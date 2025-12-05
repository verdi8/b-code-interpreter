#include "ArduinoSerialBCodeInterpreter.h"

ArduinoSerialBCodeInterpreter::ArduinoSerialBCodeInterpreter(BCodeCommandHandler* commandHandler)
    : BCodeInterpreter(new ArduinoSerialBCodeIO(), commandHandler) {
    // The command handler is passed to the base class constructor.
}
