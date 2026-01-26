#include <Arduino.h>
#include <WiFi.h>

#include "config.h"
#include "sensors.h"
#include "mqtt_client.h"

unsigned long lastSensorRead = 0;

void connectWiFi() {
    WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
    }
}

void setup() {
    Serial.begin(115200);

    connectWiFi();
    sensorsInit();
    mqttInit();

    Serial.println("Industrial IoT Node Started");
}

void loop() {
    mqttLoop();

    unsigned long now = millis();
    if (now - lastSensorRead >= SENSOR_INTERVAL_MS) {
        SensorData data = sensorsRead();

        mqttPublish(data);

        Serial.printf(
            "Temp: %.2f C | Curr: %.2f A | Vib: %.2f | Fault: %d\n",
            data.temperature,
            data.current,
            data.vibration,
            data.fault
        );

        lastSensorRead = now;
    }
}
