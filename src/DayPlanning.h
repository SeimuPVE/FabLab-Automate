#ifndef DAYPLANNING
#define DAYPLANNING

#include "Arduino.h"
#include "Printer.h"

class DayPlanning
{
    private:
        String dayName;
        int startingHour;
        int startingMinute;
        int endingHour;
        int endingMinute;

    public:
        DayPlanning();
        DayPlanning(String newDayName, String newStartingTime, String newEndingTime);

        // TODO : Check that.
//        String getDayName();
        int getStartingHour();
        int getStartingMinute();
        int getEndingHour();
        int getEndingMinute();

        void setDayName(String newDayName);
        void setStartingHour(int newStartingHour);
        void setStartingMinute(int newStartingMinute);
        void setEndingHour(int newEndingHour);
        void setEndingMinute(int newEndingMinute);

        String getStartingTime();
        String getEndingTime();

        bool isValidTimer(String timer);
        int getHours(String timer);
        int getMinutes(String timer);

        void setStartingTime(String timer);
        void setEndingTime(String timer);
  
};

#endif

