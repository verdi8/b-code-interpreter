#include "BCodeInterpreter.h"
#include "BCodeParser.h"
#include <stdlib.h> // For strtod
#include <stdio.h>  // For snprintf


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

    char commandCode = BCodeParser::readChar(ptr);

    switch (commandCode)
    {
    case 'A': { // Action command
        int actionId = BCodeParser::readUnsignedInt(ptr);
        if (ptr == nullptr) {
            return ReturnCodes::ERROR_UNPARSABLE_ACTION_CODE;
        } 
        commandHandler->performAction(actionId);
        return ReturnCodes::OK;
    }

    case 'T': { // Translate command
        char direction = BCodeParser::readChar(ptr);
        float units = BCodeParser::readFloat(ptr);
        if (ptr == nullptr) {
            return ReturnCodes::ERROR_UNPARSABLE_TRANSLATE_UNITS;
        }
        return commandHandler->performTranslationMovement(direction, units);
    }

    case 'Z': { // nop command
        return ReturnCodes::OK;
    }

    default: {
        return ReturnCodes::ERROR_UNKNOWN_COMMAND;
    }
    }
}
