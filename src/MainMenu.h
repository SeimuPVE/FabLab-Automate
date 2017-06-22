#ifndef MAINMENU
#define MAINMENU

#include "Arduino.h"
#include "MenuCreator.h"
#include "Sensors.h"
#include "SettingsMenu.h"
#include "Printer.h"

#define TITLE_START "Start"
#define TITLE_MESURE "Mesure"
#define TITLE_TEST "Test"
#define TITLE_SETTINGS "Settings"

#define LABEL_CURRENT_MESURE "Current mesure :"


class MainMenu : public MenuCreator
{
    private:
        Sensors *sensors;
        SettingsMenu *settingsMenu;

    public:
        MainMenu(Printer *printer, Button *newButton);
        
        void menuFunctions(unsigned int choice);

        void modeNormal();
        void modeMesure();
        void modeTest();
        void modeSettings();

        void printLabel();

};

#endif
