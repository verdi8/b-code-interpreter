#pragma once

namespace bcode {

class CommandUtils {
public:
    /**
     * @brief Checks if the given character (needle) matches any of the three provided characters (param1, param2, param3).
     */
    inline static bool isInParameters(char needle, char param1, char param2, char pram3);
};

}
