#include "ContinueMode.h"


ContinueMode::ContinueMode(Sensors *newSensors, Printer *newPrinter, Button *newButton, bool newIsTest) : ModeCreator(newSensors, newPrinter, newButton, newIsTest)
{

}

bool ContinueMode::simpleExec()
{
    if(second(t2 - t1) + 1 > (60 * 60 / sensors->getSettings()->getFrequency()))
    {
        samples[i] = sensors->getMeasure();

        i++;
        if(i > sample_size)
            i = 0;

        average = 0;
        for(j = 0; j < sample_size; j++)
            average += samples[j];
        average /= sample_size;

        // Actualize screen.
        if(isTest)
            printLabel(F(LABEL_TESTING));
        else
            printLabel(F(LABEL_WORKING));

        if(average < born_inf || average > born_sup)
            return true;
        else
            return false;

        t1 = t2;

    }

    t2 = now();

    return false;

}
