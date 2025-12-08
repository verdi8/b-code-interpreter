#include "Parser.h"
#include <stdlib.h> // For atof
#include <errno.h>  // For errno

namespace bcode
{
    unsigned int Parser::readUnsignedInt(char *&input)
    {
        ready(input);
        unsigned int value = atoi(input);
        if (value == 0 && *input != '0')
        { // Detect parsing failure only
            markErrored();
            return 0;
        }
        while (*input >= '0' && *input <= '9')
        { // Move input pointer past the number
            ++input;
        }
        return value;
    }

    float Parser::readFloat(char *&input)
    {
        ready(input);
        double value = atof(input);
        if (value == 0.0 && *input != '0')
        { // Detect parsing failure only
            markErrored();
            return 0.0f;
        }
        while ((*input >= '0' && *input <= '9') || *input == '.' || *input == 'e' || *input == 'E' || *input == '+' || *input == '-')
        {
            ++input; // Move input pointer past the number
        }
        return static_cast<float>(value);
    }

    char Parser::readSingleChar(char *&input)
    {
        ready(input);
        char value = *input;
        if (value == '\0')
        { // No character found
            markErrored();
            return '\0';
        }
        ++input;
        if (*input != ' ' && *input != '\0')
        { // There are more characters before the next whitespace
            markErrored();
            return '\0';
        }
        return value;
    }

    char *Parser::readCharSequence(char *&input, unsigned int maxLength)
    {
        ready(input);
        char *start = input;
        if (*start == '\0')
        { // No word found
            markErrored();
            return nullptr;
        }
        unsigned int length = 0;
        while (*input != ' ' && *input != '\0')
        {
            if (length == maxLength)
            { // Exceeded maximum length
                markErrored();
                return nullptr;
            }
            ++input;
            ++length;
        }

        // Null-terminate the string if not already at the end
        if (*input != '\0')
        {
            *input = '\0';
            ++input;
        }

        return start;
    }

    bool Parser::errorFlag = false;

    bool Parser::errored()
    {
        return errorFlag;
    }
    
    void Parser::skipLeadingWhitespaces(char *&input)
    {
        while (*input == ' ')
        {
            ++input;
        }
    }

    void Parser::clearErrorFlag()
    {
        errorFlag = false;
    }
    void Parser::markErrored()
    {
        errorFlag = true;
    }
    void Parser::ready(char *&input)
    {
        skipLeadingWhitespaces(*&input);
        clearErrorFlag();
    }

}
