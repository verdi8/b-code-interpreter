#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "fixtures/InterpreterTest.h"

using ::testing::Return;


TEST_F(InterpreterTest, AssertThat_NopCommand_IsProcessedCorrectly)
{
    WRITE_COMMAND_AND_EXPECT_RESPONSE("Z", "OK")

    EXPECT_CALL(*mockCommandHandler, nop())
        .Times(1);

    bCodeInterpreter->process();

}

TEST_F(InterpreterTest, AssertThat_NopCommand_WithHandlerError_IsRejected)
{
    WRITE_COMMAND_AND_EXPECT_RESPONSE("Z", "ERR 999")

    EXPECT_CALL(*mockCommandHandler, nop())
        .Times(1)
        .WillOnce(Return(999));

    bCodeInterpreter->process();
}
