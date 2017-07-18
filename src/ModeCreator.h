#ifndef MODECREATOR_H
#define MODECREATOR_H

#include <Time.h>
#include "Sensors.h"
#include "Button.h"

#define LABEL_TESTING "Testing..."
#define LABEL_WORKING "Working..."
#define LABEL_SLEEPING "Sleeping..."
#define LABEL_ERROR "Error..."


class ModeCreator
{
    protected:
        Sensors *sensors;
        Printer *printer;
        Button *button;
        bool isTest;

        unsigned int i;
        unsigned int j;
        unsigned int average;
        unsigned int sample_size;
        int *samples;
        unsigned int born_inf;
        unsigned int born_sup;
        time_t t1, t1_printer, t2;

        bool last_state;

    public:
        /**
         * Constructor.
         * @param newSensors : sensor to get the information.
         * @param newPrinter : way to print information.
         * @param newButton : button to used to move in the menu.
         * @param newIsTest : boolean to tell if it's for tests or a normal mode.
         */
        ModeCreator(Sensors *newSensors, Printer *newPrinter, Button *newButton, bool newIsTest);

        /**
         * Function to check if currently we are in the planning or not.
         * @return : true if we are in the planning, false else.
         */
        bool isInPlanning();


        /**
         * Print a label on the first line of the screen and the measure on the second line.
         * @param label : label to print.
         */
        void printLabel(String label);

        /**
         * Bip continually to warn an error until the user press the button.
         */
        void waitAndBipError();

        /**
         * Wait until the error disappear or the user press the button.
         * @return
         */
        bool waitErrorStop();


        /**
         * Simple execution of the mode.
         * @return true if all append well, false if there was a mistake.
         */
        virtual bool simpleExec() = 0;

        /**
         * Launch the mode until the user press the button to quit.
         */
        void launch();

};

#endif
