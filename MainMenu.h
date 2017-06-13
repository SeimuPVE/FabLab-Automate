#ifndef MAINMENU
#define MAINMENU

#include "Arduino.h"
#include "MenuCreator.h"
#include "Sensors.h"
#include "SettingsMenu.h"


class MainMenu : public MenuCreator
{
    private:
        Sensors sensors;
        SettingsMenu settingsMenu;

    public:
        MainMenu();
        
        void menuFunctions(int choice);
        
        void modeNormal();
        void modeMesure();
        void modeTest();
        void modeSettings();

        void printLabel();
  
};

#endif

