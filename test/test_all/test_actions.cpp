
#include <gtest/gtest.h>
#include "fixtures/BCodeInterpreterTest.h"


TEST_F(BCodeInterpreterTest, ActionOk)
{
    dummmyBCodeIO->injectInputLine("A 42");
    bCodeInterpreter->process();
    EXPECT_STREQ(dummmyBCodeIO->getOutputLine(), "OK");
    EXPECT_EQ(dummyBCodeCommandHandler->getPerformedActionCode(), 42);
}

TEST_F(BCodeInterpreterTest, ActionIllegalCode)
{
    dummmyBCodeIO->injectInputLine("A XYZ");
    bCodeInterpreter->process();
    EXPECT_STREQ(dummmyBCodeIO->getOutputLine(), "ERR 100");
    EXPECT_EQ(dummyBCodeCommandHandler->getPerformedActionCode(), -1);
}

