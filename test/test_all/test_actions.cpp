#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include "fixtures/BCodeInterpreterTest.h"

using ::testing::Return;

TEST_F(BCodeInterpreterTest, AssertThat_ActionCommand_IsProcessedCorrectly)
{

    WRITE_COMMAND_AND_EXPECT_RESPONSE("A 42", "OK")

    EXPECT_CALL(*mockBCodeCommandHandler, performAction(42))
        .Times(1);

    bCodeInterpreter->process();
}

TEST_F(BCodeInterpreterTest, AssertThat_ActionCommand_WithHandlerError_IsRejected)
{

    WRITE_COMMAND_AND_EXPECT_RESPONSE("A 55", "ERR 999")

    EXPECT_CALL(*mockBCodeCommandHandler, performAction(55))
        .Times(1)
        .WillOnce(Return(999));

    bCodeInterpreter->process();
}




TEST_F(BCodeInterpreterTest, AssertThat_ActionCommand_WithUnparsableActionCode_IsRejected)
{

    WRITE_COMMAND_AND_EXPECT_RESPONSE("A XYZ", "ERR 100")

    EXPECT_CALL(*mockBCodeCommandHandler, performAction(testing::_))
        .Times(0);

    bCodeInterpreter->process();
}

