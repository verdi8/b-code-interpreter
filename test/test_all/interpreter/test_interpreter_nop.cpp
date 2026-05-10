#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "fixtures/InterpreterTest.h"

using ::testing::Return;


TEST_F(InterpreterTest, AssertThat_NopCommand_IsProcessedCorrectly)
{
    char commandLine[] = "Z";

    EXPECT_CALL(*mockCommandHandler, nop())
        .Times(2);

    EXPECT_EQ(bCodeInterpreter->process(commandLine), 0u);

}

TEST_F(InterpreterTest, AssertThat_NopCommand_WithHandlerError_IsRejected)
{
    char commandLine[] = "Z";

    EXPECT_CALL(*mockCommandHandler, nop())
        .Times(1)
        .WillOnce(Return(999));

    EXPECT_EQ(bCodeInterpreter->process(commandLine), 999u);
}
