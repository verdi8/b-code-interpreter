
/**
 * @brief Defines standard error codes for the b-code protocol.
 */
namespace ReturnCodes {
    /**
     * @brief Defines the OK code for successful operations.
     */
    constexpr unsigned OK = 0;

    // Generic parsing error codes
    constexpr unsigned int ERROR_PARSING_ERROR = 1;
    constexpr unsigned int ERROR_UNKNOWN_COMMAND = 2;

    // Action-specific error codes
    constexpr unsigned int ERROR_UNPARSABLE_ACTION_CODE = 100;

    // Translation-specific error codes
    constexpr unsigned int ERROR_UNPARSABLE_TRANSLATE_UNITS = 200;
}

namespace Directions {
    /**
     * @brief Defines the direction code for forward movement.
     */
    constexpr char FORWARD = 'F';

    /**
     * @brief Defines the direction code for backward movement.
     */
    constexpr char BACKWARD = 'B';

    /**
     * @brief Defines the direction code for right movement.
     */
    constexpr char RIGHT = 'R';
    
    /**
     * @brief Defines the direction code for left movement.
     */
    constexpr char LEFT = 'L';
}