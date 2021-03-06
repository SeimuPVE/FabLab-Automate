#include "RecurrentMode.h"


RecurrentMode::RecurrentMode(Sensors *newSensors, Printer *newPrinter, Button *newButton, bool newIsTest) : ModeCreator(newSensors, newPrinter, newButton, newIsTest)
{

}

bool RecurrentMode::simpleExec()
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
            last_state = false;
        else
            last_state = true;

    }

    t2 = now();

    return last_state;

}
