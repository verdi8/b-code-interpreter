#pragma once

#include "BCodeConstants.h"

/**
 * @class BCodeCommandHandler
 * @brief Interface for handling BCode commands. It is where the actions for each command are defined.
 */
class BCodeCommandHandler {
public:

    /**
     * @brief Performs an action based on the given command code.
     * @param code The integer representing the command.
     * @return An unsigned integer indicating the result of the action : 0 for success, positive values for errors.
     */
    virtual unsigned int performAction(int code) {
        return ReturnCodes::ERROR_UNSUPPORTED_COMMAND;
    }

    /**
     * @brief Performs a translation movement in the specified direction by the given units
     * @param direction1 The primary direction character (e.g., 'F' for forward, 'B' for backward).
     * @param direction2 The secondary direction character (e.g., 'L' for left, 'R' for right).
     * @param direction3 The tertiary direction character (e.g., 'U' for up, 'D' for down).
     * @param units The distance to move in the specified direction.
     */
    virtual unsigned int performTranslationMovement(char direction1, char direction2, char direction3, float units) {
        return ReturnCodes::ERROR_UNSUPPORTED_COMMAND;
    }

    /**
     * nop command handler, with a default implementation
     */
    virtual unsigned int nop() {
        return ReturnCodes::OK;
    }
    

};
