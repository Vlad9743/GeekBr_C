import time
import adafruit_dht
import board
import random

from paho.mqtt import client as mqtt_client

broker = '192.168.83.145'
port = 1883
topic = "Temp_C"
client_id = f'python-mqtt-{random.randint(0, 1000)}'
username = 'IoT'
password = 'student'

#######################

client  = mqtt_client.Client(mqtt_client.CallbackAPIVersion.VERSION2, client_id)
client.username_pw_set(username, password)
client.connect(broker, port)

#########################

dht_device = adafruit_dht.DHT11(board.D14)

while True:

    msg = dht_device.temperature

    print("Temp:{:.1f} C".format(msg))

    client.publish(topic, msg)

    time.sleep(5.0)
