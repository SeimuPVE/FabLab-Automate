#ifndef SETTINGS
#define SETTINGS

#include <Time.h>

#include "SaverLoader.h"
#include "WeekPlanning.h"

#define SEPARATOR ":"

#define LABEL_IS_CONTINUE "Continue"
#define LABEL_IS_PONCTUAL "Ponctual"
#define LABEL_IS_NO "Normaly open"
#define LABEL_IS_NC "Normaly close"


class Settings
{
    private:
        WeekPlanning *planning;
        time_t dateTime;
        bool iContinue; // TODO : rename it.
        unsigned int frequency;
        unsigned int interval;
        unsigned int sample_size;
        unsigned int bornSup;
        unsigned int bornInf;
        bool normalyOpen;

    public:
        Settings();
        ~Settings();

        WeekPlanning *getPlanning() const;
        time_t getDateTime() const;
        bool isContinue() const;
        unsigned int getFrequency() const;
        unsigned int getInterval() const;
        unsigned int getSample_size() const;
        unsigned int getBornSup() const;
        unsigned int getBornInf() const;
        bool isNO() const;

        void setDateTime(unsigned int hour, unsigned int minute, unsigned int day, unsigned int month, unsigned int year);
        void setContinue(bool newContinue);
        void setFrequency(unsigned int newNumberCounts);
        void setInterval(unsigned int interval);
        void setSample_size(unsigned int sample_size);
        void setBornSup(unsigned int newBornSup);
        void setBornInf(unsigned int newBornInf);
        void setNO(bool newNO);

        void setDay(unsigned int dayTag, unsigned int startingHour, unsigned int startingMinute, unsigned int endingHour, unsigned int endingMinute);

        String getStrDay(unsigned int dayTag);
        String getStrCurrentDate();
        String getStrIsContinue();
        String getStrBorns();
        String getStrNormalyOpen();

        void save();
        void load();

};

#endif
