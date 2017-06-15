#ifndef SETTINGSMENU
#define SETTINGSMENU

#include "Arduino.h"
#include "MenuCreator.h"
#include "Settings.h"
#include "WeekPlanning.h" // For defines. TODO : find a solution.


class SettingsMenu : public MenuCreator
{
    private:
        Settings *settings;
      
    public:
        SettingsMenu(Printer *printer, Settings *settings);

        void menuFunctions(int choice);
        void updateLabels();
        
        void setDay(int dayTag);

        void setMonday();
        void setTuesday();
        void setWednesday();
        void setThursday();
        void setFriday();
        void setSaturday();
        void setSunday();

        void setDate();
        void setPonctual();
        void setFrequency();
        void setBorns();
        void setNO();

        void setSettings(Settings *newSettings);
        Settings *getSettings();

        void printLabel();
          
};

#endif

