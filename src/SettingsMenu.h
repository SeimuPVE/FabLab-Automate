#ifndef SETTINGSMENU
#define SETTINGSMENU

#include "Arduino.h"
#include "Time.h"
#include "MenuCreator.h"
#include "Settings.h"
#include "WeekPlanning.h"
#include "DaysMenu.h"

#define TITLE_DAYS_MENU "Planning"
#define TITLE_CONTINUE "Control mode"
#define TITLE_LIMITS "Conditions"
#define TITLE_NO "Output state"
#define TITLE_CRASH_MODE "Error manager"

#define LABEL_SET_DAYS "Days and times"

#define SELECTOR_CONTINUE "Set control mode"
#define SELECTOR_IS_CONTINUE "Continue"
#define SELECTOR_IS_RECURRENT "Recurrent"
#define SELECTOR_CRASH_MODE "If error"
#define SELECTOR_IS_CRASH_MODE "Stop when error"
#define SELECTOR_IS_NOT_CRASH_MODE "Manage errors"
#define SELECTOR_FREQUENCY "Frequency on 1h"
#define SELECTOR_INTERVAL "Period (second)"
#define SELECTOR_SAMPLE_SIZE "Qty (sampling)"
#define SELECTOR_BORN_SUP "Born sup"
#define SELECTOR_BORN_INF "Born inf"
#define SELECTOR_NO "Set output state"
#define SELECTOR_IS_NO "ON"
#define SELECTOR_IS_NC "OFF"


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

        /**
         * Function to set go in the days menu.
         */
        void setDays();

        /**
         * Function to set the setting continue or recurrent on the menu.
         */
        void setContinue();

        /**
         * Function to set the setting crash mode on the menu.
         */
        void setCrashMode();

        /**
         * Function to set the limits on the menu.
         */
        void setBorns();

        /**
         * Function to set if the relay is normally open or normally close in the menu.
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
