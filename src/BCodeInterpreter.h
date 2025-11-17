#pragma once

#include "BCodeTypes.h"
#include "BCodeIO.h"
#include "BCodeCommandHandler.h"

/**
 * @class BCodeInterpreter
 * @brief Interprets and processes commands based on the b-code protocol.
 * 
 * The b-code protocol defines a set of commands, each consisting of a command code
 * followed by optional arguments. This class reads a line of text from the provided
 * BCodeIO instance, parses it according to the b-code protocol, and delegates the
 * handling of the command to a BCodeCommandHandler instance.
 */
class BCodeInterpreter {
public:
    /**
     * @brief Constructs a BCodeInterpreter with the specified IO and command handler.
     * @param reader Pointer to the BCodeIO instance for reading commands.
     * @param commandHandler Pointer to the BCodeCommandHandler instance for handling commands.
     */
    BCodeInterpreter(BCodeIO* reader, BCodeCommandHandler* commandHandler);

    /**
     * @brief Reads and processes a single command line based on the b-code protocol.
     * 
     * This method reads a line of text from the BCodeIO instance, parses it into
     * a command code and arguments as defined by the b-code protocol, and passes
     * them to the BCodeCommandHandler.
     */
    void process();

private:
    char buffer[16]; ///< A small buffer for temporary storage during parsing.
    BCodeIO* io; ///< Pointer to the BCodeIO instance for reading commands.
    BCodeCommandHandler* commandHandler; ///< Pointer to the command handler instance.

    /**
     * @brief Processes a command line and delegates to the command handler.
     * @param commandLine The command line to process.
     * @return The return code indicating the result of processing.
     */
    ReturnCode doProcess(char* commandLine);

};

