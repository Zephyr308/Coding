/*
 ============================================================================
 🔧 Embedded Control Register Simulator (Reference & Practice Project)
 ============================================================================
 Author: YOU
 Purpose:
 - Simulates a basic control register like you'd see in embedded systems.
 - Accepts text-based commands (like POWER=ON,MODE=3) from the user.
 - Parses the string and sets bitfields in a register structure.
 - Displays the state of the register in both decimal and binary.
 - Maintains an event log (using a circular buffer).
 - Acts as a reference for: bitfields, enums, string parsing, CLI simulation.

 ============================================================================
 🧠 What You Will Learn:
 - Bitfields in structs (used in embedded hardware register simulation)
 - String parsing and `sscanf`, `strtok`, `strcasecmp`
 - Enum + dispatch pattern for scalable command handling
 - CLI loop in C
 - Circular buffer implementation for event logging

 ============================================================================
*/

#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

//
// ----------------------- Structs & Enums -----------------------
//

// Simulated 8-bit hardware control register using bitfields
typedef struct {
    unsigned char RESERVED : 3;  // bits 0-2: Reserved
    unsigned char MODE     : 3;  // bits 3-5: Operating Mode (0-7)
    unsigned char ALARM    : 1;  // bit 6: Alarm ON/OFF
    unsigned char POWER    : 1;  // bit 7: Power ON/OFF
} ControlRegister_t;

// Enum to identify which command is being parsed
typedef enum {
    CMD_POWER,
    CMD_ALARM,
    CMD_MODE,
    CMD_RESERVED,
    CMD_INVALID
} CommandType;

// Log entry structure (used in circular buffer)
typedef struct {
    char message[64]; // Log message string
} LogEntry;

//
// ----------------------- Event Buffer (Circular) -----------------------
//

#define EVENT_BUFFER_SIZE 10
LogEntry eventBuffer[EVENT_BUFFER_SIZE];
int eventHead = 0;

// Adds a new message to the circular event buffer
void logEvent(const char *msg) {
    snprintf(eventBuffer[eventHead].message, sizeof(eventBuffer[eventHead].message), "%s", msg);
    eventHead = (eventHead + 1) % EVENT_BUFFER_SIZE;
}

// Displays all event messages stored in the buffer
void printEventLog() {
    printf("\n🔍 Event Log:\n");
    for (int i = 0; i < EVENT_BUFFER_SIZE; i++) {
        if (eventBuffer[i].message[0] != '\0') {
            printf("  [%d] %s\n", i, eventBuffer[i].message);
        }
    }
    printf("\n");
}

//
// ----------------------- Register Utilities -----------------------
//

// Sets all bits in the register to zero
void resetRegister(ControlRegister_t *reg) {
    memset(reg, 0, sizeof(ControlRegister_t));
    logEvent("Register reset to zero.");
}

// Encodes the bitfield struct into a full 8-bit value
uint8_t encodeRegister(const ControlRegister_t *reg) {
    return (reg->POWER << 7) | (reg->ALARM << 6) | (reg->MODE << 3) | reg->RESERVED;
}

// Prints a byte in binary format (for 8 bits)
void printBinary(uint8_t val) {
    for (int i = 7; i >= 0; i--) {
        printf("%d", (val >> i) & 1);
    }
}

//
// ----------------------- Command Parsing -----------------------
//

// Matches string command to corresponding enum type
CommandType getCommandType(const char *key) {
    if (strcasecmp(key, "POWER") == 0) return CMD_POWER;
    if (strcasecmp(key, "ALARM") == 0) return CMD_ALARM;
    if (strcasecmp(key, "MODE") == 0) return CMD_MODE;
    if (strcasecmp(key, "RESERVED") == 0) return CMD_RESERVED;
    return CMD_INVALID;
}

