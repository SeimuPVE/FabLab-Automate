#ifndef SETTINGS
#define SETTINGS

#include "WeekPlanning.h"


class Settings
{
    private:
        WeekPlanning planning;
        // DateTime dateTime; // Add it later with RTC module.
        bool ponctual;
        int numberCounts;
        int averageTime;
        double bornSup;
        double bornInf;
        bool NO;

    public:
        Settings();

        WeekPlanning getPlanning();
        bool isPonctual();
        int getNumberCounts();
        int getAverageTime();
        double getBornSup();
        double getBornInf();
        bool getNO();

        void setPonctual(bool newPonctual);
        void setNumberCounts(int newNumberCounts);
        void setAverageTime(int newAverageTime);
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
        String getStrPonctuality();
        String getStrFrequency();
        String getStrBorns();
        String getStrNO();
  
};

#endif

