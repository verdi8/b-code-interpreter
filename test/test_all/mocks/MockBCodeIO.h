#pragma once

#include <gmock/gmock.h>
#include "BCodeIO.h"

/**
 * @class BCodeIOMock
 * @brief Mock implementation of the BCodeIO interface for testing purposes.
 */
class MockBCodeIO : public BCodeIO
{
public:
    MOCK_METHOD(char *, readLine, (), (override));
    MOCK_METHOD(void, writeLine, (const char *line), (override));
};