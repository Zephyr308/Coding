import gps
import time
import json
from geopy.geocoders import Nominatim

from config import *
from mqtt_publisher import publish_data
from local_buffer import insert_data

geolocator = Nominatim(user_agent="vehicle-tracker")

session = gps.gps(mode=gps.WATCH_ENABLE)
session.stream(gps.WATCH_ENABLE | gps.WATCH_NEWSTYLE)

last_geocode = 0
cached_address = "Unknown"

print("Vehicle Tracking Started")

while True:

    try:

        report = session.next()

        if report['class'] == 'TPV':

            latitude = getattr(report, 'lat', None)
            longitude = getattr(report, 'lon', None)
            speed = getattr(report, 'speed', 0)
            altitude = getattr(report, 'alt', 0)
            gps_time = getattr(report, 'time', '')

            if latitude and longitude:

                current_time = time.time()

                if current_time - last_geocode > GEOCODE_INTERVAL:

                    try:

                        location = geolocator.reverse(
                            f"{latitude},{longitude}",
                            timeout=10
                        )

                        cached_address = location.address
                        last_geocode = current_time

                    except:
                        pass

                payload = {
                    "device_id": DEVICE_ID,
                    "lat": latitude,
                    "lon": longitude,
                    "speed": speed,
                    "altitude": altitude,
                    "time": gps_time,
                    "address": cached_address
                }

                insert_data(payload)

                try:
                    publish_data(payload)
                    print(json.dumps(payload, indent=2))

                except Exception as e:
                    print("MQTT ERROR:", e)

        time.sleep(PUBLISH_INTERVAL)

    except KeyboardInterrupt:
        print("Stopped")
        break

    except StopIteration:

        print("GPSD Restarting...")

        time.sleep(2)

        session = gps.gps(mode=gps.WATCH_ENABLE)
        session.stream(gps.WATCH_ENABLE | gps.WATCH_NEWSTYLE)

    except Exception as e:
        print("ERROR:", e)
        time.sleep(2)
