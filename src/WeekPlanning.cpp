#include "WeekPlanning.h"


WeekPlanning::WeekPlanning()
{
    monday = new DayPlanning("Monday", "08h00", "18h00");
    tuesday = new DayPlanning("Tuesday", "08h00", "18h00");
    wednesday = new DayPlanning("Wednesday", "08h00", "18h00");
    thursday = new DayPlanning("Thursday", "08h00", "18h00");
    friday = new DayPlanning("Friday", "08h00", "18h00");
    saturday = new DayPlanning("Saturday", "08h00", "18h00");
    sunday = new DayPlanning("Sunday", "08h00", "18h00");

}

DayPlanning *WeekPlanning::getDay(int dayTag)
{
    switch(dayTag)
    {
        case MONDAY     : return monday; break;
        case TUESDAY    : return tuesday; break;
        case WEDNESDAY  : return wednesday; break;
        case THURSDAY   : return thursday; break;
        case FRIDAY     : return friday; break;
        case SATURDAY   : return saturday; break;
        case SUNDAY     : return sunday; break;
        default         : Serial.println("Error : day not found."); break;
      
    }    
  
}

void WeekPlanning::save(int addr)
{
    int planning_size = 7;
    DayPlanning *days[] = {monday, tuesday, wednesday, thursday, friday, saturday, sunday};

    for(int i = 0; i < planning_size; i++)
    {
        SaverLoader::saveInt((addr + i) * sizeof(int) * 1, days[i]->getStartingHour());
        SaverLoader::saveInt((addr + i) * sizeof(int) * 2, days[i]->getStartingMinute());
        SaverLoader::saveInt((addr + i) * sizeof(int) * 3, days[i]->getEndingHour());
        SaverLoader::saveInt((addr + i) * sizeof(int) * 4, days[i]->getEndingMinute());

    }

}

void WeekPlanning::load(int addr)
{
    int planning_size = 7;
    DayPlanning *days[] = {monday, tuesday, wednesday, thursday, friday, saturday, sunday};

    for(int i = 0; i < planning_size; i++)
    {
        days[i]->setStartingHour(SaverLoader::loadInt((addr + i) * sizeof(int)));
        days[i]->setStartingMinute(SaverLoader::loadInt((addr + i) * sizeof(int) * 2));
        days[i]->setEndingHour(SaverLoader::loadInt((addr + i) * sizeof(int)) * 3);
        days[i]->setEndingMinute(SaverLoader::loadInt((addr + i) * sizeof(int)) * 4);

    }

}
