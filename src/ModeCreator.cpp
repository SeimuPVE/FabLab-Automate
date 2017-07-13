#include "ModeCreator.h"


ModeCreator::ModeCreator(Sensors *newSensors, Printer *newPrinter, Button *newButton, bool newIsTest)
{
    sensors = newSensors;
    printer = newPrinter;
    button = newButton;
    isTest = newIsTest;
    average = 0;

    sample_size = sensors->getSettings()->getSample_size();
    born_inf = sensors->getSettings()->getBornInf();
    born_sup = sensors->getSettings()->getBornSup();

    if((samples = (unsigned int *) malloc(sample_size * sizeof(unsigned int))) == NULL)
        Serial.println("Can't malloc samples.");

    if(sensors->getSettings()->isNO())
        sensors->setRelay(true);
    else
        sensors->setRelay(false);

    printer->Clear();
    if(isTest)
        printer->WriteL1(F(LABEL_TESTING));
    else
        printer->WriteL1(F(LABEL_WORKING));
    printer->WriteL2(sensors->getMeasure());

}

bool ModeCreator::isInPlanning()
{
    unsigned int dayTag = dayOfWeek(now()) - 2;
    unsigned int startingHour = sensors->getSettings()->getPlanning()->getDay(dayTag)->getStartingHour();
    unsigned int startingMinute = sensors->getSettings()->getPlanning()->getDay(dayTag)->getStartingMinute();
    unsigned int endingHour = sensors->getSettings()->getPlanning()->getDay(dayTag)->getEndingHour();
    unsigned int endingMinute = sensors->getSettings()->getPlanning()->getDay(dayTag)->getEndingMinute();

    if((hour() > startingHour) || ((hour() == startingHour) && (minute() > startingMinute)))
        if((hour() < endingHour) || ((hour() == endingHour) && (minute() < endingMinute)))
            return true;
    return false;

}

void ModeCreator::printLabel(String label)
{
    if(second(t2 - t1_printer) > 1)
    {
        printer->Clear();
        printer->WriteL1(label);
        printer->WriteL2(sensors->getMeasure());

        t1_printer = t2;

    }

}

void ModeCreator::waitAndBipError()
{
    sensors->setRelay(!sensors->getSettings()->isNO());

    while(!button->buttonOk())
    {
        tone(BUZZER_PORT, 1000);
        delay(100);
        noTone(BUZZER_PORT);
        delay(100);

        button->checkButtonsUnblocking();

    }

}

bool ModeCreator::waitErrorStop()
{
    sensors->setRelay(!sensors->getSettings()->isNO());

    while(simpleExec())
    {
        button->checkButtonsUnblocking();

        if(button->buttonOk())
            return true;

    }

    sensors->setRelay(!sensors->getSettings()->isNO());

    return false;

}

void ModeCreator::launch()
{
    bool error = false;

    while(!button->buttonOk() && !error)
    {
        if(isTest || isInPlanning())
            error = simpleExec();
        else
            printLabel(LABEL_SLEEPING);

        if(error)
        {
            if(sensors->getSettings()->isCrashMode())
                waitAndBipError();
            else
            {
                if(!waitErrorStop())
                {
                    error = false;
                    sensors->setRelay(!sensors->getRelay());

                }

            }

        }

        button->checkButtonsUnblocking();

        t2 = now();

    }

    free(samples);

}
