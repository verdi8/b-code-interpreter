#pragma once
#include "../Io.h"

namespace bcode
{

    /**
     * @class SerialIo
     * @brief Implementation of Io for serial communication.
     */
    class ArduinoSerialIo : public Io
    {
    public:
        /**
         * @brief Reads a line of BCode command from the serial interface.
         * @return A pointer to the read line as a character array.
         */
        char *readLine() override;

        /**
         * @brief Writes a line of BCode command to the serial interface.
         * @param line The line to write as a character array.
         */
        void writeLine(const char *line) override;
    };

}