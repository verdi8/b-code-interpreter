#include <gtest/gtest.h>
#include "fixtures/BCodeInterpreterTest.h"

using ::testing::Return;

TEST_F(BCodeInterpreterTest, AssertThat_TranslationCommand_WithOneDirections_IsProcessedCorrectly)
{
    char commandLine[] = "T F 4.2";

    EXPECT_CALL(*mockBCodeIO, readLine())
        .WillOnce(Return(commandLine)); 

    EXPECT_CALL(*mockBCodeCommandHandler, performTranslationMovement('F', '\0', '\0', 4.2)) 
        .Times(1);
    
    EXPECT_CALL(*mockBCodeIO, writeLine(testing::StrEq("OK")))
        .Times(1);

    bCodeInterpreter->process();
}

TEST_F(BCodeInterpreterTest, AssertThat_TranslationCommand_WithTwoDirections_IsProcessedCorrectly)
{
    char commandLine[] = "T FR 3.5";

    EXPECT_CALL(*mockBCodeIO, readLine())
        .WillOnce(Return(commandLine)); 

    EXPECT_CALL(*mockBCodeCommandHandler, performTranslationMovement('F', 'R', '\0', 3.5)) 
        .Times(1);
    
    EXPECT_CALL(*mockBCodeIO, writeLine(testing::StrEq("OK")))
        .Times(1);

    bCodeInterpreter->process();
}

TEST_F(BCodeInterpreterTest, AssertThat_TranslationCommand_WithThreeDirections_IsProcessedCorrectly)
{
    char commandLine[] = "T FRU 5";

    EXPECT_CALL(*mockBCodeIO, readLine())
        .WillOnce(Return(commandLine)); 

    EXPECT_CALL(*mockBCodeCommandHandler, performTranslationMovement('F', 'R', 'U', 5)) 
        .Times(1);
    
    EXPECT_CALL(*mockBCodeIO, writeLine(testing::StrEq("OK")))
        .Times(1);

    bCodeInterpreter->process();
}

TEST_F(BCodeInterpreterTest, AssertThat_TranslationCommand_WithTooMuchDirections_IsRejected)
{
    char commandLine[] = "T FRUD 0";

    EXPECT_CALL(*mockBCodeIO, readLine())
        .WillOnce(Return(commandLine)); 

    EXPECT_CALL(*mockBCodeCommandHandler, performTranslationMovement(testing::_, testing::_, testing::_, testing::_))
        .Times(0);
    
    EXPECT_CALL(*mockBCodeIO, writeLine(testing::StrEq("ERR 200")))
        .Times(1);

    bCodeInterpreter->process();
}

TEST_F(BCodeInterpreterTest, AssertThat_TranslationCommand_WithInvalidUnitOfMovement_IsRejected)
{
    char commandLine[] = "T F XYZ";

    EXPECT_CALL(*mockBCodeIO, readLine())
        .WillOnce(Return(commandLine)); 

    EXPECT_CALL(*mockBCodeCommandHandler, performTranslationMovement(testing::_, testing::_, testing::_, testing::_))
        .Times(0);
    
    EXPECT_CALL(*mockBCodeIO, writeLine(testing::StrEq("ERR 201")))
        .Times(1);

    bCodeInterpreter->process();
}

TEST_F(BCodeInterpreterTest, AssertThat_TranslationCommand_WithMissingUnitOfMovement_IsRejected)
{
    char commandLine[] = "T F";

    EXPECT_CALL(*mockBCodeIO, readLine())
        .WillOnce(Return(commandLine)); 

    EXPECT_CALL(*mockBCodeCommandHandler, performTranslationMovement(testing::_, testing::_, testing::_, testing::_))
        .Times(0);
    
    EXPECT_CALL(*mockBCodeIO, writeLine(testing::StrEq("ERR 201")))
        .Times(1);

    bCodeInterpreter->process();
}