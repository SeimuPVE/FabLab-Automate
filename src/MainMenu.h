#ifndef MAINMENU
#define MAINMENU

#include "Arduino.h"
#include "MenuCreator.h"
#include "Sensors.h"
#include "SettingsMenu.h"
#include "Printer.h"


class MainMenu : public MenuCreator
{
    private:
        Sensors *sensors;
        SettingsMenu *settingsMenu;

    public:
        MainMenu(Printer *printer, Button *newButton);
        
        void menuFunctions(int choice);

        void modeNormal();
        void modeMesure();
        void modeTest();
        void modeSettings();

        void printLabel();

        void preparePonctualMode();
        void ponctualMode();
  
};

#endif
