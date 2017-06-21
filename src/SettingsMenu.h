#ifndef SETTINGSMENU
#define SETTINGSMENU

#include "Arduino.h"
#include "MenuCreator.h"
#include "Settings.h"
#include "WeekPlanning.h" // For defines. TODO : find a solution.

//#define DAY_NAME[7] = {"monday", "tuesday", "wednesday", "thursday", "friday", "saturday", "sunday"}


class SettingsMenu : public MenuCreator
{
    private:
        Settings *settings;

    public:
        SettingsMenu(Printer *printer, Button *newButton, Settings *settings);

        void menuFunctions(int choice);

        void setDay(int dayTag);

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

        int selectBetweenInterval(String label, bool super_incrementor, int initialValue, int inf = 0, int sup = 999);
        bool selectBoolean(String label, String trueLabel, String falseLabel, bool initialValue);

        void printLabel();

};

#endif
