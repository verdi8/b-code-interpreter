
#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include "fixtures/BCodeInterpreterTest.h"

using ::testing::Return;

TEST_F(BCodeInterpreterTest, ActionOk)
{
    ON_CALL(*mockBCodeIO, readLine())
        .WillByDefault(Return(const_cast<char*>("A 42")));

    EXPECT_CALL(*mockBCodeCommandHandler, performAction(42))
        .Times(1);

    EXPECT_CALL(*mockBCodeIO, writeLine(testing::StrEq("OK")))
        .Times(1);

    bCodeInterpreter->process();
}

TEST_F(BCodeInterpreterTest, ActionIllegalCode)
{
    ON_CALL(*mockBCodeIO, readLine())
        .WillByDefault(Return(const_cast<char*>("A XYZ")));

    EXPECT_CALL(*mockBCodeCommandHandler, performAction(testing::_))
        .Times(0);

    EXPECT_CALL(*mockBCodeIO, writeLine(testing::StrEq("ERR 100")))
        .Times(1);

    bCodeInterpreter->process();
}

