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
     * Reads a single character from the input string. An error is flagged if no character is found or if there are more than one character before the next whitespace.
     * @param input A reference to the input string pointer, which will be advanced past the read character.
     * @return The read character.
     */
    static char readSingleChar(char*& input);

    /**
     * Read a word (string without spaces) from the input string.
     * If no word is found, an error is flagged.
     * If the word exceeds maxLength, an error is flagged.
     * @param input A reference to the input string pointer, which will be advanced past the read word.
     * @param maxLength The maximum length of the word to read (including null terminator). Default is 16.
     * @return A pointer to the start of the read word.
     */
    static char* readCharSequence(char*& input, unsigned int maxLength);

    /**
     * @brief Checks if a parsing error has occurred during the last read operation.
     * @return true if a parsing error occurred, false otherwise.
     */
    static bool errored();

private:
    static bool errorFlag; ///< Indicates if a parsing error has occurred.
    static void clearErrorFlag(); ///< Resets the error flag to false.
    static void setErrorFlag(); ///< Sets the error flag to true.
};
