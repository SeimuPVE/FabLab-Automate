#ifndef CONTINUEMODE_H
#define CONTINUEMODE_H

#include <Time.h>
#include "Sensors.h"
#include "Button.h"

#define LABEL_CONTINUE_TESTING "Testing..."
#define LABEL_CONTINUE_WORKING "Working..."


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
        ContinueMode(Sensors *newSensors, Printer *newPrinter, Button *newButton, bool newIsTest);
        void continueModeSimpleExec();
        void launch();

};

#endif
