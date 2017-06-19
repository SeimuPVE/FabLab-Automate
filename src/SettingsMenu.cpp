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
        case 8 : setPonctual(); break;
        case 9 : setFrequency(); break;
        case 10 : setBorns(); break;
        case 11 : setNO(); break;
        case 12 : setExitFlag(true); break;
        default : Serial.println("Error : menu functions error."); break;
        
    }
  
}

void SettingsMenu::updateLabels()
{
  
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
    printer->Clear();
    printer->WriteL1("Set date");
    printer->WriteL2("(to add)", 8);
    
    for(int i = 0; i < 3; i++)
    {
        printer->WriteL2(".", i);
        delay(1000);
        
    }

}

void SettingsMenu::setPonctual()
{
    printer->Clear();
    printer->WriteL1("Set ponctuality");
    printer->WriteL2(settings->getStrIsContinue());

    while(!button->buttonOk())
    {
        button->checkButtons();

        if(button->buttonUp() || button->buttonDown())
        {
            settings->setContinue(!settings->isContinue());

            printer->Clear();
            printer->WriteL1("Set ponctuality");
            printer->WriteL2(settings->getStrIsContinue());


        }

    }

}

void SettingsMenu::setFrequency()
{
    printer->Clear();
    printer->WriteL1("Set frequency");
    printer->WriteL2(settings->getFrequency());

    while(!button->buttonOk())
    {
        button->checkButtons();

        if(button->buttonUp())
        {
            settings->setFrequency(settings->getFrequency() + 1);

            printer->Clear();
            printer->WriteL1("Set frequency");
            printer->WriteL2(settings->getFrequency());

        }
        else if(button->buttonDown())
        {
            settings->setFrequency(settings->getFrequency() - 1);

            printer->Clear();
            printer->WriteL1("Set frequency");
            printer->WriteL2(settings->getFrequency());

        }

    }

}

void SettingsMenu::setBorns()
{
    printer->Clear();
    printer->WriteL1("Set born sup");
    printer->WriteL2(settings->getBornSup());

    while(!button->buttonOk()) {
        button->checkButtons();

        if (button->buttonUp()) {
            settings->setBornSup(settings->getBornSup() + 1);

            printer->Clear();
            printer->WriteL1("Set born sup");
            printer->WriteL2(settings->getBornSup());

        } else if (button->buttonDown()) {
            settings->setBornSup(settings->getBornSup() - 1);

            printer->Clear();
            printer->WriteL1("Set born sup");
            printer->WriteL2(settings->getBornSup());

        }

    }


    printer->Clear();
    printer->WriteL1("Set born inf");
    printer->WriteL2(settings->getBornInf());

    while(!button->buttonOk())
    {
        button->checkButtons();

        if(button->buttonUp())
        {
            settings->setBornInf(settings->getBornInf()+1);

            printer->Clear();
            printer->WriteL1("Set born inf");
            printer->WriteL2(settings->getBornInf());

        }
        else if(button->buttonDown())
        {
            settings->setBornInf(settings->getBornInf()-1);

            printer->Clear();
            printer->WriteL1("Set born inf");
            printer->WriteL2(settings->getBornInf());

        }

    }

}

void SettingsMenu::setNO()
{
    printer->Clear();
    printer->WriteL1("Set NO/NC");
    printer->WriteL2(settings->getStrNormalyOpen());

    while(!button->buttonOk())
    {
        button->checkButtons();

        if(button->buttonUp() || button->buttonDown())
        {
            settings->setNO(!settings->isNO());

            printer->Clear();
            printer->WriteL1("Set NO/NC");
            printer->WriteL2(settings->getStrNormalyOpen());

        }

    }

}

void SettingsMenu::setSettings(Settings *newSettings)
{
    settings = newSettings;
  
}

Settings *SettingsMenu::getSettings()
{
    return settings;
  
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
            case 9 : printer->WriteL2(settings->getFrequency()); break;
            case 10 : printer->WriteL2(settings->getStrBorns()); break;
            case 11 : printer->WriteL2(settings->getStrNormalyOpen()); break;
            case 12 : printer->WriteL2("Go on main menu"); break;
            default : Serial.println("Error : menu functions error."); break;
            
        }

}
