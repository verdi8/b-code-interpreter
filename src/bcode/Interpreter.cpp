#include "Interpreter.h"
#include "Parser.h"
#include <stdlib.h> // For strtod
#include <stdio.h>  // For snprintf
#include <string.h> // For strlen

namespace bcode
{

    Interpreter::Interpreter(CommandHandler *commandHandler)
        : commandHandler(commandHandler) {}

    ReturnCode Interpreter::process(char *commandLine)
    {
        if (!(commandLine && commandHandler))
        {
            return ReturnCodes::ERROR_UNPARSABLE_COMMAND_CODE;
        }

        if (commandLine[0] == '\0')
        {
            return ReturnCodes::ERROR_UNPARSABLE_COMMAND_CODE;
        }

        char *ptr = commandLine;

        char commandCode = Parser::readSingleChar(ptr);
        if (Parser::errored())
        {
            return ReturnCodes::ERROR_UNPARSABLE_COMMAND_CODE;
        }

        switch (commandCode)
        {
        case 'A':
        { // Action command
            int actionId = Parser::readUnsignedInt(ptr);
            if (Parser::errored())
            {
                return ReturnCodes::ERROR_UNPARSABLE_ACTION_CODE;
            }
            return commandHandler->performAction(actionId);
        }

        case 'T':
        {                                                             // Translate command
            char *directions = Parser::readCharSequence(ptr, 3); // Read up to 3 direction characters
            if (Parser::errored())
            {
                return ReturnCodes::ERROR_UNPARSABLE_TRANSLATION_DIRECTION;
            }
            char direction1 = directions[0];
            char direction2 = directions[1];
            char direction3 = direction2 != '\0' ? directions[2] : '\0';

            float units = Parser::readFloat(ptr);
            if (Parser::errored())
            {
                return ReturnCodes::ERROR_UNPARSABLE_TRANSLATION_UNIT;
            }
            return commandHandler->performTranslationMovement(direction1, direction2, direction3, units);
        }

        case 'Z':
        { // nop command
            return commandHandler->nop();
        }

        default:
        {
            return ReturnCodes::ERROR_UNKNOWN_COMMAND;
        }
        }
    }

}