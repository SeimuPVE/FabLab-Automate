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
    Serial.print("Set day ");

}

void SettingsMenu::setMonday()
{
    setDay(MONDAY);
    Serial.println("monday");

}

void SettingsMenu::setTuesday()
{
    setDay(TUESDAY);
    Serial.println("tuesday");
  
}

void SettingsMenu::setWednesday()
{
    setDay(WEDNESDAY);
    Serial.println("wednesday");
  
}

void SettingsMenu::setThursday()
{
    setDay(THURSDAY);
    Serial.println("thursday");
  
}

void SettingsMenu::setFriday()
{
    setDay(FRIDAY);
    Serial.println("friday");
  
}

void SettingsMenu::setSaturday()
{
    setDay(SATURDAY);
    Serial.println("saturday");
  
}

void SettingsMenu::setSunday()
{
    setDay(SUNDAY);
    Serial.println("sunday");
  
}

void SettingsMenu::setDate()
{
    Serial.println("Set date");
  
}

void SettingsMenu::setPonctual()
{
    Serial.println("Set ponctual");
  
}

void SettingsMenu::setFrequency()
{
    Serial.println("Set frequency");
  
}

void SettingsMenu::setBorns()
{
    Serial.println("Set borns");
  
}

void SettingsMenu::setNO()
{
    Serial.println("Set NO");
  
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
            case 12 : Serial.println("Click to return on main menu"); break;
            default : Serial.println("Error : menu functions error."); break;
            
        }
  
}

