#ifndef SETTINGS
#define SETTINGS

#include <Time.h>

#include "WeekPlanning.h"


class Settings
{
    private:
        WeekPlanning *planning = new WeekPlanning;
        time_t dateTime;
        bool iContinue; // TODO : rename it.
        int frequency;
        int interval;
        int sample_size;

private:
    int bornSup;
        int bornInf;
        bool normalyOpen;

    public:
        Settings();

        WeekPlanning *getPlanning() const;
        bool isContinue() const;
        int getFrequency() const;
        int getInterval() const;
        int getSample_size() const;
        int getBornSup() const;
        int getBornInf() const;
        bool isNO() const;

        void setDateTime(int hour, int minute, int day, int month, int year);
        void setContinue(bool newContinue);
        void setFrequency(int newNumberCounts);
        void setInterval(int interval);
        void setSample_size(int sample_size);
        void setBornSup(double newBornSup);
        void setBornInf(double newBornInf);
        void setNO(bool newNO);

        void setDay(int dayTag, int startingHour, int startingMinute, int endingHour, int endingMinute);

        String getStrDay(int dayTag);
        String getStrCurrentDate();
        String getStrIsContinue();
        String getStrBorns();
        String getStrNormalyOpen();

};

#endif
