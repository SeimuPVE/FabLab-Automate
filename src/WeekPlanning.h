#ifndef WEEKPLANNING
#define WEEKPLANNING

#include "DayPlanning.h"

#define MONDAY 0
#define TUESDAY 1
#define WEDNESDAY 2
#define THURSDAY 3
#define FRIDAY 4
#define SATURDAY 5
#define SUNDAY 6


class WeekPlanning
{
    private:
        DayPlanning monday;
        DayPlanning tuesday;
        DayPlanning wednesday;
        DayPlanning thursday;
        DayPlanning friday;
        DayPlanning saturday;
        DayPlanning sunday;

    public:
        WeekPlanning();

        void setDayStartingTime(int dayTag, String startingTime);
        void setDayEndingTime(int dayTag, String endingTime);
        void setAllStartingTime(String startingTime);
        void setAllEndingTime(String endingTime);
        
        void setDay(int dayTag, String startingHour, String endingHour);
        void setAll(String startingHour, String endingHour);

        DayPlanning getDay(int dayTag);
  
};

#endif

