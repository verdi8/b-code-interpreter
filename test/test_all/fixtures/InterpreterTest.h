#pragma once

#include "mocks/MockIo.h"
#include "mocks/MockCommandHandler.h"
#include "bcode/Interpreter.h"
#include "gtest/gtest.h"

using ::bcode::Interpreter;


class InterpreterTest : public testing::Test
{
protected:
    InterpreterTest();
    void SetUp();

    MockIo *mockIo;
    MockCommandHandler *mockCommandHandler;

    /**
     * @brief The Interpreter instance under test.
     */
    Interpreter *bCodeInterpreter;
};
