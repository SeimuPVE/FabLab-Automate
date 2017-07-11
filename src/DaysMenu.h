#ifndef DAYSMENU
#define DAYSMENU

#include "Arduino.h"
#include "Time.h"
#include "MenuCreator.h"
#include "Settings.h"
#include "WeekPlanning.h"

#define TITLE_DATE "Set date"

#define SELECTOR_STARTING_HOUR "Starting hour"
#define SELECTOR_STARTING_MINUTE "Starting minute"
#define SELECTOR_ENDING_HOUR "Ending hour"
#define SELECTOR_ENDING_MINUTE "Ending minute"
#define SELECTOR_HOUR "Hour"
#define SELECTOR_MINUTE "Minute"
#define SELECTOR_DAY "Day"
#define SELECTOR_MONTH "Month"
#define SELECTOR_YEAR "Year"


/**
 * Settings menu.
 */
class DaysMenu : public MenuCreator
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
    DaysMenu(Printer *printer, Button *newButton, Settings *settings);

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
