#pragma once

#include "Types.h"
#include "Io.h"
#include "CommandHandler.h"

namespace bcode
{

    /**
     * @class Interpreter
     * @brief Interprets and processes commands based on the b-code protocol.
     *
     * The b-code protocol defines a set of commands, each consisting of a command code
     * followed by optional arguments. This class reads a line of text from the provided
     * Io instance, parses it according to the b-code protocol, and delegates the
     * handling of the command to a CommandHandler instance.
     */
    class Interpreter
    {
    public:
        /**
         * @brief Constructs a Interpreter with the specified IO and command handler.
         * @param reader Pointer to the Io instance for reading commands.
         * @param commandHandler Pointer to the CommandHandler instance for handling commands.
         */
        Interpreter(Io *reader, CommandHandler *commandHandler);

        /**
         * @brief Reads and processes a single command line based on the b-code protocol.
         *
         * This method reads a line of text from the Io instance, parses it into
         * a command code and arguments as defined by the b-code protocol, and passes
         * them to the CommandHandler.
         */
        void process();

    private:
        char buffer[16];                     ///< A small buffer for temporary storage during parsing.
        Io *io;                         ///< Pointer to the Io instance for reading commands.
        CommandHandler *commandHandler; ///< Pointer to the command handler instance.

        /**
         * @brief Processes a command line and delegates to the command handler.
         * @param commandLine The command line to process.
         * @return The return code indicating the result of processing.
         */
        ReturnCode doProcess(char *commandLine);
    };

}
