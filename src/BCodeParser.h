#pragma once

/**
 * @class BCodeParser
 * @brief Utility class for parsing b-code command arguments.
 */
class BCodeParser {
public:
    /**
     * Skips over any whitespace characters in the input string.
     * @param input A reference to the input string pointer, which will be advanced past the whitespace.
     */
    static void skipWhitespaces(char*& input);

    /**
     * Parses a floating-point number from the input string.
     * @param input A reference to the input string pointer, which will be advanced past the parsed number.
     * @return The parsed floating-point number.
     */
    static float readFloat(char*& input);

    /**
     * Parses an unsigned integer from the input string.
     * @param input A reference to the input string pointer, which will be advanced past the parsed number.
     * @return The parsed unsigned integer.
     */
    static unsigned int readUnsignedInt(char*& input);

    /**
     * Reads a single character from the input string.
     * @param input A reference to the input string pointer, which will be advanced past the read character.
     * @return The read character.
     */
    static char readChar(char*& input);

    /**
     * Read a word (string without spaces) from the input string.
     */
    static char* readWord(char*& input);

};
