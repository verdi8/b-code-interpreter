
#include <gtest/gtest.h>
#include "fixtures/BCodeInterpreterTest.h"

TEST_F(BCodeInterpreterTest, TranslationMovementOk)
{
    dummmyBCodeIO->injectInputLine("T F 4.2");
    bCodeInterpreter->process();
    EXPECT_STREQ(dummmyBCodeIO->getOutputLine(), "OK");
    EXPECT_EQ(dummyBCodeCommandHandler->getPerformedDirection(), 'A');
    EXPECT_FLOAT_EQ(dummyBCodeCommandHandler->getPerformedUnits(), 4.2f);
}

