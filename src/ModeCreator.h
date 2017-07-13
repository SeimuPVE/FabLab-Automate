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
        unsigned int *samples;
        unsigned int born_inf;
        unsigned int born_sup;
        time_t t1, t1_printer, t2;

    public:
        /**
         * Constructor.
         * @param newSensors : sensor to get the information.
         * @param newPrinter : way to print information.
         * @param newButton : button to used to move in the menu.
         * @param newIsTest : boolean to tell if it's for tests or a normal mode.
         */
        ModeCreator(Sensors *newSensors, Printer *newPrinter, Button *newButton, bool newIsTest);

        bool isInPlanning();

        void printLabel(String label);
        void waitAndBipError();
        bool waitErrorStop();

        virtual bool simpleExec() = 0;

        void launch();

};

#endif
