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



#define WRITE_COMMAND_AND_EXPECT_RESPONSE(commandLine, expectedResponse)    \
    char mutableCommandLine[] = commandLine;                                \
    EXPECT_CALL(*mockBCodeIO, readLine())                                   \
        .WillOnce(Return(mutableCommandLine));                              \
    EXPECT_CALL(*mockBCodeIO, writeLine(testing::StrEq(expectedResponse)))  \
        .Times(1);
