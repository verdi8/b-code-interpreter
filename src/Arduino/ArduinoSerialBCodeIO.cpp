#include "ArduinoSerialBCodeIO.h"

#include <Arduino.h>

// Buffer size for reading serial input
constexpr size_t BUFFER_SIZE = 64;

char* ArduinoSerialBCodeIO::readLine() {
    static char buffer[BUFFER_SIZE];
    size_t index = 0;

    while (Serial.available() > 0) {
        char c = Serial.read();
        if (c == '\n' || index >= BUFFER_SIZE - 1) {
            buffer[index] = '\0';
            return buffer;
        }
        buffer[index++] = c;
    }
    return nullptr; // Return nullptr if no complete line is available
}

void ArduinoSerialBCodeIO::writeLine(const char* line) {
    Serial.println(line);
}
