#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "fixtures/InterpreterTest.h"

using ::testing::Return;


TEST_F(InterpreterTest, AssertThat_NoCommand_IsRejected)
{
    char commandLine[] = "";

    EXPECT_EQ(bCodeInterpreter->process(commandLine), 2u);
}

TEST_F(InterpreterTest, AssertThat_UnknownCommand_IsRejected)
{
    char commandLine[] = "$ 123 456";

    EXPECT_EQ(bCodeInterpreter->process(commandLine), 3u);
}

TEST_F(InterpreterTest, AssertThat_TooLongCommand_IsRejected)
{
    char commandLine[] = "ABCDE 123 456";

    EXPECT_EQ(bCodeInterpreter->process(commandLine), 2u);
}


