#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <limits.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>  // For sleep()

/*
=========================================================
📦 Embedded Sensor Logger - Microcontroller Simulation
=========================================================
🔧 Features:
1. Simulates sensor temperature readings using `rand()`
2. Logs data into a circular buffer of fixed size
3. Uses bitfields to simulate a control register
   - LOG_ENABLE: controls if logging is active
   - ERROR: flags any temperature outside allowed range
4. Applies embedded concepts:
   - `volatile`: for simulated hardware register
   - `const`: for ROM-like thresholds
   - `static`: to retain state across function calls
5. Outputs system state and readings like an MCU logger
*/

#define BUFFER_SIZE 10                 // Circular buffer size
const int TEMP_THRESHOLD_HIGH = 40;   // Constant stored in Flash/ROM
const int TEMP_THRESHOLD_LOW  = 0;

// Simulated hardware register with bitfields
typedef struct {
    uint8_t ERROR      : 1;
    uint8_t LOG_ENABLE : 1;
    uint8_t RESERVED   : 6;
} ControlReg_t;

// 🛑 Volatile because it may be changed by ISR or other hardware
volatile ControlReg_t sensorControlReg = {0};  

// 🔄 Circular buffer & state variables
int circularBuffer[BUFFER_SIZE];
int head = 0;  // Next insert index

// Store current min/max for the buffer
int bufferMin = INT_MAX;
int bufferMax = INT_MIN;

// --------------------------------------------
// 📌 Function: logSensorValue
// Stores a temperature reading in the circular buffer
// Also updates min/max values
// --------------------------------------------
void logSensorValue(int value) {
    if (sensorControlReg.LOG_ENABLE) {
        circularBuffer[head] = value;

        // Update min/max
        if (value < bufferMin) bufferMin = value;
        if (value > bufferMax) bufferMax = value;

        head = (head + 1) % BUFFER_SIZE;  // Circular logic
    }
}

// --------------------------------------------
// 📌 Function: readSensorData
// Simulates reading from a temperature sensor
// Checks threshold, updates control register
// --------------------------------------------
void readSensorData() {
    static int sampleCount = 0;  // Static retains value across calls

    int tempData = rand() % (TEMP_THRESHOLD_HIGH + 10);  // 0 to 49
    printf("[Sensor] Reading #%d = %d°C\n", ++sampleCount, tempData);

    // Enable logging if not already enabled
    if (!sensorControlReg.LOG_ENABLE) {
        sensorControlReg.LOG_ENABLE = 1;
        printf("[Control Register] LOG enabled.\n");
    }

    // Check for error condition
    if (tempData < TEMP_THRESHOLD_LOW || tempData > TEMP_THRESHOLD_HIGH) {
        sensorControlReg.ERROR = 1;
        printf("⚠️  ERROR: Temperature out of range!\n");
    } else {
        sensorControlReg.ERROR = 0;
        logSensorValue(tempData);
    }
}

// --------------------------------------------
// 📌 Function: toggleLogging
// Simulates a control register toggle (like button press)
// --------------------------------------------
void toggleLogging() {
    sensorControlReg.LOG_ENABLE = !sensorControlReg.LOG_ENABLE;
    printf("[Control Register] LOG toggled. New state: %d\n", sensorControlReg.LOG_ENABLE);
}

// --------------------------------------------
// 📌 Main Application
// --------------------------------------------
int main() {
    srand(time(NULL));  // Seed RNG

    printf("=== Embedded Sensor Logger (Simulation) ===\n");

    for (int i = 0; i < 10; i++) {
        readSensorData();  // Simulate a sensor interrupt or timer-triggered reading
        sleep(1);          // Delay between readings (as in RTOS tick or timer)
    }

    // Print register status
    printf("\n[Control Register] LOG: %d, ERROR: %d, BUFFER COUNT: %d\n",
           sensorControlReg.LOG_ENABLE, sensorControlReg.ERROR, head);

    // Print most recent value
    int latest = circularBuffer[(head - 1 + BUFFER_SIZE) % BUFFER_SIZE];

    // Final buffer and temperature log
    printf("[Sensor Log] Latest = %d°C | Min = %d°C | Max = %d°C\n",
           latest, bufferMin, bufferMax);

    printf("[Buffer Contents]: ");
    for (int i = 0; i < BUFFER_SIZE; i++) {
        printf("%d ", circularBuffer[i]);
    }
    printf("\n");

    return 0;
}
