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

DayPlanning *WeekPlanning::getDay(unsigned int dayTag)
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

void WeekPlanning::save(unsigned int addr)
{
    int planning_size = 7;
    DayPlanning *days[] = {monday, tuesday, wednesday, thursday, friday, saturday, sunday};

    for(int i = 0; i < planning_size; i++)
    {
        SaverLoader::saveUnsignedInt((addr + i) * sizeof(unsigned int) * 1, days[i]->getStartingHour());
        SaverLoader::saveUnsignedInt((addr + i) * sizeof(unsigned int) * 2, days[i]->getStartingMinute());
        SaverLoader::saveUnsignedInt((addr + i) * sizeof(unsigned int) * 3, days[i]->getEndingHour());
        SaverLoader::saveUnsignedInt((addr + i) * sizeof(unsigned int) * 4, days[i]->getEndingMinute());

    }

}

void WeekPlanning::load(unsigned int addr)
{
    unsigned int planning_size = 7;
    DayPlanning *days[] = {monday, tuesday, wednesday, thursday, friday, saturday, sunday};

    for(unsigned int i = 0; i < planning_size; i++)
    {
        days[i]->setStartingHour(SaverLoader::loadUnsignedInt((addr + i) * sizeof(unsigned int)));
        days[i]->setStartingMinute(SaverLoader::loadUnsignedInt((addr + i) * sizeof(unsigned int) * 2));
        days[i]->setEndingHour(SaverLoader::loadUnsignedInt((addr + i) * sizeof(unsigned int)) * 3);
        days[i]->setEndingMinute(SaverLoader::loadUnsignedInt((addr + i) * sizeof(unsigned int)) * 4);

    }

}
