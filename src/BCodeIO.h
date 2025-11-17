#pragma once

/**
 * @class BCodeReader
 * @brief Interface for reading BCode command lines.
 */
class BCodeIO {
public:

    /**
     * @brief Reads a line of BCode command.
     * @return A pointer to the read line as a character array.
     */
    virtual char* readLine() = 0;

    /**
     * @brief Writes a line of BCode command.
     * @param line The line to write as a character array.
     */
    virtual void writeLine(const char* line) = 0;

};
