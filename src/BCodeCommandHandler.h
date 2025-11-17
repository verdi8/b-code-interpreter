#pragma once

#include "BCodeConstants.h"

/**
 * @class BCodeCommandHandler
 * @brief Interface for handling BCode commands.
 */
class BCodeCommandHandler {
public:

    /**
     * @brief Performs an action based on the given command code.
     * @param code The integer representing the command.
     * @return An unsigned integer indicating the result of the action : 0 for success, positive values for errors.
     */
    virtual unsigned int performAction(int code) = 0;

    /**
     * @brief Performs a translation movement in the specified direction by the given units.
     * @param direction The direction of the movement (e.g., 'F' for forward, 'B' for backward).
     * @param units The number of units to move in the specified direction.
     * @return An unsigned integer indicating the result of the movement : 0 for success, positive values for errors.
     */
    virtual unsigned int performTranslationMovement(char direction, float units) = 0;

    /**
     * nop command handler, with a default implementation
     */
    virtual unsigned int nop() {
        return ReturnCodes::OK;
    }
    

};
