#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "InterpreterTest.h"


using ::testing::Mock;
using ::bcode::Interpreter;

InterpreterTest::InterpreterTest()
{
    mockCommandHandler = new MockCommandHandler();
    bCodeInterpreter = new Interpreter(mockCommandHandler);
}

void InterpreterTest::SetUp()
{
    Mock::VerifyAndClear(mockCommandHandler);
    Mock::AllowLeak(mockCommandHandler);
}
