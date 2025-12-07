#include <gtest/gtest.h>
#include "fixtures/InterpreterTest.h"

using ::testing::Return;

TEST_F(InterpreterTest, AssertThat_TranslationCommand_WithOneDirections_IsProcessedCorrectly)
{
    WRITE_COMMAND_AND_EXPECT_RESPONSE("T F 4.2", "OK")

    EXPECT_CALL(*mockCommandHandler, performTranslationMovement('F', '\0', '\0', 4.2)) 
        .Times(1);

    bCodeInterpreter->process();
}

TEST_F(InterpreterTest, AssertThat_TranslationCommand_WithTwoDirections_IsProcessedCorrectly)
{
    WRITE_COMMAND_AND_EXPECT_RESPONSE("T FR 3.5", "OK")

    EXPECT_CALL(*mockCommandHandler, performTranslationMovement('F', 'R', '\0', 3.5)) 
        .Times(1);

    bCodeInterpreter->process();
}

TEST_F(InterpreterTest, AssertThat_TranslationCommand_WithThreeDirections_IsProcessedCorrectly)
{
    WRITE_COMMAND_AND_EXPECT_RESPONSE("T FRU 5", "OK")

    EXPECT_CALL(*mockCommandHandler, performTranslationMovement('F', 'R', 'U', 5)) 
        .Times(1);
    
    bCodeInterpreter->process();
}

TEST_F(InterpreterTest, AssertThat_TranslationCommand_WithHdnalerError_IsRejected)
{
    WRITE_COMMAND_AND_EXPECT_RESPONSE("T F 1.5", "ERR 999")

    EXPECT_CALL(*mockCommandHandler, performTranslationMovement('F', '\0', '\0', 1.5))
        .Times(1)
        .WillOnce(Return(999));
    
    bCodeInterpreter->process();
}

TEST_F(InterpreterTest, AssertThat_TranslationCommand_WithTooMuchDirections_IsRejected)
{

    WRITE_COMMAND_AND_EXPECT_RESPONSE("T FRUD 2", "ERR 200")

    EXPECT_CALL(*mockCommandHandler, performTranslationMovement(testing::_, testing::_, testing::_, testing::_))
        .Times(0);

    bCodeInterpreter->process();
}

TEST_F(InterpreterTest, AssertThat_TranslationCommand_WithInvalidUnitOfMovement_IsRejected)
{
    WRITE_COMMAND_AND_EXPECT_RESPONSE("T F XYZ", "ERR 201")

    EXPECT_CALL(*mockCommandHandler, performTranslationMovement(testing::_, testing::_, testing::_, testing::_))
        .Times(0);

    bCodeInterpreter->process();
}

TEST_F(InterpreterTest, AssertThat_TranslationCommand_WithMissingUnitOfMovement_IsRejected)
{
    WRITE_COMMAND_AND_EXPECT_RESPONSE("T F XYZ", "ERR 201")

    EXPECT_CALL(*mockCommandHandler, performTranslationMovement(testing::_, testing::_, testing::_, testing::_))
        .Times(0);
    
    bCodeInterpreter->process();
}



