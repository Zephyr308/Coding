import json
import paho.mqtt.publish as publish
from config import MQTT_BROKER, MQTT_PORT, MQTT_TOPIC


def publish_data(payload):

    publish.single(
        MQTT_TOPIC,
        json.dumps(payload),
        hostname=MQTT_BROKER,
        port=MQTT_PORT
    )
