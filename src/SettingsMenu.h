#ifndef SETTINGSMENU
#define SETTINGSMENU

#include "Arduino.h"
#include "Time.h"
#include "MenuCreator.h"
#include "Settings.h"
#include "WeekPlanning.h"

#define TITLE_DATE "Date"
#define TITLE_CONTINUE "Continue"
#define TITLE_BORNS "Borns"
#define TITLE_NO "NO/NC"
#define TITLE_EXIT "Exit"

#define SELECTOR_STARTING_HOUR "Start H"
#define SELECTOR_STARTING_MINUTE "Start min"
#define SELECTOR_ENDING_HOUR "End H"
#define SELECTOR_ENDING_MINUTE "End min"
#define SELECTOR_HOUR "Select H"
#define SELECTOR_MINUTE "Select min"
#define SELECTOR_DAY "Select day"
#define SELECTOR_MONTH "Select month"
#define SELECTOR_YEAR "Select year"

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

#define LABEL_GO_BACK "Go back"


/**
 * Settings menu.
 */
class SettingsMenu : public MenuCreator
{
    private:
        Settings *settings;

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
         * Function to set a day on the menu.
         * @param dayTag : tag of the selected day.
         */
        void setDay(unsigned int dayTag);

        /**
         * Function to set the monday on the menu.
         */
        void setMonday();
        /**
         * Function to set the tuesday on the menu.
         */
        void setTuesday();
        /**
         * Function to set the wednesday on the menu.
         */
        void setWednesday();
        /**
         * Function to set the thursday on the menu.
         */
        void setThursday();
        /**
         * Function to set the friday on the menu.
         */
        void setFriday();
        /**
         * Function to set the saturday on the menu.
         */
        void setSaturday();
        /**
         * Function to set the sunday on the menu.
         */
        void setSunday();

        /**
         * Function to set the current date on the menu.
         */
        void setDate();
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
         * Select a value in a given interval.
         * @param label : label to print on the first line of the screen.
         * @param super_incrementor : true if you want a progressive incrementor, false if you want it fixe.
         * @param initialValue : initiale value printed.
         * @param inf : minimal value in the interval.
         * @param sup : maximal value in the interval.
         * @return : value selected.
         */
        unsigned int selectBetweenInterval(String label, bool super_incrementor, unsigned int initialValue, unsigned int inf = 0, unsigned int sup = 999);
        /**
         * Select a boolean in the menu.
         * @param label : label to print on the first line of the screen.
         * @param trueLabel : label to print if the value is true.
         * @param falseLabel : label to print if the value is false.
         * @param initialValue : initiale value to print.
         * @return : value selected.
         */
        bool selectBoolean(String label, String trueLabel, String falseLabel, bool initialValue);

        /**
         * Print the label of the current choice.
         */
        void printLabel();

};

#endif
