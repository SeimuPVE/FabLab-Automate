#include "MainMenu.h"


MainMenu::MainMenu() : MenuCreator()
{
    int listSize = 4;
    String titleList[] = {"Start", "Mesure mode", "Test mode", "Settings"};
    String labelList[] = {"Click to enter", "Click to enter", "Click to enter", "Click to enter"};
            
    setTitles(titleList, listSize);
    setLabels(labelList, listSize);
  
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
    Serial.println("Execute normal mode");
    
}

void MainMenu::modeMesure()
{
    Serial.println("Execute mesure mode");
  
}

void MainMenu::modeTest()
{
    Serial.println("Execute mode test");
  
}

void MainMenu::modeSettings()
{
    Serial.println("Execute settings");
  
}

