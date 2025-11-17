#pragma once

#include "BCodeInterpreter.h"
#include "dummy/DummyBCodeIO.h"
#include "dummy/DummyBCodeCommandHandler.h"
#include "gtest/gtest.h"

class BCodeInterpreterTest : public testing::Test
{
protected:
    BCodeInterpreterTest();
    void SetUp();

    DummyBCodeIO* dummmyBCodeIO;
    DummyBCodeCommandHandler* dummyBCodeCommandHandler;

    /**
     * @brief The BCodeInterpreter instance under test.
     */
    BCodeInterpreter* bCodeInterpreter;
};
