
namespace bcode
{

    /**
     * @brief Defines standard error codes for the b-code protocol.
     */
    namespace ReturnCodes
    {
        /**
         * @brief Defines the OK code for successful operations.
         */
        constexpr unsigned OK = 0;

        /**
         * A parsing error occurs when a command cannot be interpreted correctly.
         */
        constexpr unsigned int ERROR_PARSING_ERROR = 1;

        /**
         * An unparsable command code is a command code that cannot be interpreted.
         * @brief Defines the error code for unparsable command codes.
         */
        constexpr unsigned int ERROR_UNPARSABLE_COMMAND_CODE = 2;

        /**
         * An unknown command is a command that is not part of the protocol.
         * @brief Defines the error code for unknown commands.
         */
        constexpr unsigned int ERROR_UNKNOWN_COMMAND = 3;

        /**
         * An unsupported command is a command that is part of the protocol but not implemented by the device.
         * @brief Defines the error code for unsupported commands.
         */
        constexpr unsigned int ERROR_UNSUPPORTED_COMMAND = 4;

        // Action-specific error codes

        /**
         * @brief Defines the error code for unparsable action codes.
         */
        constexpr unsigned int ERROR_UNPARSABLE_ACTION_CODE = 100;

        // Translation-specific error codes

        /**
         * @brief Defines the error code for unparsable translation directions.
         */
        constexpr unsigned int ERROR_UNPARSABLE_TRANSLATION_DIRECTION = 200;

        /**
         * @brief Defines the error code for unparsable translation units.
         */
        constexpr unsigned int ERROR_UNPARSABLE_TRANSLATION_UNIT = 201;
    }

    namespace CommonTranslationDirections
    {
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

        /**
         * @brief Defines the direction code for upward movement.
         */
        constexpr char UP = 'U';

        /**
         * @brief Defines the direction code for downward movement.
         */
        constexpr char DOWN = 'D';

        /**
         * @brief Defines the axis code for the X axis.
         */
        constexpr char X_AXIS = 'X';

        /**
         * @brief Defines the axis code for the Y axis.
         */
        constexpr char Y_AXIS = 'Y';

        /**
         * @brief Defines the axis code for the Z axis.
         */
        constexpr char Z_AXIS = 'Z';
    }

    namespace CommonRotationDirections
    {

        /**
         * @brief Defines the direction code for left rotation.
         */
        constexpr char LEFT = 'L';

        /**
         * @brief Defines the direction code for right rotation.
         */
        constexpr char RIGHT = 'R';

        /**
         * @brief Defines the direction code for upward rotation.
         */
        constexpr char UP = 'U';

        /**
         * @brief Defines the direction code for downward rotation.
         */
        constexpr char DOWN = 'D';

        /**
         * @brief Defines the direction code for clockwise rotation.
         */
        constexpr char CLOCKWISE = 'C';

        /**
         * @brief Defines the direction code for counter-clockwise rotation.
         */
        constexpr char COUNTER_CLOCKWISE = 'A';

        /**
         * @brief Defines the axis code for the X axis.
         */
        constexpr char X_AXIS = 'X';

        /**
         * @brief Defines the axis code for the Y axis.
         */
        constexpr char Y_AXIS = 'Y';

        /**
         * @brief Defines the axis code for the Z axis.
         */
        constexpr char Z_AXIS = 'Z';

        /**
         * @brief Defines the yaw rotation code.
         */
        constexpr char YAW = 'Y';

        /**
         * @brief Defines the pitch rotation code.
         */
        constexpr char PITCH = 'P';

        /**
         * @brief Defines the roll rotation code.
         */
        constexpr char ROLL = 'R';

    }

}