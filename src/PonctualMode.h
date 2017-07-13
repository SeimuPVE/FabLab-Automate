#ifndef PONCTUALMODE_H
#define PONCTUALMODE_H

#include "ModeCreator.h"


/**
 * Ponctual mode. Get sensor information ponctualy and use the result to turn on or off the relay.
 */
class PonctualMode : public ModeCreator
{
    public:
        PonctualMode(Sensors *newSensors, Printer *newPrinter, Button *newButton, bool newIsTest);

        /**
         * Get a simple execution with only one measure.
         */
        bool simpleExec();

};

#endif
