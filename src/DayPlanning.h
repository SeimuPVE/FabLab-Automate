#ifndef DAYPLANNING
#define DAYPLANNING

#include "Arduino.h"
#include "Printer.h"

class DayPlanning
{
    private:
        String dayName;
        unsigned int startingHour;
        unsigned int startingMinute;
        unsigned int endingHour;
        unsigned int endingMinute;

    public:
        DayPlanning();
        DayPlanning(String newDayName, String newStartingTime, String newEndingTime);

        String getDayName();
        unsigned int getStartingHour() const;
        unsigned int getStartingMinute() const;
        unsigned int getEndingHour() const;
        unsigned int getEndingMinute() const;

        void setDayName(String newDayName);
        void setStartingHour(unsigned int newStartingHour);
        void setStartingMinute(unsigned int newStartingMinute);
        void setEndingHour(unsigned int newEndingHour);
        void setEndingMinute(unsigned int newEndingMinute);

        String getStartingTime();
        String getEndingTime();

        bool isValidTimer(String timer);
        unsigned int getHours(String timer);
        unsigned int getMinutes(String timer);

        void setStartingTime(String timer);
        void setEndingTime(String timer);
  
};

#endif

