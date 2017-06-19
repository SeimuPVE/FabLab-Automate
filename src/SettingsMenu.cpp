#include "SettingsMenu.h"


SettingsMenu::SettingsMenu(Printer *printer, Button *newButton, Settings *newSettings) : MenuCreator(printer, newButton)
{
    setSettings(newSettings);
    
    int listSize = 13;
    String titleList[] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN", "Date", "Continue", "Frequency", "Borns", "NO/NC", "Exit"};
            
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
        case 9 : setFrequency(); break;
        case 10 : setBorns(); break;
        case 11 : setNO(); break;
        case 12 : setExitFlag(true); break;
        default : Serial.println("Error : menu functions error."); break;
        
    }
  
}

void SettingsMenu::setDay(int dayTag)
{
    printer->Clear();
    printer->WriteL1("Set day :");

}

void SettingsMenu::setMonday()
{
    setDay(MONDAY);
    printer->WriteL2("monday");
    printer->WriteL1("(to add)", 8);

    for(int i = 0; i < 3; i++)
    {
        printer->WriteL2(".", i + 6);
        delay(1000);
        
    }

}

void SettingsMenu::setTuesday()
{
    setDay(TUESDAY);
    printer->WriteL2("tuesday");
    printer->WriteL1("(to add)", 8);

    for(int i = 0; i < 3; i++)
    {
        printer->WriteL2(".", i + 7);
        delay(1000);
        
    }

}

void SettingsMenu::setWednesday()
{
    setDay(WEDNESDAY);
    printer->WriteL2("wednesday");
    printer->WriteL1("(to add)", 8);

    for(int i = 0; i < 3; i++)
    {
        printer->WriteL2(".", i + 9);
        delay(1000);
        
    }

}

void SettingsMenu::setThursday()
{
    setDay(THURSDAY);
    printer->WriteL2("thursday");
    printer->WriteL1("(to add)", 8);

    for(int i = 0; i < 3; i++)
    {
        printer->WriteL2(".", i + 8);
        delay(1000);
        
    }

}

void SettingsMenu::setFriday()
{
    setDay(FRIDAY);
    printer->WriteL2("friday");
    printer->WriteL1("(to add)", 8);

    for(int i = 0; i < 3; i++)
    {
        printer->WriteL2(".", i + 6);
        delay(1000);
        
    }

}

void SettingsMenu::setSaturday()
{
    setDay(SATURDAY);
    printer->WriteL2("saturday");
    printer->WriteL1("(to add)", 8);

    for(int i = 0; i < 3; i++)
    {
        printer->WriteL2(".", i + 8);
        delay(1000);
        
    }

}

void SettingsMenu::setSunday()
{
    setDay(SUNDAY);
    printer->WriteL2("sunday");
    printer->WriteL1("(to add)", 8);

    for(int i = 0; i < 3; i++)
    {
        printer->WriteL2(".", i + 6);
        delay(1000);
        
    }

}

void SettingsMenu::setDate()
{
    int hour, minute, day, month, year;

    hour = 15;
    minute = 5;
    day = 18;
    month = 6;
    year = 2017;

    // TODO : change initial values.
    hour = selectBetweenInterval("Select hour", hour, 0, 23);
    minute = selectBetweenInterval("Select minute", minute, 0, 59);
    day = selectBetweenInterval("Select day", day, 0, 31);
    month = selectBetweenInterval("Select month", month , 0, 11); // TODO : select label.
    year = selectBetweenInterval("Select year", year, 2000, 3000);

    settings->setDateTime(hour, minute, day, month, year);

}

void SettingsMenu::setContinue()
{
    settings->setContinue(selectBoolean("Set continue", "Continue", "Ponctual", settings->isContinue()));

}

void SettingsMenu::setFrequency()
{
    settings->setFrequency(selectBetweenInterval("Select frequency", settings->getFrequency()));

}

void SettingsMenu::setBorns()
{
    settings->setBornInf(selectBetweenInterval("Set born inf", settings->getBornInf()));
    settings->setBornSup(selectBetweenInterval("Set born sup", settings->getBornSup()));

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
            case 9 : printer->WriteL2(settings->getStrFrequency()); break;
            case 10 : printer->WriteL2(settings->getStrBorns()); break;
            case 11 : printer->WriteL2(settings->getStrNormalyOpen()); break;
            case 12 : printer->WriteL2("Go on main menu"); break;
            default : Serial.println("Error : menu functions error."); break;
            
        }

}

int SettingsMenu::selectBetweenInterval(String label, int initialValue, int inf, int sup)
{
    int result = initialValue;

    printer->Clear();
    printer->WriteL1(label);
    printer->WriteL2(result);

    while(!button->buttonOk())
    {
        button->checkButtons();

        if(button->buttonUp())
        {
            result++;
            if(result > sup)
                result = inf;

            printer->Clear();
            printer->WriteL1(label);
            printer->WriteL2(result);

        }
        else if(button->buttonDown())
        {
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
