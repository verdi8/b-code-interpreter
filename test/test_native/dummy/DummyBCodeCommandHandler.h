#pragma once

#include "BCodeCommandHandler.h"

/**
 * @class DummyBCodeCommandHandler
 * @brief Dummy implementation of the BCodeCommandHandler interface for testing purposes.
 */
class DummyBCodeCommandHandler : public BCodeCommandHandler {
public:
    /**
     * @brief Performs an action based on the given command code.
     * @param code The integer representing the command.
     */
    unsigned int performAction(int code) override;

    /**
     * @brief Performs a translation movement in the specified direction by the given units.
     * @param direction The direction of the movement (e.g., 'F' for forward, 'B' for backward).
     * @param units The number of units to move in the specified direction.
     */
    unsigned int performTranslationMovement(char direction, float units) override;

    /**
     * @brief Resets the internal state of the command handler.
     */
    void reset();

    /**
     * @brief Sets the return code for the last operation.
     * @param code The return code to set.
     */
    void setReturnCode(unsigned int code);

    /**
     * @brief Checks if a nop command was performed.
     */
    bool isNopped() const;

    /**
     * @brief Retrieves the last performed action code.
     * @return The last performed action code as an integer.
     */
    int getPerformedActionCode() const;

    /**
     * @brief Retrieves the last performed direction.
     * @return The last performed direction as a character.
     */
    char getPerformedDirection() const;

    /**
     * @brief Retrieves the last performed units.
     * @return The last performed units as a float.
     */
    float getPerformedUnits() const;

private:
    unsigned int returnCode = ReturnCodes::OK; ///< Stores the return code of the last operation
    bool nopped; ///< Indicates if a nop command was performed
    int performedActionCode = -1; ///< Stores the last performed action code
    char performedDirection = '\0'; ///< Stores the last performed direction
    float performedUnits = 0.0f; ///< Stores the last performed units
};