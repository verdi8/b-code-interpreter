#include "ArduinoSerialInterpreter.h"

namespace bcode
{

    ArduinoSerialInterpreter::ArduinoSerialInterpreter(CommandHandler *commandHandler)
        : Interpreter(new ArduinoSerialIo(), commandHandler)
    {
        // The command handler is passed to the base class constructor.
    }

}