#ifndef CONTINUEMODE_H
#define CONTINUEMODE_H

#include "ModeCreator.h"


/**
 * Continue mode. Get sensor information in continue and use the result to turn on or off the relay.
 */
class ContinueMode : public ModeCreator
{
    public:
        ContinueMode(Sensors *newSensors, Printer *newPrinter, Button *newButton, bool newIsTest);

        /**
         * Get a simple execution with only one measure.
         */
        bool simpleExec();

};

#endif
