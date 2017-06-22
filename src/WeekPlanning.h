#ifndef WEEKPLANNING
#define WEEKPLANNING

#include "SaverLoader.h"
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
        DayPlanning *monday;
        DayPlanning *tuesday;
        DayPlanning *wednesday;
        DayPlanning *thursday;
        DayPlanning *friday;
        DayPlanning *saturday;
        DayPlanning *sunday;

    public:
        WeekPlanning();

        DayPlanning *getDay(unsigned int dayTag);
        void save(unsigned int addr);
        void load(unsigned int addr);

};

#endif

