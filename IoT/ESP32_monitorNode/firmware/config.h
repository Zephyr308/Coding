#ifndef CONFIG_H
#define CONFIG_H

// ---------- Device Identity ----------
#define DEVICE_ID        "motor_node_01"

// ---------- Wi-Fi ----------
#define WIFI_SSID        "YOUR_WIFI_SSID"
#define WIFI_PASSWORD    "YOUR_WIFI_PASSWORD"

// ---------- MQTT ----------
#define MQTT_BROKER      "192.168.1.100"   // Mosquitto / Cloud IP
#define MQTT_PORT        1883              // 8883 for TLS
#define MQTT_TOPIC_PUB   "factory/motor1/data"
#define MQTT_TOPIC_STAT  "factory/motor1/status"

// ---------- Timing ----------
#define SENSOR_INTERVAL_MS   2000
#define MQTT_RETRY_MS        5000

// ---------- Thresholds ----------
#define TEMP_LIMIT_C     70.0
#define CURRENT_LIMIT_A  5.0
#define VIB_LIMIT        1.2

#endif
