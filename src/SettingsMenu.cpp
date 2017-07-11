#include "SettingsMenu.h"


SettingsMenu::SettingsMenu(Printer *printer, Button *newButton, Settings *newSettings) : MenuCreator(printer, newButton)
{
    setSettings(newSettings);

    int listSize = 12;
    String titleList[] =    {
                                F(LABEL_SHORT_MONDAY),
                                F(LABEL_SHORT_TUESDAY),
                                F(LABEL_SHORT_WEDNESDAY),
                                F(LABEL_SHORT_THURSDAY),
                                F(LABEL_SHORT_FRIDAY),
                                F(LABEL_SHORT_SATURDAY),
                                F(LABEL_SHORT_SUNDAY),
                                F(TITLE_DATE),
                                F(TITLE_CONTINUE),
                                F(TITLE_BORNS),
                                F(TITLE_NO),
                                F(TITLE_EXIT)
                            };

    setTitles(titleList, listSize);

}

void SettingsMenu::menuFunctions(unsigned int choice)
{
    switch(choice)
    {
        case 0 : setMonday(); break;
        case 1 : setTuesday(); break;
        case 2 : setWednesday(); break;
        case 3 : setThursday(); break;
        case 4 : setFriday(); break;
        case 5 : setSaturday(); break;
        case 6 : setSunday(); break;
        case 7 : setDate(); break;
        case 8 : setContinue(); break;
        case 9 : setBorns(); break;
        case 10 : setNO(); break;
        case 11 : settings->save(); setExitFlag(true); break;
        default : Serial.println("Error : menu functions error."); break;
        
    }
  
}

void SettingsMenu::setDay(unsigned int dayTag)
{
    int startingHour = settings->getPlanning()->getDay(dayTag)->getStartingHour();
    int startingMinute = settings->getPlanning()->getDay(dayTag)->getStartingMinute();
    int endingHour = settings->getPlanning()->getDay(dayTag)->getEndingHour();
    int endingMinute = settings->getPlanning()->getDay(dayTag)->getEndingMinute();

    startingHour = selectBetweenInterval(F(SELECTOR_STARTING_HOUR), false, startingHour, 0, 23);
    startingMinute = selectBetweenInterval(F(SELECTOR_STARTING_MINUTE), false, startingMinute, 0, 59);

    if(endingHour > startingHour)
        endingHour = selectBetweenInterval(F(SELECTOR_ENDING_HOUR), false, endingHour, startingHour, 23);
    else
        endingHour = selectBetweenInterval(F(SELECTOR_ENDING_HOUR), false, startingHour, startingHour, 23);

    if(startingHour == endingHour)
        if(endingMinute > startingMinute)
            endingMinute = selectBetweenInterval(F(SELECTOR_ENDING_MINUTE), false, endingMinute, startingMinute + 1, 59);
        else
            endingMinute = selectBetweenInterval(F(SELECTOR_ENDING_MINUTE), false, startingMinute + 1, startingMinute + 1, 59);
    else
        endingMinute = selectBetweenInterval(F(SELECTOR_ENDING_MINUTE), false, endingMinute, 0, 59);

    settings->setDay(dayTag, startingHour, startingMinute, endingHour, endingMinute);

}

void SettingsMenu::setMonday()
{
    setDay(MONDAY);

}

void SettingsMenu::setTuesday()
{
    setDay(TUESDAY);

}

void SettingsMenu::setWednesday()
{
    setDay(WEDNESDAY);

}

void SettingsMenu::setThursday()
{
    setDay(THURSDAY);

}

void SettingsMenu::setFriday()
{
    setDay(FRIDAY);

}

void SettingsMenu::setSaturday()
{
    setDay(SATURDAY);

}

void SettingsMenu::setSunday()
{
    setDay(SUNDAY);

}

void SettingsMenu::setDate()
{
    unsigned int hour, minute, day, month, year;

    hour = 0;
    minute = 0;
    day = 1;
    month = 1;
    year = 2001;

    hour = selectBetweenInterval(F(SELECTOR_HOUR), false, hour, 0, 23);
    minute = selectBetweenInterval(F(SELECTOR_MINUTE), false, minute, 0, 59);
    day = selectBetweenInterval(F(SELECTOR_DAY), false, day, 1, 31);
    month = selectBetweenInterval(F(SELECTOR_MONTH), false, month , 1, 12);
    year = selectBetweenInterval(F(SELECTOR_YEAR), false, year, 2000, 3000);

    settings->setDateTime(hour, minute, day, month, year);

}

