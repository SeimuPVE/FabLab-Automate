#include "DaysMenu.h"


DaysMenu::DaysMenu(Printer *printer, Button *newButton, Settings *newSettings) : MenuCreator(printer, newButton)
{
    setSettings(newSettings);

    unsigned int listSize = 9;
    String titleList[] =    {
            F(LABEL_SHORT_MONDAY),
            F(LABEL_SHORT_TUESDAY),
            F(LABEL_SHORT_WEDNESDAY),
            F(LABEL_SHORT_THURSDAY),
            F(LABEL_SHORT_FRIDAY),
            F(LABEL_SHORT_SATURDAY),
            F(LABEL_SHORT_SUNDAY),
            F(TITLE_DATE),
            F(TITLE_EXIT)
    };

    setTitles(titleList, listSize);

}

void DaysMenu::menuFunctions(unsigned int choice)
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
        case 8 : settings->save(); setExitFlag(true); break;
        default : Serial.println("Error : menu functions error."); break;

    }

}

void DaysMenu::setDay(unsigned int dayTag)
{
    unsigned int startingHour = settings->getPlanning()->getDay(dayTag)->getStartingHour();
    unsigned int startingMinute = settings->getPlanning()->getDay(dayTag)->getStartingMinute();
    unsigned int endingHour = settings->getPlanning()->getDay(dayTag)->getEndingHour();
    unsigned int endingMinute = settings->getPlanning()->getDay(dayTag)->getEndingMinute();

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

void DaysMenu::setMonday()
{
    setDay(MONDAY);

}

void DaysMenu::setTuesday()
{
    setDay(TUESDAY);

}

void DaysMenu::setWednesday()
{
    setDay(WEDNESDAY);

}

void DaysMenu::setThursday()
{
    setDay(THURSDAY);

}

void DaysMenu::setFriday()
{
    setDay(FRIDAY);

}

void DaysMenu::setSaturday()
{
    setDay(SATURDAY);

}

void DaysMenu::setSunday()
{
    setDay(SUNDAY);

}

void DaysMenu::setDate()
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

void DaysMenu::setSettings(Settings *newSettings)
{
    settings = newSettings;

}

void DaysMenu::printLabel()
{
    if(currentChoice >= MONDAY && currentChoice <= SUNDAY)
        printer->WriteL2(settings->getStrDay(currentChoice));
    else if(currentChoice == SUNDAY + 1)
        printer->WriteL2(settings->getStrCurrentDate());
    else
        printer->WriteL2(F(LABEL_GO_BACK));

}
