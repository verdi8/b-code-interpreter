#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include "fixtures/InterpreterTest.h"

using ::testing::Return;

TEST_F(InterpreterTest, AssertThat_ActionCommand_IsProcessedCorrectly)
{
    char commandLine[] = "A 42";

    EXPECT_CALL(*mockCommandHandler, performAction(42))
        .Times(1);

    EXPECT_EQ(bCodeInterpreter->process(commandLine), 0u);
}

TEST_F(InterpreterTest, AssertThat_ActionCommand_WithHandlerError_IsRejected)
{
    char commandLine[] = "A 55";

    EXPECT_CALL(*mockCommandHandler, performAction(55))
        .Times(1)
        .WillOnce(Return(999));

    EXPECT_EQ(bCodeInterpreter->process(commandLine), 999u);
}




TEST_F(InterpreterTest, AssertThat_ActionCommand_WithUnparsableActionCode_IsRejected)
{
    char commandLine[] = "A XYZ";

    EXPECT_CALL(*mockCommandHandler, performAction(testing::_))
        .Times(0);

    EXPECT_EQ(bCodeInterpreter->process(commandLine), 100u);
}

