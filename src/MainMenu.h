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

#define LABEL_CURRENT_MESURE "Current mesure"


/**
 * Main menu of this program.
 */
class MainMenu : public MenuCreator
{
    private:
        Sensors *sensors;
        SettingsMenu *settingsMenu;

    public:
        /**
         * Constructor.
         * @param newPrinter : way to print information.
         * @param newButton : button to navigate in the menu.
         */
        MainMenu(Printer *printer, Button *newButton);
        /**
         * Destructor.
         */
        ~MainMenu();

        /**
         * Connect all functions to the menu.
         * @param choice : your choice of function to launch.
         */
        void menuFunctions(unsigned int choice);

        /**
         * Use the normal mode in function of the settings.
         */
        void modeNormal();
        /**
         * Use the measure mode. Simply print the current measure on the screen.
         */
        void modeMesure();
        /**
         * Use the test mode in function of the settings.
         */
        void modeTest();
        /**
         * Go on the settings menu.
         */
        void modeSettings();

        /**
         * Print the label of the current choice.
         */
        void printLabel();

};

#endif
