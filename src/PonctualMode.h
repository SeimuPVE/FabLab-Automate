#ifndef PONCTUALMODE_H
#define PONCTUALMODE_H

#include "Sensors.h"
#include "Button.h"


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
        PonctualMode(Sensors *newSensors, Printer *newPrinter, Button *newButton, bool newIsTest);
        void ponctualModeSimpleExec();
        void launch();

};

#endif
