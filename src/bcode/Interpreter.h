#pragma once

#include "Types.h"
#include "CommandHandler.h"

namespace bcode
{

    /**
     * @class Interpreter
     * @brief Interprets and processes commands based on the b-code protocol.
     *
    * The b-code protocol defines a set of commands, each consisting of a command code
    * followed by optional arguments. This class parses a command line according to
    * the b-code protocol and delegates the handling of the command to a CommandHandler
    * instance.
     */
    class Interpreter
    {
    public:
        /**
         * @brief Constructs a Interpreter with the specified command handler.
         * @param commandHandler Pointer to the CommandHandler instance for handling commands.
         */
        Interpreter(CommandHandler *commandHandler);

        /**
         * @brief Processes a single command line based on the b-code protocol.
         *
         * This method parses a line of text into a command code and arguments as
         * defined by the b-code protocol, and passes them to the CommandHandler.
         */
        ReturnCode process(char *commandLine);

    private:
        CommandHandler *commandHandler; ///< Pointer to the command handler instance.
    };

}
