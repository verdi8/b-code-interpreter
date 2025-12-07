#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "fixtures/InterpreterTest.h"

using ::testing::Return;


TEST_F(InterpreterTest, AssertThat_NoCommand_IsRejected)
{
    WRITE_COMMAND_AND_EXPECT_RESPONSE("", "ERR 2")
   
    bCodeInterpreter->process();
}

TEST_F(InterpreterTest, AssertThat_UnknownCommand_IsRejected)
{
    WRITE_COMMAND_AND_EXPECT_RESPONSE("$ 123 456", "ERR 3")

    bCodeInterpreter->process();
}

TEST_F(InterpreterTest, AssertThat_TooLongCommand_IsRejected)
{
    WRITE_COMMAND_AND_EXPECT_RESPONSE("ABCDE 123 456", "ERR 2")   
   
    bCodeInterpreter->process();
}


