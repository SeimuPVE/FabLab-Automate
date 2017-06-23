#ifndef PONCTUALMODE_H
#define PONCTUALMODE_H

#include "Sensors.h"
#include "Button.h"

#define LABEL_PONCTUAL_TESTING "Testing..."
#define LABEL_PONCTUAL_WORKING "Working..."
#define LABEL_PONCTUAL_SLEEPING "Sleeping..."


/**
 * Ponctual mode. Get sensor information ponctualy and use the result to turn on or off the relay.
 */
class PonctualMode
{
    private:
        Sensors *sensors;
        Printer *printer;
        Button *button;
        bool isTest;

        unsigned int i;
        unsigned int average;
        unsigned int sample_size;
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
        PonctualMode(Sensors *newSensors, Printer *newPrinter, Button *newButton, bool newIsTest);
        /**
         * Get a simple execution with only one measure.
         */
        void ponctualModeSimpleExec();
        /**
         * Launch the entire mode.
         */
        void launch();

};

#endif
