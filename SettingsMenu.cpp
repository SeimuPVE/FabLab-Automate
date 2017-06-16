#include "SettingsMenu.h"


SettingsMenu::SettingsMenu(Printer *printer, Settings *newSettings) : MenuCreator(printer)
{
    setSettings(newSettings);
    
    int listSize = 13;
    String titleList[] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday", "Current date", "Continue", "Frequency", "Borns", "NO", "Exit"};
            
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
    printer->WriteL1("Set ponctual");

    printer->WriteL2("(to add)", 8);
    
    for(int i = 0; i < 3; i++)
    {
        printer->WriteL2(".", i);
        delay(1000);
        
    }

}

void SettingsMenu::setFrequency()
{
    printer->Clear();
    printer->WriteL2("Set frequency");

    printer->WriteL2("(to add)", 8);
    
    for(int i = 0; i < 3; i++)
    {
        printer->WriteL2(".", i);
        delay(1000);
        
    }

}

void SettingsMenu::setBorns()
{
    printer->Clear();
    printer->WriteL2("Set borns");

    printer->WriteL2("(to add)", 8);
    
    for(int i = 0; i < 3; i++)
    {
        printer->WriteL2(".", i);
        delay(1000);
        
    }

}

void SettingsMenu::setNO()
{
    printer->Clear();
    printer->WriteL2("Set NO");

    printer->WriteL2("(to add)", 8);
    
    for(int i = 0; i < 3; i++)
    {
        printer->WriteL2(".", i);
        delay(1000);
        
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
            case 7 : printer->WriteL2(settings->getStrCurrentDate()); break;
            case 8 : printer->WriteL2(settings->getStrPonctuality()); break;
            case 9 : printer->WriteL2(settings->getStrFrequency()); break;
            case 10 : printer->WriteL2(settings->getStrBorns()); break;
            case 11 : printer->WriteL2(settings->getStrNO()); break;
            case 12 : printer->WriteL2("Go on main menu"); break;
            default : Serial.println("Error : menu functions error."); break;
            
        }
  
}

