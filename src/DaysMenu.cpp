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

    startingHour = selectBetweenInterval(F(SELECTOR_STARTING_HOUR), 1, startingHour, 0, 23);
    startingMinute = selectBetweenInterval(F(SELECTOR_STARTING_MINUTE), 1, startingMinute, 0, 59);

    if(endingHour > startingHour)
        endingHour = selectBetweenInterval(F(SELECTOR_ENDING_HOUR), 1, endingHour, startingHour, 23);
    else
        endingHour = selectBetweenInterval(F(SELECTOR_ENDING_HOUR), 1, startingHour, startingHour, 23);

    if(startingHour == endingHour)
        if(endingMinute > startingMinute)
            endingMinute = selectBetweenInterval(F(SELECTOR_ENDING_MINUTE), 1, endingMinute, startingMinute + 1, 59);
        else
            endingMinute = selectBetweenInterval(F(SELECTOR_ENDING_MINUTE), 1, startingMinute + 1, startingMinute + 1, 59);
    else
        endingMinute = selectBetweenInterval(F(SELECTOR_ENDING_MINUTE), 1, endingMinute, 0, 59);

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
    unsigned int new_hour, new_minute, new_day, new_month, new_year, max_day;

    max_day = 30;

    new_hour = selectBetweenInterval(F(SELECTOR_HOUR), 1, (unsigned int) hour(), 0, 23);
    new_minute = selectBetweenInterval(F(SELECTOR_MINUTE), 1, (unsigned int) minute(), 0, 59);
    new_month = selectBetweenInterval(F(SELECTOR_MONTH), 1, (unsigned int) month() , 1, 12);

    if(new_month == 1 || new_month == 3 || new_month == 5 || new_month == 7 || new_month == 8 || new_month == 10 || new_month == 12)
        max_day = 31;
    new_day = selectBetweenInterval(F(SELECTOR_DAY), 1, (unsigned int) day(), 1, max_day);

    new_year = selectBetweenInterval(F(SELECTOR_YEAR), 1, (unsigned int) year(), 2000, 3000);

    settings->setDateTime(new_hour, new_minute, new_day, new_month, new_year);

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
