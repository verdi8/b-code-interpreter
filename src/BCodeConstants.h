
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
