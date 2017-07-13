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

        if(average < born_inf || average > born_sup)
            sensors->setRelay(!sensors->getRelay());

        if(second(t2 - t1_printer) > 1)
        {
            printer->Clear();
            if(isTest)
                printer->WriteL1(F(LABEL_TESTING));
            else
                printer->WriteL1(F(LABEL_WORKING));
            printer->WriteL2(sensors->getMeasure());

            t1_printer = t2;

        }

        t1 = t2;

    }

    t2 = now();
    button->checkButtonsUnblocking();

    return true;

}