// Applies a command to update the control register
void applyCommand(ControlRegister_t *reg, CommandType cmd, const char *value) {
    char log[64];

    switch (cmd) {
        case CMD_POWER:
            reg->POWER = (strcasecmp(value, "ON") == 0) ? 1 : 0;
            snprintf(log, sizeof(log), "POWER set to %s", reg->POWER ? "ON" : "OFF");
            break;

        case CMD_ALARM:
            reg->ALARM = (strcasecmp(value, "ON") == 0) ? 1 : 0;
            snprintf(log, sizeof(log), "ALARM set to %s", reg->ALARM ? "ON" : "OFF");
            break;

        case CMD_MODE: {
            int mode = atoi(value);
            if (mode >= 0 && mode <= 7) {
                reg->MODE = mode;
                snprintf(log, sizeof(log), "MODE set to %d", reg->MODE);
            } else {
                snprintf(log, sizeof(log), "Invalid MODE value: %d", mode);
            }
            break;
        }

        case CMD_RESERVED: {
            int rsv = atoi(value);
            if (rsv >= 0 && rsv <= 7) {
                reg->RESERVED = rsv;
                snprintf(log, sizeof(log), "RESERVED bits set to %d", reg->RESERVED);
            } else {
                snprintf(log, sizeof(log), "Invalid RESERVED value: %d", rsv);
            }
            break;
        }

        default:
            snprintf(log, sizeof(log), "Unknown command");
            break;
    }

    logEvent(log);  // Save command to the event log
}

//
// ----------------------- Main Parser -----------------------
//

// Takes an input string like "POWER=ON,MODE=3", splits and applies each
void parseCommand(const char *input, ControlRegister_t *reg) {
    if (!input || !reg) return;

    if (strcasecmp(input, "RESET") == 0) {
        resetRegister(reg);
        return;
    }

    char *inputCopy = strdup(input);              // Copy input (to safely tokenize it)
    char *token = strtok(inputCopy, ",");         // Start splitting by comma

    while (token) {
        char key[20], value[20];

        // Extract KEY=VALUE using sscanf
        if (sscanf(token, "%19[^=]=%19s", key, value) == 2) {
            CommandType cmd = getCommandType(key); // Determine which field to modify
            applyCommand(reg, cmd, value);         // Apply command to register
        } else {
            char warn[64];
            snprintf(warn, sizeof(warn), "Invalid format: %s", token);
            logEvent(warn);
        }

        token = strtok(NULL, ",");  // Next command
    }

    free(inputCopy);
}

//
// ----------------------- Display Register State -----------------------
//

void displayRegister(const ControlRegister_t *reg) {
    uint8_t encoded = encodeRegister(reg);

    printf("\n🧾 Current Register State:\n");
    printf("  POWER    = %d\n", reg->POWER);
    printf("  ALARM    = %d\n", reg->ALARM);
    printf("  MODE     = %d\n", reg->MODE);
    printf("  RESERVED = %d\n", reg->RESERVED);
    printf("  Binary   = ");
    printBinary(encoded);
    printf(" (0x%02X)\n\n", encoded);
}

//
// ----------------------- Main CLI Loop -----------------------
//

int main() {
    ControlRegister_t reg = {0}; // Register initialized to 0
    char input[128];

    printf("🔧 Embedded Control Register CLI\n");
    printf("--------------------------------------------------------\n");
    printf("Type commands like:\n");
    printf("  POWER=ON,MODE=3,ALARM=OFF,RESERVED=4\n");
    printf("Special commands:\n");
    printf("  RESET - clears the register\n");
    printf("  LOG   - shows last 10 register changes\n");
    printf("  EXIT  - quits the program\n");
    printf("--------------------------------------------------------\n\n");

    while (1) {
        printf(">> ");
        if (!fgets(input, sizeof(input), stdin)) break;

        // Remove newline
        input[strcspn(input, "\n")] = '\0';

        if (strcasecmp(input, "EXIT") == 0) {
            printf("Exiting...\n");
            break;
        } else if (strcasecmp(input, "LOG") == 0) {
            printEventLog();
        } else {
            parseCommand(input, &reg);
            displayRegister(&reg);
        }
    }

    return 0;
}
