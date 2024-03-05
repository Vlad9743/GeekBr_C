#include <stdio.h>
#include <unistd.h>
#include <getopt.h>
#include <stdlib.h>

#include "temp_functions.h"



int main(int argc, char *argv[])
{
    int key=0;
    char *filename;
    int month_for_analisys;
    int need_help = 1;

    opterr = 0;

    while ( (key = getopt(argc,argv,"hf:m:")) != -1)
    {
        switch(key)
        {
            case 'h':
            {
                need_help = 1;
                break;
            }
            case 'f':
            {
                need_help = 0;
                filename = optarg;
                break;
            }
            case 'm':
            {
                month_for_analisys = atoi(optarg);
                if (month_for_analisys < 1 || month_for_analisys > 12)
                {
                    printf("Wrong month number. Input 1 ... 12.\n");
                    need_help = 1;
                }
                else
                {
                    need_help = 0;
                }
                break;
            }
            case '?':
            {
                need_help = 1;
                break;
            }
        }
    }

    if (need_help == 1)
    {
        printf("==========================================================================================\n");
        printf("This program analise temperature sensor data, presented in a .csv file.\n\n");
        printf("Required CSV-file records format: yyyy;mm;dd;hh;mm;tt\n");
        printf("Program flags:\n\n");
        printf("-h - show help.\n\n");
        printf("-f <filename.csv> - declare input .csv file.\n\n");
        printf("   The max, min and avg temperatures for all month and entire year will be calculated.\n\n");
        printf("-m <1...12> - max, min and avg temperatures for declared month will be calculated.\n");
        printf("==========================================================================================\n");
    }
    else
    {
        FILE *input_file;
        input_file = fopen(filename, "r");

        if (input_file != NULL)
        {
            int number_of_records = count_strings_number(input_file);
            struct data_record_t data_array[number_of_records];
            int actual_records = parse_file(input_file, data_array, number_of_records);

            if (month_for_analisys != 0)
            {
                month_temp_parameters(data_array, actual_records, month_for_analisys);
            }
            else
            {
                full_temp_parameters(data_array, actual_records);
            }
        }
        else
        {
            printf("File not found.\n");
        }
    }

    return 0;
}