#include "MainMenu.h"


MainMenu::MainMenu() : MenuCreator()
{
    Printer::Begin();
    settingsMenu.setSettings(sensors.getSettings());
    
    int listSize = 4;
    String titleList[] = {"Start", "Mesure mode", "Test mode", "Settings"};
            
    setTitles(titleList, listSize);
  
}

void MainMenu::menuFunctions(int choice)
{
    if(choice == 0)
        modeNormal();
    else if(choice == 1)
        modeMesure();
    else if(choice == 2)
        modeTest();
    else if(choice == 3)
        modeSettings();
    else
        Serial.println("Error");
  
}

void MainMenu::modeNormal(void)
{
    Printer::Write("Execute normal mode");
    
}

void MainMenu::modeMesure()
{
    Printer::Write("Execute mesure mode");
  
}

void MainMenu::modeTest()
{
    Printer::Write("Execute mode test");
  
}

void MainMenu::modeSettings()
{
    settingsMenu.execute();
  
}

void MainMenu::printLabel()
{
    Printer::Write("   ");
    Printer::Write(titleList[(currentChoice + 1) % titleSize]);
  
}

