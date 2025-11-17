#include "BCodeParser.h"
#include <stdlib.h> // For strtoul, strtof

void BCodeParser::skipWhitespaces(char*& input) {
    while (*input == ' ') {
        ++input;
    }
}

unsigned int BCodeParser::readUnsignedInt(char*& input) {
    skipWhitespaces(input);
    char* endPtr;
    unsigned long value = strtoul(input, &endPtr, 10);
    if (endPtr == input) {
        input = nullptr; // Indicate parsing failure
        return 0;
    }
    input = endPtr;
    return static_cast<unsigned int>(value);
}

float BCodeParser::readFloat(char*& input) {
    skipWhitespaces(input);
    char* endPtr;
    float value = strtof(input, &endPtr);
    if (endPtr == input) {
        input = nullptr; // Indicate parsing failure
        return 0.0f;
    }
    input = endPtr;
    return value;
}

char BCodeParser::readChar(char*& input) {
    skipWhitespaces(input);
    char value = *input;
    if (value != '\0') {
        ++input;
    }
    return value;
}