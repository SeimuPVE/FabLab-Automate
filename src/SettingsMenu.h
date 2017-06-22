#ifndef SETTINGSMENU
#define SETTINGSMENU

#include "Arduino.h"
#include "Time.h"
#include "MenuCreator.h"
#include "Settings.h"
#include "WeekPlanning.h" // For defines. TODO : find a solution.


class SettingsMenu : public MenuCreator
{
    private:
        Settings *settings;

    public:
        SettingsMenu(Printer *printer, Button *newButton, Settings *settings);

        void menuFunctions(unsigned int choice);

        void setDay(unsigned int dayTag);

        void setMonday();
        void setTuesday();
        void setWednesday();
        void setThursday();
        void setFriday();
        void setSaturday();
        void setSunday();

        void setDate();
        void setContinue();
        void setBorns();
        void setNO();

        void setSettings(Settings *newSettings);

        unsigned int selectBetweenInterval(String label, bool super_incrementor, unsigned int initialValue, unsigned int inf = 0, unsigned int sup = 999);
        bool selectBoolean(String label, String trueLabel, String falseLabel, bool initialValue);

        void printLabel();

};

#endif
