#ifndef SETTINGSMENU
#define SETTINGSMENU

#include "Arduino.h"
#include "MenuCreator.h"
#include "Sensors.h"
#include "WeekPlanning.h"


class SettingsMenu : public MenuCreator
{
    private:
        // Nothing.

    public:
        SettingsMenu();

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
          
};

#endif

