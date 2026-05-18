import json
import paho.mqtt.client as mqtt

from database import SessionLocal
from models import VehicleData

BROKER = "broker.hivemq.com"
TOPIC = "vehicle/livegps"

db = SessionLocal()

def on_message(client, userdata, msg):

    data = json.loads(msg.payload.decode())

    record = VehicleData(
        device_id=data['device_id'],
        latitude=data['lat'],
        longitude=data['lon'],
        speed=data['speed'],
        altitude=data['altitude'],
        gps_time=data['time'],
        address=data['address']
    )

    db.add(record)
    db.commit()

client = mqtt.Client()

client.on_message = on_message

client.connect(BROKER, 1883)

client.subscribe(TOPIC)

client.loop_forever()
