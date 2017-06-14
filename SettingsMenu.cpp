#include "SettingsMenu.h"


SettingsMenu::SettingsMenu() : MenuCreator()
{
    int listSize = 13;
    String titleList[] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday", "Current date", "Ponctual/Continue", "Frequency", "Borns", "NO", "Exit"};
            
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
    Printer::Write("Set day ");

}

void SettingsMenu::setMonday()
{
    setDay(MONDAY);
    Printer::Write("monday");
    Printer::ReturnLine();

}

void SettingsMenu::setTuesday()
{
    setDay(TUESDAY);
    Printer::Write("tuesday");
    Printer::ReturnLine();
  
}

void SettingsMenu::setWednesday()
{
    setDay(WEDNESDAY);
    Printer::Write("wednesday");
    Printer::ReturnLine();
  
}

void SettingsMenu::setThursday()
{
    setDay(THURSDAY);
    Printer::Write("thursday");
    Printer::ReturnLine();
  
}

void SettingsMenu::setFriday()
{
    setDay(FRIDAY);
    Printer::Write("friday");
    Printer::ReturnLine();
  
}

void SettingsMenu::setSaturday()
{
    setDay(SATURDAY);
    Printer::Write("saturday");
    Printer::ReturnLine();
  
}

void SettingsMenu::setSunday()
{
    setDay(SUNDAY);
    Printer::Write("sunday");
    Printer::ReturnLine();
  
}

void SettingsMenu::setDate()
{
    Printer::Write("Set date");
    Printer::ReturnLine();
  
}

void SettingsMenu::setPonctual()
{
    Printer::Write("Set ponctual");
    Printer::ReturnLine();
  
}

void SettingsMenu::setFrequency()
{
    Printer::Write("Set frequency");
    Printer::ReturnLine();
  
}

void SettingsMenu::setBorns()
{
    Printer::Write("Set borns");
    Printer::ReturnLine();
  
}

void SettingsMenu::setNO()
{
    Printer::Write("Set NO");
    Printer::ReturnLine();
  
}

void SettingsMenu::setSettings(Settings newSettings)
{
    settings = newSettings;
  
}

Settings SettingsMenu::getSettings()
{
    return settings;
  
}

void SettingsMenu::printLabel()
{
    if(currentChoice >= MONDAY && currentChoice <= SUNDAY)
        settings.printDay(currentChoice);
    else
        switch(currentChoice)
        {
            case 7 : settings.printCurrentDate(); break;
            case 8 : settings.printPonctuality(); break;
            case 9 : settings.printFrequency(); break;
            case 10 : settings.printBorns(); break;
            case 11 : settings.printNO(); break;
            case 12 : Serial.print("Click to return on main menu"); break;
            default : Serial.println("Error : menu functions error."); break;
            
        }
  
}

