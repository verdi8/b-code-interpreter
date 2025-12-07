#pragma once

#include "../Interpreter.h"
#include "ArduinoSerialIo.h"

namespace bcode
{

    /**
     * @class ArduinoSerialInterpreter
     * @brief A specialized Interpreter preconfigured with ArduinoSerialIo.
     */
    class ArduinoSerialInterpreter : public Interpreter
    {
    public:
        /**
         * @brief Constructs an ArduinoSerialInterpreter with a preinitialized ArduinoSerialIo and a command handler.
         * @param commandHandler Pointer to the CommandHandler instance for handling commands.
         */
        ArduinoSerialInterpreter(CommandHandler *commandHandler);
    };

}