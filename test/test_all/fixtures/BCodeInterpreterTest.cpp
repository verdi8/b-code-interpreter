#include "gtest/gtest.h"
#include "BCodeInterpreterTest.h"
#include "BCodeInterpreter.h"
#include "dummy/DummyBCodeIO.h"
#include "dummy/DummyBCodeCommandHandler.h"

BCodeInterpreterTest::BCodeInterpreterTest()
{
    dummmyBCodeIO = new DummyBCodeIO();
    dummyBCodeCommandHandler = new DummyBCodeCommandHandler();
    bCodeInterpreter = new BCodeInterpreter(dummmyBCodeIO, dummyBCodeCommandHandler);
}

void BCodeInterpreterTest::SetUp()
{
    dummyBCodeCommandHandler->reset();
}
