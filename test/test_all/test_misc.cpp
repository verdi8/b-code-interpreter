
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "fixtures/BCodeInterpreterTest.h"

using ::testing::Return;

TEST_F(BCodeInterpreterTest, UnknwonCommand)
{
    ON_CALL(*mockBCodeIO, readLine())
        .WillByDefault(Return(const_cast<char*>("$ 123 456")));

    EXPECT_CALL(*mockBCodeCommandHandler, performAction(testing::_))
        .Times(0);

    EXPECT_CALL(*mockBCodeIO, writeLine(testing::StrEq("ERR 2")))
        .Times(1);
   
    bCodeInterpreter->process();

}
