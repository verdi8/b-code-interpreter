#include "gtest/gtest.h"
#include "bcode/CommandUtils.h"

using bcode::CommandUtils;

TEST(CommandUtilsTest, AssertThat_IsInParameters_FindsCharacters_InAnyPosition) {
    EXPECT_TRUE(CommandUtils::isInParameters('a', 'a', '\0', 'c'));
    EXPECT_TRUE(CommandUtils::isInParameters('b', 'a', 'b', '\0'));
    EXPECT_TRUE(CommandUtils::isInParameters('c', '\0', 'b', 'c'));
    EXPECT_FALSE(CommandUtils::isInParameters('d', 'a', '\0', 'c'));
}
TEST(CommandUtilsTest, AssertThat_IsInParameters_HandlesEdgeCases) {
    // Tests with the null character
    EXPECT_TRUE(CommandUtils::isInParameters('\0', '\0', 'b', 'c'));
    EXPECT_FALSE(CommandUtils::isInParameters('\0', 'a', 'b', 'c'));
}


