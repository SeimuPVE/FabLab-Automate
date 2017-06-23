#ifndef CONTINUEMODE_H
#define CONTINUEMODE_H

#include <Time.h>
#include "Sensors.h"
#include "Button.h"

#define LABEL_CONTINUE_TESTING "Testing..."
#define LABEL_CONTINUE_WORKING "Working..."
#define LABEL_CONTINUE_SLEEPING "Sleeping..."


/**
 * Continue mode. Get sensor information in continue and use the result to turn on or off the relay.
 */
class ContinueMode {
    private:
        Sensors *sensors;
        Printer *printer;
        Button *button;
        bool isTest;

        unsigned int i;
        unsigned int j;
        unsigned int average;
        unsigned int sample_size;
        unsigned int *samples;
        unsigned int born_inf;
        unsigned int born_sup;
        bool off;
        time_t t1, t1_printer, t2;

    public:
        /**
         * Constructor.
         * @param newSensors : sensor to get the information.
         * @param newPrinter : way to print information.
         * @param newButton : button to used to move in the menu.
         * @param newIsTest : boolean to tell if it's for tests or a normal mode.
         */
        ContinueMode(Sensors *newSensors, Printer *newPrinter, Button *newButton, bool newIsTest);
        /**
         * Get a simple execution with only one measure.
         */
        void continueModeSimpleExec();
        /**
         * Launch the entire mode.
         */
        void launch();

};

#endif
