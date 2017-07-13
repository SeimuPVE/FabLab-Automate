#include "PonctualMode.h"


PonctualMode::PonctualMode(Sensors *newSensors, Printer *newPrinter, Button *newButton, bool newIsTest) : ModeCreator(newSensors, newPrinter, newButton, newIsTest)
{

}

bool PonctualMode::simpleExec()
{
    if(second(t2 - t1) + 1 > sensors->getSettings()->getInterval())
    {
        average = 0;
        for(i = 0; i < sample_size; i++)
            average += sensors->getMeasure();
        average /= sample_size;

        if(isTest)
            printLabel(F(LABEL_TESTING));
        else
            printLabel(F(LABEL_WORKING));

        t1 = t2;

        if(average < born_inf || average > born_sup)
            return false;
        else
            return true;

    }

    t2 = now();

    return true;

}
