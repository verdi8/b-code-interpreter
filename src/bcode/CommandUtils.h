#pragma once

namespace bcode {

class CommandUtils {
public:
    /**
     * @brief Checks if the given character (needle) matches any of the three provided characters (haystack1, haystack2, haystack3).
     * The method is implemented here because it is an inline function.
     * @param needle The character to search for.
     * @param haystack1 The first character to compare against.
     * @param haystack2 The second character to compare against.
     * @param haystack3 The third character to compare against.
     * @return True if the needle matches any of the haystack characters, false otherwise.
     */
    inline static bool isInParameters(char needle, char haystack1, char haystack2, char haystack3) {
        return needle == haystack1 || needle == haystack2 || needle == haystack3;
    }
};

}
