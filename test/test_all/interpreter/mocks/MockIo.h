#pragma once

#include <gmock/gmock.h>
#include "bcode/Io.h"

using ::bcode::Io;

/**
 * @class IoMock
 * @brief Mock implementation of the Io interface for testing purposes.
 */
class MockIo : public Io
{
public:
    MOCK_METHOD(char *, readLine, (), (override));
    MOCK_METHOD(void, writeLine, (const char *line), (override));
};



#define WRITE_COMMAND_AND_EXPECT_RESPONSE(commandLine, expectedResponse)    \
    char mutableCommandLine[] = commandLine;                                \
    EXPECT_CALL(*mockIo, readLine())                                   \
        .WillOnce(Return(mutableCommandLine));                              \
    EXPECT_CALL(*mockIo, writeLine(testing::StrEq(expectedResponse)))  \
        .Times(1);
