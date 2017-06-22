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

#define LABEL_MONDAY "Monday"
#define LABEL_TUESDAY "Tuesday"
#define LABEL_WEDNESDAY "Wednesday"
#define LABEL_THURSDAY "Thursday"
#define LABEL_FRIDAY "Friday"
#define LABEL_SATURDAY "Saturday"
#define LABEL_SUNDAY "Sunday"

#define LABEL_SHORT_MONDAY "MON"
#define LABEL_SHORT_TUESDAY "TUE"
#define LABEL_SHORT_WEDNESDAY "WED"
#define LABEL_SHORT_THURSDAY "THU"
#define LABEL_SHORT_FRIDAY "FRI"
#define LABEL_SHORT_SATURDAY "SAT"
#define LABEL_SHORT_SUNDAY "SUN"


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
