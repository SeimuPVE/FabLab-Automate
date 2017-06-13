#include "WeekPlanning.h"


WeekPlanning::WeekPlanning()
{
    monday.setDayName("Monday");
    monday.setStartingTime("08h00");
    monday.setEndingTime("18h00");
    
    tuesday.setDayName("Tuesday");
    tuesday.setStartingTime("08h00");
    tuesday.setEndingTime("18h00");
    
    wednesday.setDayName("Wednesday");
    wednesday.setStartingTime("08h00");
    wednesday.setEndingTime("18h00");
    
    thursday.setDayName("Thursday");
    thursday.setStartingTime("08h00");
    thursday.setEndingTime("18h00");
    
    friday.setDayName("Friday");
    friday.setStartingTime("08h00");
    friday.setEndingTime("18h00");
    
    saturday.setDayName("Saturday");
    saturday.setStartingTime("08h00");
    saturday.setEndingTime("18h00");
    
    sunday.setDayName("Sunday");
    sunday.setStartingTime("08h00");
    sunday.setEndingTime("18h00");
    
}

void WeekPlanning::setDayStartingTime(int dayTag, String startingTime)
{
    switch(dayTag)
    {
        case MONDAY     : monday.setStartingTime(startingTime); break;
        case TUESDAY    : tuesday.setStartingTime(startingTime); break;
        case WEDNESDAY  : wednesday.setStartingTime(startingTime); break;
        case THURSDAY   : thursday.setStartingTime(startingTime); break;
        case FRIDAY     : friday.setStartingTime(startingTime); break;
        case SATURDAY   : saturday.setStartingTime(startingTime); break;
        case SUNDAY     : sunday.setStartingTime(startingTime); break;
        default         : Serial.println("Error : day not found."); break;
      
    }
  
}

void WeekPlanning::setDayEndingTime(int dayTag, String endingTime)
{
    switch(dayTag)
    {
        case MONDAY     : monday.setEndingTime(endingTime); break;
        case TUESDAY    : tuesday.setEndingTime(endingTime); break;
        case WEDNESDAY  : wednesday.setEndingTime(endingTime); break;
        case THURSDAY   : thursday.setEndingTime(endingTime); break;
        case FRIDAY     : friday.setEndingTime(endingTime); break;
        case SATURDAY   : saturday.setEndingTime(endingTime); break;
        case SUNDAY     : sunday.setEndingTime(endingTime); break;
        default         : Serial.println("Error : day not found."); break;
      
    }
  
}

void WeekPlanning::setAllStartingTime(String startingTime)
{
    for(int i = MONDAY; i <= SUNDAY; i++)
        setDayStartingTime(i, startingTime);
  
}

void WeekPlanning::setAllEndingTime(String endingTime)
{
    for(int i = MONDAY; i <= SUNDAY; i++)
        setDayEndingTime(i, endingTime);
  
}

void WeekPlanning::setDay(int dayTag, String startingHour, String endingHour)
{
    setDayStartingTime(dayTag, startingHour);
    setDayEndingTime(dayTag, endingHour);
  
}

void WeekPlanning::setAll(String startingHour, String endingHour)
{
    for(int i = MONDAY; i <= SUNDAY; i++)
        setDay(i, startingHour, endingHour);
  
}

DayPlanning WeekPlanning::getDay(int dayTag)
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

void WeekPlanning::printPlanning()
{
    monday.printDay();
    Serial.println();

    tuesday.printDay();
    Serial.println();

    wednesday.printDay();
    Serial.println();

    thursday.printDay();
    Serial.println();

    friday.printDay();
    Serial.println();

    saturday.printDay();
    Serial.println();

    sunday.printDay();

}

