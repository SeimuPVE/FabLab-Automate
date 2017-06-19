#ifndef SETTINGS
#define SETTINGS

#include <Time.h>

#include "WeekPlanning.h"


class Settings
{
    private:
        WeekPlanning planning;
        time_t dateTime;
        bool iContinue; // TODO : rename it.
        int frequency;
        double bornSup;
        double bornInf;
        bool NormalyOpen;

    public:
        Settings();

        WeekPlanning getPlanning();
        bool isContinue();
        int getFrequency();
        double getBornSup();
        double getBornInf();
        bool isNO();

        void setContinue(bool newPonctual);
        void setFrequency(int newNumberCounts);
        void setBornSup(double newBornSup);
        void setBornInf(double newBornInf);
        void setNO(bool newNO);

        void setDayStartingTime(int dayTag, String startingTime);
        void setDayEndingTime(int dayTag, String endingTime);
        void setAllStartingTime(String startingTime);
        void setAllEndingTime(String endingTime);
        
        void setDay(int dayTag, String startingHour, String endingHour);
        void setAll(String startingHour, String endingHour);

        String getStrDay(int dayTag);
        String getStrCurrentDate();
        String getStrIsContinue();
        String writeFrequency();
        String getStrBorns();
        String getStrNormalyOpen();

};

#endif
