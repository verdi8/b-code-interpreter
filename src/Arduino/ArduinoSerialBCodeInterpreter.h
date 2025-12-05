#pragma once

#include "../BCodeInterpreter.h"
#include "ArduinoSerialBCodeIO.h"

/**
 * @class ArduinoSerialBCodeInterpreter
 * @brief A specialized BCodeInterpreter preconfigured with ArduinoSerialBCodeIO.
 */
class ArduinoSerialBCodeInterpreter : public BCodeInterpreter {
public:
    /**
     * @brief Constructs an ArduinoSerialBCodeInterpreter with a preinitialized ArduinoSerialBCodeIO and a command handler.
     * @param commandHandler Pointer to the BCodeCommandHandler instance for handling commands.
     */
    ArduinoSerialBCodeInterpreter(BCodeCommandHandler* commandHandler);
};