void SettingsMenu::setContinue()
{
    settings->setContinue(selectBoolean(F(SELECTOR_CONTINUE), F(SELECTOR_IS_CONTINUE), F(SELECTOR_IS_PONCTUAL), settings->isContinue()));

    if(settings->isContinue())
        settings->setFrequency(selectBetweenInterval(F(SELECTOR_FREQUENCY), true, settings->getFrequency(), 0, 9999));
    else
        settings->setInterval(selectBetweenInterval(F(SELECTOR_INTERVAL), true, settings->getInterval()));

    settings->setSample_size(selectBetweenInterval(F(SELECTOR_SAMPLE_SIZE), true, settings->getSample_size()));

}

void SettingsMenu::setBorns()
{
    settings->setBornInf(selectBetweenInterval(F(SELECTOR_BORN_INF), true, settings->getBornInf()));
    settings->setBornSup(selectBetweenInterval(F(SELECTOR_BORN_SUP), true, settings->getBornSup()));

}

void SettingsMenu::setNO()
{
    settings->setNO(selectBoolean(F(SELECTOR_NO), F(SELECTOR_IS_NO), F(SELECTOR_IS_NC), settings->isNO()));

}

void SettingsMenu::setSettings(Settings *newSettings)
{
    settings = newSettings;
  
}

void SettingsMenu::printLabel()
{
    if(currentChoice >= MONDAY && currentChoice <= SUNDAY)
        printer->WriteL2(settings->getStrDay(currentChoice));
    else
        switch(currentChoice)
        {
            case 7 :printer->WriteL2(settings->getStrCurrentDate()); break;
            case 8 : printer->WriteL2(settings->getStrIsContinue()); break;
            case 9 : printer->WriteL2(settings->getStrBorns()); break;
            case 10 : printer->WriteL2(settings->getStrNormalyOpen()); break;
            case 11 : printer->WriteL2(F(LABEL_GO_BACK)); break;
            default : Serial.println("Error : menu functions error."); break;
            
        }

}

unsigned int SettingsMenu::selectBetweenInterval(String label, bool super_incrementor, unsigned int initialValue, unsigned int inf, unsigned int sup)
{
    unsigned int positif_incrementer = 0, negatif_incrementer = 0;
    int result = initialValue;

    printer->Clear();
    printer->WriteL1(label);
    printer->WriteL2(result);

    while(!button->buttonOk())
    {
        button->checkButtons();

        if(button->buttonUp())
        {
            negatif_incrementer = 0;
            if(positif_incrementer < 10)
                positif_incrementer++;

            if(super_incrementor)
                result += positif_incrementer;
            else
                result++;

            if(result > sup)
                result = inf;

            printer->Clear();
            printer->WriteL1(label);
            printer->WriteL2(result);

        }
        else if(button->buttonDown())
        {
            positif_incrementer = 0;
            if(negatif_incrementer < 10)
                negatif_incrementer++;

            if(super_incrementor)
                result -= negatif_incrementer;
            else
                result--;

            if(result < inf || result < 0)
                result = sup;

            printer->Clear();
            printer->WriteL1(label);
            printer->WriteL2(result);

        }

    }

    return result;

}

bool SettingsMenu::selectBoolean(String label, String trueLabel, String falseLabel, bool initialValue)
{
    bool result = initialValue;

    printer->Clear();
    printer->WriteL1(label);
    if(result)
        printer->WriteL2(trueLabel);
    else
        printer->WriteL2(falseLabel);

    while(!button->buttonOk())
    {
        button->checkButtons();

        if(button->buttonUp() || button->buttonDown())
        {
            result = !result;

            printer->Clear();
            printer->WriteL1(label);
            if(result)
                printer->WriteL2(trueLabel);
            else
                printer->WriteL2(falseLabel);

        }

    }

    return result;

}
