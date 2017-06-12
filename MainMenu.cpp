#include "ModesExecutor.h"


void setupMainMenu()
{
    int listSize = 4;
    String titleList[] = {"Start", "Mesure mode", "Test mode", "Settings"};
            
    MenuCreator *menu = new MenuCreator(titleList, listSize, modeMainMenu);
    menu->launchMenu();
  
}

void modeMainMenu(int choice)
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

void modeNormal(void)
{
    Serial.println("Execute normal mode");
    
}

void modeMesure()
{
    Serial.println("Execute mesure mode");
  
}

void modeTest()
{
    Serial.println("Execute mode test");
  
}

void modeSettings()
{
    Serial.println("Execute settings");
  
}

