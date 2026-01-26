#include "mqtt_client.h"
#include "config.h"
#include <WiFi.h>
#include <PubSubClient.h>

WiFiClient espClient;
PubSubClient mqttClient(espClient);

static unsigned long lastReconnectAttempt = 0;

void mqttReconnect() {
    if (mqttClient.connect(DEVICE_ID)) {
        mqttClient.publish(MQTT_TOPIC_STAT, "ONLINE", true);
    }
}

void mqttInit() {
    mqttClient.setServer(MQTT_BROKER, MQTT_PORT);
}

void mqttLoop() {
    if (!mqttClient.connected()) {
        unsigned long now = millis();
        if (now - lastReconnectAttempt > MQTT_RETRY_MS) {
            lastReconnectAttempt = now;
            mqttReconnect();
        }
    } else {
        mqttClient.loop();
    }
}

bool mqttIsConnected() {
    return mqttClient.connected();
}

void mqttPublish(const SensorData& data) {
    if (!mqttClient.connected()) return;

    char payload[256];
    snprintf(payload, sizeof(payload),
        "{"
        "\"device_id\":\"%s\","
        "\"temperature\":%.2f,"
        "\"current\":%.2f,"
        "\"vibration\":%.2f,"
        "\"fault\":%s"
        "}",
        DEVICE_ID,
        data.temperature,
        data.current,
        data.vibration,
        data.fault ? "true" : "false"
    );

    mqttClient.publish(MQTT_TOPIC_PUB, payload);
}
