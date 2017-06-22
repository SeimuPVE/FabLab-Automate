#include "ContinueMode.h"


ContinueMode::ContinueMode(Sensors *newSensors, Printer *newPrinter, Button *newButton, bool newIsTest)
{
    sensors = newSensors;
    printer = newPrinter;
    button = newButton;
    isTest = newIsTest;
    average = 0;

    off = false;
    sample_size = sensors->getSettings()->getSample_size();
    born_inf = sensors->getSettings()->getBornInf();
    born_sup = sensors->getSettings()->getBornSup();

    if((samples = (unsigned int *) malloc(sample_size * sizeof(unsigned int))) == NULL)
        Serial.println("Can't malloc samples.");

    if(sensors->getSettings()->isNO())
        sensors->setRelais(true);
    else
        sensors->setRelais(false);

    printer->Clear();
    if(isTest)
        printer->WriteL1(LABEL_CONTINUE_TESTING);
    else
        printer->WriteL1(LABEL_CONTINUE_WORKING);
    printer->WriteL2(sensors->getMesure());

    for(i = 0; i < sample_size; i++)
    {
        samples[i] = sensors->getMesure();
        average += samples[i];
        delay(60 * 60 / sensors->getSettings()->getFrequency());

    }
    average /= sample_size;

    printer->Clear();
    if(isTest)
        printer->WriteL1(LABEL_CONTINUE_TESTING);
    else
        printer->WriteL1(LABEL_CONTINUE_WORKING);
    printer->WriteL2(average);

    if(average < born_inf || average > born_sup)
    {
        sensors->setRelais(!sensors->getRelais());
        off = true;

    }

    t1 = now();
    t1_printer = t1;
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

        if(average < born_inf || average > born_sup)
        {
            sensors->setRelais(!sensors->getRelais());
            off = true;

        }

        if(second(t2 - t1_printer) > 1)
        {
            printer->Clear();
            if(isTest)
                printer->WriteL1(LABEL_CONTINUE_TESTING);
            else
                printer->WriteL1(LABEL_CONTINUE_WORKING);
            printer->WriteL2(sensors->getMesure());

            t1_printer = t2;

        }

        t1 = t2;

    }

    t2 = now();
    button->checkButtonsUnblocking();

}

void ContinueMode::launch()
{
    unsigned int dayTag;
    unsigned int startingHour;
    unsigned int startingMinute;
    unsigned int endingHour;
    unsigned int endingMinute;

    while(!button->buttonOk() && !off)
    {
        dayTag = dayOfWeek(now()) - 2;
        startingHour = sensors->getSettings()->getPlanning()->getDay(dayTag)->getStartingHour();
        startingMinute = sensors->getSettings()->getPlanning()->getDay(dayTag)->getStartingMinute();
        endingHour = sensors->getSettings()->getPlanning()->getDay(dayTag)->getEndingHour();
        endingMinute = sensors->getSettings()->getPlanning()->getDay(dayTag)->getEndingMinute();

        if(isTest)
            continueModeSimpleExec();
        else if((hour() > startingHour) || ((hour() == startingHour) && (minute() > startingMinute)))
        {
            if((hour() < endingHour) || ((hour() == endingHour) && (minute() < endingMinute)))
                continueModeSimpleExec();
            else
            {
                button->checkButtonsUnblocking();

                if(button->buttonOk())
                    break;

            }

        }
        else
        {
            if(second(t2 - t1_printer) > 1)
            {
                printer->Clear();
                printer->WriteL1(LABEL_CONTINUE_SLEEPING);
                printer->WriteL2(sensors->getMesure());

                t1_printer = t2;

            }

            button->checkButtonsUnblocking();

            if(button->buttonOk())
                break;

        }

        t2 = now();

    }

    while(!button->buttonOk() && off)
    {
        tone(BUZZER_PORT, 1000);
        delay(100);
        noTone(BUZZER_PORT);
        delay(100);

        button->checkButtonsUnblocking();

    }

    free(samples);

}
