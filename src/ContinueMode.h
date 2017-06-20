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
        int i;
        int j;
        int average;
        int sample_size;
        int *samples;
        int born_inf;
        int born_sup;
        bool off;
        time_t t1, t2;

    public:
        ContinueMode(Sensors *newSensors, Printer *newPrinter, Button *newButton);
        void continueModeSimpleExec();
        void launch();

};


#endif
