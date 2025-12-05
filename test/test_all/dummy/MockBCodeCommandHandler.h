#include <gmock/gmock.h>  // Brings in gMock.

class MockBCodeCommandHandler : public BCodeCommandHandler {
 public:
    MOCK_METHOD(unsigned int, performAction, (int code), (override));
    MOCK_METHOD(unsigned int, performTranslationMovement, (char direction1, char direction2, char direction3, float units), (override));
    MOCK_METHOD0(unsigned int, nop, (), (override));
};
