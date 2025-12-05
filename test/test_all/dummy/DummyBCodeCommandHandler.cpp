#include "DummyBCodeCommandHandler.h"

unsigned int DummyBCodeCommandHandler::performAction(int code) {
    performedActionCode = code;
    return returnCode;
}


unsigned int DummyBCodeCommandHandler::performTranslationMovement(char direction1, char direction2, char direction3, float units) {
    performedDirection = direction1;
    performedUnits = units;
    return returnCode;
}

void DummyBCodeCommandHandler::reset() {
    nopped = false;
    returnCode = ReturnCodes::OK;
    performedActionCode = -1;
    performedDirection = '\0';
    performedUnits = 0.0f;
}

void DummyBCodeCommandHandler::setReturnCode(unsigned int code) {
    returnCode = code;
}

bool DummyBCodeCommandHandler::isNopped() const {
    return nopped;
}

int DummyBCodeCommandHandler::getPerformedActionCode() const {
    return performedActionCode;
}

char DummyBCodeCommandHandler::getPerformedDirection() const {
    return performedDirection;
}

float DummyBCodeCommandHandler::getPerformedUnits() const {
    return performedUnits;
}

