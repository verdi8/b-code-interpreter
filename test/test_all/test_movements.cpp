
#include <gtest/gtest.h>
#include "fixtures/BCodeInterpreterTest.h"

using ::testing::Return;

TEST_F(BCodeInterpreterTest, TranslationMovementOk)
{
    ON_CALL(*mockBCodeIO, readLine())
        .WillByDefault(Return(const_cast<char*>("T F 4.2")));

    EXPECT_CALL(*mockBCodeCommandHandler, performTranslationMovement('F', NULL, NULL, 4.2)) 
        .Times(1);
    
    EXPECT_CALL(*mockBCodeIO, writeLine(testing::StrEq("OK")))
        .Times(1);

    bCodeInterpreter->process();
}
