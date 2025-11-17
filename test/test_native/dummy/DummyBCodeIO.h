#pragma once

#include "BCodeIO.h"

/**
 * @class BCodeIOMock
 * @brief Mock implementation of the BCodeIO interface for testing purposes.
 */
class DummyBCodeIO : public BCodeIO {
public:
    /**
     * @brief Reads a line of BCode command.
     * @return A pointer to the read line as a character array.
     */
    char* readLine() override;

    /**
     * @brief Writes a line of BCode command.
     * @param line The line to write as a character array.
     */
    void writeLine(const char* line) override;

    /**
     * @brief Injects a line to be read by the mock.
     * @param line The line to inject as a character array.
     */
    void injectInputLine(const char* line);

    /**
     * @brief Retrieves the last written line.
     * @return The last written line as a character array.
     */
    const char* getOutputLine() const;

private:
    char inputBuffer[256]; ///< Buffer for input lines
    char outputBuffer[256]; ///< Buffer for output lines
};
