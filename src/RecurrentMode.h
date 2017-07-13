#ifndef RECURRENTMODE_H
#define RECURRENTMODE_H

#include "ModeCreator.h"


/**
 * Recurrent mode. Get sensor information promptly and use the result to turn on or off the relay.
 */
class RecurrentMode : public ModeCreator
{
    public:
        /**
         * Recurrent mode.
         * @param newSensors : sensor to get the information.
         * @param newPrinter : way to print information.
         * @param newButton : button to used to move in the menu.
         * @param newIsTest : boolean to tell if it's for tests or a normal mode.
         */
        RecurrentMode(Sensors *newSensors, Printer *newPrinter, Button *newButton, bool newIsTest);

        /**
         * Get a simple execution with only one measure.
         */
        bool simpleExec();

};

#endif
