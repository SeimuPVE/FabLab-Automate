#ifndef CONTINUEMODE_H
#define CONTINUEMODE_H


#include <Time.h>
#include "Sensors.h"
#include "Button.h"

class ContinueMode {
    private:
        Sensors *sensors;
        Printer *printer;
        Button *button;
        bool isTest;

        int i;
        int j;
        int average;
        int sample_size;
        int *samples;
        int born_inf;
        int born_sup;
        bool off;
        time_t t1, t1_printer, t2;

    public:
        ContinueMode(Sensors *newSensors, Printer *newPrinter, Button *newButton, bool newIsTest);
        void continueModeSimpleExec();
        void launch();

};

#endif
