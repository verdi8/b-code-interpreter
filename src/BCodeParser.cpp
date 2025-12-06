#include "BCodeParser.h"
#include <stdlib.h> // For atof
#include <errno.h>  // For errno

void BCodeParser::skipWhitespaces(char*& input) {
    while (*input == ' ') {
        ++input;
    }
}

unsigned int BCodeParser::readUnsignedInt(char*& input) {
    clearErrorFlag();
    skipWhitespaces(input);
    unsigned int value = atoi(input);
    if (value == 0 && *input != '0') { // Detect parsing failure only
        setErrorFlag();
        return 0;
    }
    while (*input >= '0' && *input <= '9') { // Move input pointer past the number
        ++input;
    }
    return value;
}

float BCodeParser::readFloat(char*& input) {
    clearErrorFlag();
    skipWhitespaces(input);
    double value = atof(input);
    if (value == 0.0 && *input != '0') { // Detect parsing failure only
        setErrorFlag();
        return 0.0f;
    }
    while ((*input >= '0' && *input <= '9') || *input == '.' || *input == 'e' || *input == 'E' || *input == '+' || *input == '-') {
        ++input; // Move input pointer past the number
    }
    return static_cast<float>(value);
}

char BCodeParser::readSingleChar(char*& input) {
    clearErrorFlag();
    skipWhitespaces(input);
    char value = *input;
    if (value == '\0') { // No character found
        setErrorFlag();
        return '\0';
    }
    ++input;
    if( *input != ' ' && *input != '\0') { // There are more characters before the next whitespace
        setErrorFlag();
        return '\0';
    }
    return value;
}


char* BCodeParser::readCharSequence(char*& input, unsigned int maxLength) {
    clearErrorFlag();
    skipWhitespaces(input);
    char* start = input;
    if (*start == '\0') { // No word found
        setErrorFlag();
        return nullptr;
    }
    unsigned int length = 0;
    while (*input != ' ' && *input != '\0') {
         if (length == maxLength) { // Exceeded maximum length
            setErrorFlag();
            return nullptr;
        }
        ++input;
        ++length;
    }

    // Null-terminate the string if not already at the end
    if(*input != '\0') {
        *input = '\0';
        ++input;
    }


    return start;
}

bool BCodeParser::errorFlag = false;
void BCodeParser::clearErrorFlag() {
    errorFlag = false;
}
void BCodeParser::setErrorFlag() {
    errorFlag = true;
}
bool BCodeParser::errored() {
    return errorFlag;
}