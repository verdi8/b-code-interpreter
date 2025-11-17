
#include <gtest/gtest.h>
#include "fixtures/BCodeInterpreterTest.h"


TEST_F(BCodeInterpreterTest, UnknwonCommand)
{
    dummmyBCodeIO->injectInputLine("$ 123 456");
    bCodeInterpreter->process();
    EXPECT_STREQ(dummmyBCodeIO->getOutputLine(), "ERR 2");
    EXPECT_EQ(dummyBCodeCommandHandler->getPerformedActionCode(), -1);
}
