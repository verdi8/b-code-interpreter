#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "BCodeInterpreterTest.h"
#include "BCodeInterpreter.h"


using ::testing::Mock;

BCodeInterpreterTest::BCodeInterpreterTest()
{
    mockBCodeIO = new MockBCodeIO();
    mockBCodeCommandHandler = new MockBCodeCommandHandler();
    bCodeInterpreter = new BCodeInterpreter(mockBCodeIO, mockBCodeCommandHandler);
}

void BCodeInterpreterTest::SetUp()
{
    Mock::VerifyAndClear(mockBCodeCommandHandler);
    Mock::VerifyAndClear(mockBCodeIO);    
}
