#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "InterpreterTest.h"


using ::testing::Mock;
using ::bcode::Interpreter;

InterpreterTest::InterpreterTest()
{
    mockIo = new MockIo();
    mockCommandHandler = new MockCommandHandler();
    bCodeInterpreter = new Interpreter(mockIo, mockCommandHandler);
}

void InterpreterTest::SetUp()
{
    Mock::VerifyAndClear(mockCommandHandler);
    Mock::VerifyAndClear(mockIo);    
    Mock::AllowLeak(mockCommandHandler);
    Mock::AllowLeak(mockIo);
}
