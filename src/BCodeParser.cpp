#include "BCodeParser.h"
#include <stdlib.h> // For atof
#include <errno.h>  // For errno

void BCodeParser::skipWhitespaces(char*& input) {
    while (*input == ' ') {
        ++input;
    }
}

unsigned int BCodeParser::readUnsignedInt(char*& input) {
    skipWhitespaces(input);
    int value = atoi(input);
    if (value == 0 && *input != '0') { // Detect parsing failure only
        input = nullptr;
        return 0;
    }
    while (*input >= '0' && *input <= '9') { // Move input pointer past the number
        ++input;
    }
    return static_cast<unsigned int>(value);
}

float BCodeParser::readFloat(char*& input) {
    skipWhitespaces(input);
    double value = atof(input);
    if (value == 0.0 && *input != '0') { // Detect parsing failure only
        input = nullptr;
        return 0.0f;
    }
    while ((*input >= '0' && *input <= '9') || *input == '.' || *input == 'e' || *input == 'E' || *input == '+' || *input == '-') {
        ++input; // Move input pointer past the number
    }
    return static_cast<float>(value);
}

char BCodeParser::readChar(char*& input) {
    skipWhitespaces(input);
    char value = *input;
    if (value != '\0') {
        ++input;
    }
    return value;
}