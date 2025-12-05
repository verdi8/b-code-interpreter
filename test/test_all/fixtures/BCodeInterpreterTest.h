#pragma once

#include "mocks/MockBCodeIO.h"
#include "mocks/MockBCodeCommandHandler.h"
#include "BCodeInterpreter.h"
#include "gtest/gtest.h"

class BCodeInterpreterTest : public testing::Test
{
protected:
    BCodeInterpreterTest();
    void SetUp();

    MockBCodeIO* mockBCodeIO;
    MockBCodeCommandHandler* mockBCodeCommandHandler;

    /**
     * @brief The BCodeInterpreter instance under test.
     */
    BCodeInterpreter* bCodeInterpreter;
};
