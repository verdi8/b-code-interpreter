#pragma once
#include "bcode/CommandHandler.h"
#include <gmock/gmock.h>  // Brings in gMock.

using ::bcode::CommandHandler;

class MockCommandHandler : public CommandHandler {
 public:
    MOCK_METHOD(unsigned int, performAction, (int code), (override));
    MOCK_METHOD(unsigned int, performTranslationMovement, (char direction1, char direction2, char direction3, float units), (override));
    MOCK_METHOD(unsigned int, nop, (), (override));
};
