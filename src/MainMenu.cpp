#include "MainMenu.h"


MainMenu::MainMenu(Printer *printer, Button *newButton) : MenuCreator(printer, newButton)
{
    sensors = new Sensors();
    settingsMenu = new SettingsMenu(printer, newButton, sensors->getSettings());

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
    printer->Clear();
    printer->WriteL1("Normal mode");
    printer->WriteL2("(to add)", 8);

    for(int i = 0; i < 3; i++)
    {
        printer->WriteL2(".", i);
        delay(1000);
        
    }
    
}

void MainMenu::modeMesure()
{
    printer->Clear();
    printer->WriteL1("Mesure mode");
    printer->WriteL2("(to add)", 8);

    for(int i = 0; i < 3; i++)
    {
        printer->WriteL2(".", i);
        delay(1000);
        
    }
  
}

void MainMenu::modeTest()
{
    printer->Clear();
    printer->WriteL1("Mode test");
    printer->WriteL2("(to add)", 8);

    for(int i = 0; i < 3; i++)
    {
        printer->WriteL2(".", i);
        delay(1000);
        
    }
  
}

void MainMenu::modeSettings()
{
    printer->Clear();
    settingsMenu->execute();
  
}

void MainMenu::printLabel()
{
    printer->WriteL2(titleList[(currentChoice + 1) % titleSize], 3);
  
}

