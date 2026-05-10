#include <gtest/gtest.h>
#include "fixtures/InterpreterTest.h"

using ::testing::Return;

TEST_F(InterpreterTest, AssertThat_TranslationCommand_WithOneDirections_IsProcessedCorrectly)
{
    char commandLine[] = "T F 4.2";

    EXPECT_CALL(*mockCommandHandler, performTranslationMovement('F', '\0', '\0', 4.2)) 
        .Times(1);

    EXPECT_EQ(bCodeInterpreter->process(commandLine), 0u);
}

TEST_F(InterpreterTest, AssertThat_TranslationCommand_WithTwoDirections_IsProcessedCorrectly)
{
    char commandLine[] = "T FR 3.5";

    EXPECT_CALL(*mockCommandHandler, performTranslationMovement('F', 'R', '\0', 3.5)) 
        .Times(1);

    EXPECT_EQ(bCodeInterpreter->process(commandLine), 0u);
}

TEST_F(InterpreterTest, AssertThat_TranslationCommand_WithThreeDirections_IsProcessedCorrectly)
{
    char commandLine[] = "T FRU 5";

    EXPECT_CALL(*mockCommandHandler, performTranslationMovement('F', 'R', 'U', 5)) 
        .Times(1);
    
    EXPECT_EQ(bCodeInterpreter->process(commandLine), 0u);
}

TEST_F(InterpreterTest, AssertThat_TranslationCommand_WithHdnalerError_IsRejected)
{
    char commandLine[] = "T F 1.5";

    EXPECT_CALL(*mockCommandHandler, performTranslationMovement('F', '\0', '\0', 1.5))
        .Times(1)
        .WillOnce(Return(999));
    
    EXPECT_EQ(bCodeInterpreter->process(commandLine), 999u);
}

TEST_F(InterpreterTest, AssertThat_TranslationCommand_WithTooMuchDirections_IsRejected)
{
    char commandLine[] = "T FRUD 2";

    EXPECT_CALL(*mockCommandHandler, performTranslationMovement(testing::_, testing::_, testing::_, testing::_))
        .Times(0);

    EXPECT_EQ(bCodeInterpreter->process(commandLine), 200u);
}

TEST_F(InterpreterTest, AssertThat_TranslationCommand_WithInvalidUnitOfMovement_IsRejected)
{
    char commandLine[] = "T F XYZ";

    EXPECT_CALL(*mockCommandHandler, performTranslationMovement(testing::_, testing::_, testing::_, testing::_))
        .Times(0);

    EXPECT_EQ(bCodeInterpreter->process(commandLine), 201u);
}

TEST_F(InterpreterTest, AssertThat_TranslationCommand_WithMissingUnitOfMovement_IsRejected)
{
    char commandLine[] = "T F XYZ";

    EXPECT_CALL(*mockCommandHandler, performTranslationMovement(testing::_, testing::_, testing::_, testing::_))
        .Times(0);
    
    EXPECT_EQ(bCodeInterpreter->process(commandLine), 201u);
}



