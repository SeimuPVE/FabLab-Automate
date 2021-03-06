#include "WeekPlanning.h"


WeekPlanning::WeekPlanning()
{
    monday = new DayPlanning(F(LABEL_MONDAY), "08h00", "18h00");
    tuesday = new DayPlanning(F(LABEL_TUESDAY), "08h00", "18h00");
    wednesday = new DayPlanning(F(LABEL_WEDNESDAY), "08h00", "18h00");
    thursday = new DayPlanning(F(LABEL_THURSDAY), "08h00", "18h00");
    friday = new DayPlanning(F(LABEL_FRIDAY), "08h00", "18h00");
    saturday = new DayPlanning(F(LABEL_SATURDAY), "08h00", "18h00");
    sunday = new DayPlanning(F(LABEL_SUNDAY), "08h00", "18h00");

}

WeekPlanning::~WeekPlanning()
{
    delete monday;
    delete tuesday;
    delete wednesday;
    delete thursday;
    delete friday;
    delete saturday;
    delete sunday;

}

DayPlanning *WeekPlanning::getDay(unsigned int dayTag)
{
    switch(dayTag)
    {
        case MONDAY     : return monday;
        case TUESDAY    : return tuesday;
        case WEDNESDAY  : return wednesday;
        case THURSDAY   : return thursday;
        case FRIDAY     : return friday;
        case SATURDAY   : return saturday;
        case SUNDAY     : return sunday;
        default         : Serial.println("Error : day not found."); return NULL;
      
    }    
  
}

void WeekPlanning::save(unsigned int address)
{
    int planning_size = 7;
    DayPlanning *days[] = {monday, tuesday, wednesday, thursday, friday, saturday, sunday};

    for(int i = 0; i < planning_size; i++)
    {
        SaverLoader::saveUnsignedInt(address + 0 + (i * 4 * sizeof(unsigned int)), days[i]->getStartingHour());
        SaverLoader::saveUnsignedInt(address + 2 + (i * 4 * sizeof(unsigned int)), days[i]->getStartingMinute());
        SaverLoader::saveUnsignedInt(address + 4 + (i * 4 * sizeof(unsigned int)), days[i]->getEndingHour());
        SaverLoader::saveUnsignedInt(address + 6 + (i * 4 * sizeof(unsigned int)), days[i]->getEndingMinute());

    }

}

void WeekPlanning::load(unsigned int address)
{
    unsigned int planning_size = 7;
    DayPlanning *days[] = {monday, tuesday, wednesday, thursday, friday, saturday, sunday};

    for(unsigned int i = 0; i < planning_size; i++)
    {
        days[i]->setStartingHour(  SaverLoader::loadUnsignedInt(address + 0 + (i * 4 * sizeof(unsigned int))));
        days[i]->setStartingMinute(SaverLoader::loadUnsignedInt(address + 2 + (i * 4 * sizeof(unsigned int))));
        days[i]->setEndingHour(    SaverLoader::loadUnsignedInt(address + 4 + (i * 4 * sizeof(unsigned int))));
        days[i]->setEndingMinute(  SaverLoader::loadUnsignedInt(address + 6 + (i * 4 * sizeof(unsigned int))));

    }

}
