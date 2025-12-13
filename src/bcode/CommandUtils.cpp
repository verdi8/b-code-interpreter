#include "CommandUtils.h"

namespace bcode {

bool CommandUtils::isInParameters(char needle, char haystack1, char haystack2, char haystack3) {
    return needle == haystack1 || needle == haystack2 || needle == haystack3;
}

}
