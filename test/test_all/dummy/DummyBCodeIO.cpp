#include "DummyBCodeIO.h"
#include <string.h>

char* DummyBCodeIO::readLine() {
    return inputBuffer;
}

void DummyBCodeIO::writeLine(const char* line) {
    strncpy(outputBuffer, line, sizeof(outputBuffer) - 1);
    outputBuffer[sizeof(outputBuffer) - 1] = '\0'; // Ensure null-termination
}

void DummyBCodeIO::injectInputLine(const char* line) {
    strncpy(inputBuffer, line, sizeof(inputBuffer) - 1);
    inputBuffer[sizeof(inputBuffer) - 1] = '\0'; // Ensure null-termination
}

const char* DummyBCodeIO::getOutputLine() const {
    return outputBuffer;
}

