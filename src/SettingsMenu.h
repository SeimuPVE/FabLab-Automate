#ifndef SETTINGSMENU
#define SETTINGSMENU

#include "Arduino.h"
#include "Time.h"
#include "MenuCreator.h"
#include "Settings.h"
#include "WeekPlanning.h"
#include "DaysMenu.h"

#define TITLE_DAYS_MENU "Planning"
#define TITLE_CONTINUE "Continue"
#define TITLE_BORNS "Borns"
#define TITLE_NO "NO/NC"

#define LABEL_SET_DAYS "Configure days"

#define SELECTOR_CONTINUE "Set continue"
#define SELECTOR_IS_CONTINUE "Continue"
#define SELECTOR_IS_PONCTUAL "Ponctual"
#define SELECTOR_FREQUENCY "Calculs by H"
#define SELECTOR_INTERVAL "Delay in seconds"
#define SELECTOR_SAMPLE_SIZE "Sample size"
#define SELECTOR_BORN_SUP "Born sup"
#define SELECTOR_BORN_INF "Born inf"
#define SELECTOR_NO "Set NO/NC"
#define SELECTOR_IS_NO "Normaly open"
#define SELECTOR_IS_NC "Normaly close"


/**
 * Settings menu.
 */
class SettingsMenu : public MenuCreator
{
    private:
        Settings *settings;
        DaysMenu *daysMenu;

    public:
        /**
         * Constructor.
         * @param printer : way to print information.
         * @param newButton : button to navigate in the menu.
         * @param settings : settings to change.
         */
        SettingsMenu(Printer *printer, Button *newButton, Settings *settings);

        /**
         * Connect all functions to the menu.
         * @param choice : your choice of function to launch.
         */
        void menuFunctions(unsigned int choice);

        void setDays();

        /**
         * Function to set the setting continue or ponctual on the menu.
         */
        void setContinue();
        /**
         * Function to set the borns on the menu.
         */
        void setBorns();
        /**
         * Function to set if the relay is normaly open or normaly close in the menu.
         */
        void setNO();

        /**
         * Change the settings to work with.
         * @param newSettings : new settings.
         */
        void setSettings(Settings *newSettings);

        /**
         * Print the label of the current choice.
         */
        void printLabel();

};

#endif
