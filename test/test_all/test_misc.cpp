#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "fixtures/BCodeInterpreterTest.h"

using ::testing::Return;


TEST_F(BCodeInterpreterTest, AssertThat_NoCommand_IsRejected)
{
    char commandLine[] = "";

    EXPECT_CALL(*mockBCodeIO, readLine())
        .WillOnce(Return(commandLine));

    EXPECT_CALL(*mockBCodeIO, writeLine(testing::_))
        .Times(0);
   
    bCodeInterpreter->process();

}

TEST_F(BCodeInterpreterTest, AssertThat_UnknownCommand_IsRejected)
{
    char commandLine[] = "$ 123 456";

    EXPECT_CALL(*mockBCodeIO, readLine())
        .WillOnce(Return(commandLine));

    EXPECT_CALL(*mockBCodeIO, writeLine(testing::StrEq("ERR 3")))
        .Times(1);
   
    bCodeInterpreter->process();
}

TEST_F(BCodeInterpreterTest, AssertThat_TooLongCommand_IsRejected)
{
    char commandLine[] = "AB 123 456";

    EXPECT_CALL(*mockBCodeIO, readLine())
        .WillOnce(Return(commandLine));

    EXPECT_CALL(*mockBCodeIO, writeLine(testing::StrEq("ERR 2")))
        .Times(1);
   
    bCodeInterpreter->process();

}

