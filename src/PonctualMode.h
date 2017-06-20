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

    int i;
    int average;
    int sample_size;
    int born_inf;
    int born_sup;
    bool off;
    time_t t1, t2;


public:
    PonctualMode(Sensors *newSensors, Printer *newPrinter, Button *newButton, bool newIsTest);
    void ponctualModeSimpleExec();
    void launch();

};

#endif
