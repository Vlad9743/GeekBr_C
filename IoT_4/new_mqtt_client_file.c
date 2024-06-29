#include <stdio.h>
#include <stdint.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include <getopt.h>

#include "MQTTClient.h"

#define CLIENTID    "ExampleClientPub"
#define TOPIC       "Temp_C"
#define QOS         1
#define TIMEOUT     10000L
double DELAY = 5;

struct sensor {
    uint16_t year;
    uint8_t month;
    uint16_t day;
    uint8_t hour;
    uint8_t minute;
    int8_t t;
};

void AddRecord (struct sensor* info, int number, 
uint16_t year,uint8_t month,uint16_t day,uint8_t hour,uint8_t minute,int8_t t)
{
    info[number].year = year;
    info[number].month = month;
    info[number].day = day;
    info[number].hour = hour;
    info[number].minute = minute;
    info[number].t = t;
}

int main(int argc, char *argv[])
{
	//flags
	int key = 0;
	char *ip = "192.168.0.223";
	char *login = "IoT";
	char *pass = "student";
	char *filename = "temperature_small.csv";

	opterr = 0;

	while ((key = getopt(argc, argv, "i:l:p:f:")) != -1)
	{
		switch(key)
		{
			case 'i':
			{
				ip = optarg;
				break;
			}
			case 'l':
			{
				login = optarg;
				break;
			}
			case 'p':
			{
				pass = optarg;
				break;
			}
			case 'f':
			{
				filename = optarg;
				break;
			}
		}
	}
	//flags end

	FILE *file;
	file = fopen(filename ,"r");

    MQTTClient client;
    MQTTClient_connectOptions conn_opts = MQTTClient_connectOptions_initializer;
    MQTTClient_message pubmsg = MQTTClient_message_initializer;
    MQTTClient_deliveryToken token;
    int rc;

    MQTTClient_create(&client, ip , CLIENTID,
        MQTTCLIENT_PERSISTENCE_NONE, NULL);
    conn_opts.keepAliveInterval = 20;
    conn_opts.cleansession = 1;
    conn_opts.username = login;
    conn_opts.password = pass;

    if ((rc = MQTTClient_connect(client, &conn_opts)) != MQTTCLIENT_SUCCESS)
    {
        printf("Failed to connect, return code %d\n", rc);
        exit(-1);
    }

    struct sensor*info = malloc (365*24*60*sizeof(struct sensor));

        int Y,M,D,H,Min,T;
        int r;
        int count=0;

        for (;(r=fscanf(file,"%d;%d;%d;%d;%d;%d",&Y,&M,&D,&H,&Min,&T))>0;count++)
        {
            if (r<6)
            {
                char s[20], c;
                r = fscanf (file, "%[^\n]%c",s,&c);
                printf("Wrong format in line %s\n",s);
            }
            else
            {
                printf("%d %d %d %d %d %d\n",Y,M,D,H,Min,T);
                AddRecord(info,count,Y,M,D,H,Min,T);
            }
		}
        fclose(file);
        int i = 0;

    while(1)
    {
        clock_t begin = clock();

        char str[255];
        sprintf(str,"%d",info[i++].t);
        printf("%s,%d\n",str,i);

        if(i>=count)
            i=0;

        pubmsg.payload = str;
        pubmsg.payloadlen = strlen(str);
        pubmsg.qos = QOS;
        pubmsg.retained = 0;
        MQTTClient_publishMessage(client, TOPIC, &pubmsg, &token);
        rc = MQTTClient_waitForCompletion(client, token, TIMEOUT);

        while ((double)(clock() - begin)/CLOCKS_PER_SEC<DELAY)
        {}
    }
    MQTTClient_disconnect(client, 10000);
    MQTTClient_destroy(&client);
    return rc;
}