#include "ContinueMode.h"


ContinueMode::ContinueMode(Sensors *newSensors, Printer *newPrinter, Button *newButton)
{
    sensors = newSensors;
    printer = newPrinter;
    button = newButton;
    average = 0;

    off = false;
    sample_size = sensors->getSettings()->getSample_size();
    born_inf = sensors->getSettings()->getBornInf();
    born_sup = sensors->getSettings()->getBornSup();

    if((samples = (int *) malloc(sample_size * sizeof(int))) == NULL)
        Serial.println("Can't malloc samples.");

    if(sensors->getSettings()->isNO())
        sensors->setRelais(true);
    else
        sensors->setRelais(false);

    printer->Clear();
    printer->WriteL1("Testing...");
    printer->WriteL2(sensors->getMesure());

    for(i = 0; i < sample_size; i++)
    {
        samples[i] = sensors->getMesure();
        average += samples[i];
        delay(60 * 60 / sensors->getSettings()->getFrequency());

    }
    average /= sample_size;

    printer->Clear();
    printer->WriteL1("Testing...");
    printer->WriteL2(average);

    if(average < born_inf || average > born_sup)
    {
        sensors->setRelais(!sensors->getRelais());
        off = true;

    }

    t1 = now();
    t2 = t1;

}

void ContinueMode::continueModeSimpleExec()
{
    if(second(t2 - t1) + 1 > (60 * 60 / sensors->getSettings()->getFrequency()))
    {
        samples[i] = sensors->getMesure();

        i++;
        if(i > sample_size)
            i = 0;

        average = 0;
        for(j = 0; j < sample_size; j++)
            average += samples[j];
        average /= sample_size;

        printer->Clear();
        printer->WriteL1("Testing...");
        printer->WriteL2(average);

        if(average < born_inf || average > born_sup)
        {
            sensors->setRelais(!sensors->getRelais());
            off = true;

        }

        t1 = t2;

    }

    t2 = now();
    button->checkButtonsUnblocking();

}

void ContinueMode::launch()
{
    while(!button->buttonOk() && !off)
    {
        continueModeSimpleExec();

    }

    free(samples);

}
