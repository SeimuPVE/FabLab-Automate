#include "SettingsMenu.h"

#define SELECTOR_HOUR "Select hour"
#define SELECTOR_STARTING_HOUR "Start hour"
#define SELECTOR_STARTING_MINUTE "Start minute"
#define SELECTOR_ENDING_HOUR "End hour"
#define SELECTOR_ENDING_MINUTE "End minute"


SettingsMenu::SettingsMenu(Printer *printer, Button *newButton, Settings *newSettings) : MenuCreator(printer, newButton)
{
    setSettings(newSettings);

    int listSize = 12;
    String titleList[] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN", "Date", "Continue", "Borns", "NO/NC", "Exit"};

    setTitles(titleList, listSize);

}

void SettingsMenu::menuFunctions(int choice)
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
        case 11 : setExitFlag(true); break;
        default : Serial.println("Error : menu functions error."); break;
        
    }
  
}

void SettingsMenu::setDay(int dayTag)
{
    int startingHour = settings->getPlanning()->getDay(dayTag)->getStartingHour();
    int startingMinute = settings->getPlanning()->getDay(dayTag)->getStartingMinute();
    int endingHour = settings->getPlanning()->getDay(dayTag)->getEndingHour();
    int endingMinute = settings->getPlanning()->getDay(dayTag)->getEndingMinute();

    startingHour = selectBetweenInterval(SELECTOR_STARTING_HOUR, false, startingHour, 0, 23);
    startingMinute = selectBetweenInterval(SELECTOR_STARTING_MINUTE, false, startingMinute, 0, 59);
    endingHour = selectBetweenInterval(SELECTOR_ENDING_HOUR, false, endingHour, 0, 23);
    endingMinute = selectBetweenInterval(SELECTOR_ENDING_MINUTE, false, endingMinute, 0, 59);

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
    int hour, minute, day, month, year;

    hour = 0;
    minute = 0;
    day = 1;
    month = 1;
    year = 2001;

    hour = selectBetweenInterval(SELECTOR_HOUR, false, hour, 0, 23);
    minute = selectBetweenInterval("Select minute", false, minute, 0, 59);
    day = selectBetweenInterval("Select day", false, day, 1, 31);
    month = selectBetweenInterval("Select month", false, month , 1, 12);
    year = selectBetweenInterval("Select year", false, year, 2000, 3000);

    settings->setDateTime(hour, minute, day, month, year);

}

void SettingsMenu::setContinue()
{
    settings->setContinue(selectBoolean("Set continue", "Continue", "Ponctual", settings->isContinue()));

    if(settings->isContinue())
        settings->setFrequency(selectBetweenInterval("Calculs by H", settings->getFrequency(), 0, 9999));
    else
        settings->setInterval(selectBetweenInterval("Delay in seconde", true, settings->getInterval()));

    settings->setSample_size(selectBetweenInterval("Sample size", true, settings->getSample_size()));

}

void SettingsMenu::setBorns()
{
    settings->setBornInf(selectBetweenInterval("Set born inf", true, settings->getBornInf()));
    settings->setBornSup(selectBetweenInterval("Set born sup", true, settings->getBornSup()));

}

void SettingsMenu::setNO()
{
    settings->setNO(selectBoolean("Set NO/NC", "Normaly open", "Normaly close", settings->isNO()));

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
            case 11 : printer->WriteL2("Go on main menu"); break;
            default : Serial.println("Error : menu functions error."); break;
            
        }

}

int SettingsMenu::selectBetweenInterval(String label, bool super_incrementor, int initialValue, int inf, int sup)
{
    int result = initialValue, positif_incrementer = 0, negatif_incrementer = 0;

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

            if(result < inf)
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
