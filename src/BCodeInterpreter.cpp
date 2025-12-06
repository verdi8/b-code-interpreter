#include "BCodeInterpreter.h"
#include "BCodeParser.h"
#include <stdlib.h> // For strtod
#include <stdio.h>  // For snprintf
#include <string.h> // For strlen


BCodeInterpreter::BCodeInterpreter(BCodeIO* io, BCodeCommandHandler* commandHandler)
    : io(io), commandHandler(commandHandler) {}

void BCodeInterpreter::process() {
    if (!(io && commandHandler)) {
        return;
    }
    
    char* commandLine = io->readLine(); // Read a command
    if (!commandLine || commandLine[0] == '\0') {
        return; // Ignore empty lines
    }

    unsigned int returnCode = doProcess(commandLine);
    if(returnCode == ReturnCodes::OK) {
        io->writeLine("OK");
    } else {
        snprintf(buffer, sizeof(buffer), "ERR %d", returnCode);
        io->writeLine(buffer);
    }

}

unsigned int BCodeInterpreter::doProcess(char* commandLine) {
    // Parse the command line
    char* ptr = commandLine;

    char commandCode = BCodeParser::readSingleChar(ptr);
    if (BCodeParser::errored()) {
        return ReturnCodes::ERROR_UNPARSABLE_COMMAND_CODE;
    }

    switch (commandCode)
    {
    case 'A': { // Action command
        int actionId = BCodeParser::readUnsignedInt(ptr);
        if (BCodeParser::errored()) {
            return ReturnCodes::ERROR_UNPARSABLE_ACTION_CODE;
        } 
        commandHandler->performAction(actionId);
        return ReturnCodes::OK;
    }

    case 'T': { // Translate command
        char* directions = BCodeParser::readCharSequence(ptr, 3); // Read up to 3 direction characters
        if (BCodeParser::errored()) {
            return ReturnCodes::ERROR_UNPARSABLE_TRANSLATION_DIRECTION;
        }
        char direction1 = directions[0];
        char direction2 = directions[1];
        char direction3 = direction2 != '\0' ? directions[2] : '\0';
        
        float units = BCodeParser::readFloat(ptr);
        if (BCodeParser::errored()) {
            return ReturnCodes::ERROR_UNPARSABLE_TRANSLATION_UNIT;
        }
        return commandHandler->performTranslationMovement(direction1, direction2, direction3, units);
    }

    case 'Z': { // nop command
        return ReturnCodes::OK;
    }

    default: {
        return ReturnCodes::ERROR_UNKNOWN_COMMAND;
    }
    }
}
