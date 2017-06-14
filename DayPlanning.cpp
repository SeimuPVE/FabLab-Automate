#include "DayPlanning.h"


DayPlanning::DayPlanning()
{
    setDayName("Unknown");
    setStartingTime("00h00");
    setEndingTime("00h00");
  
}

DayPlanning::DayPlanning(String newDayName, String newStartingTime, String newEndingTime)
{
    setDayName(newDayName);

    if(isValidTimer(newStartingTime))
        setStartingTime(newStartingTime);
    else
        Serial.println("Error");

    if(isValidTimer(newEndingTime))
        setEndingTime(newEndingTime);
    else
        Serial.println("Error");

}

String DayPlanning::getDayName()
{
    return dayName;
    
}

int DayPlanning::getStartingHour()
{
    return startingHour;
    
}

int DayPlanning::getStartingMinute()
{
    return startingMinute;
    
}

int DayPlanning::getEndingHour()
{
    return endingHour;
    
}

int DayPlanning::getEndingMinute()
{
    return endingMinute;
}


void DayPlanning::setDayName(String newDayName)
{
    dayName = newDayName;
  
}

void DayPlanning::setStartingHour(int newStartingHour)
{
    startingHour = newStartingHour;
    
}

void DayPlanning::setStartingMinute(int newStartingMinute)
{
    startingMinute = newStartingMinute;
  
}

void DayPlanning::setEndingHour(int newEndingHour)
{
    endingHour = newEndingHour;
  
}

void DayPlanning::setEndingMinute(int newEndingMinute)
{
    endingMinute = newEndingMinute;
  
}

String DayPlanning::getStartingTime()
{
    String startingTime = "";

    if(getStartingHour() < 10)
    {
        startingTime += '0';
        startingTime += (char)(getStartingHour() + '0');
      
    }
    else
    {
        startingTime += (char)(getStartingHour()/10 + '0');
        startingTime += getStartingHour()%10;
      
    }

    startingTime += "h";

    if(getStartingMinute() < 10)
    {
        startingTime += '0';
        startingTime += (char)(getStartingMinute() + '0');
      
    }
    else
    {
        startingTime += (char)(getStartingMinute()/10 + '0');
        startingTime += getStartingMinute()%10;
      
    }

    return startingTime;
  
}

String DayPlanning::getEndingTime()
{
    String endingTime = "";

    if(getEndingHour() < 10)
    {
        endingTime += '0';
        endingTime += (char)(getEndingHour() + '0');
      
    }
    else
    {
        endingTime += (char)(getEndingHour()/10 + '0');
        endingTime += getEndingHour()%10;
      
    }

    endingTime += "h";

    if(getEndingMinute() < 10)
    {
        endingTime += '0';
        endingTime += (char)(getEndingMinute() + '0');
      
    }
    else
    {
        endingTime += (char)(getEndingMinute()/10 + '0');
        endingTime += getEndingMinute()%10;
      
    }

    return endingTime;
  
}

bool DayPlanning::isValidTimer(String timer)
{
    if(timer.length() != 5)
        return false;

    if(timer[2] != 'h')
        return false;
         
    for(int i = 0; i < 5; i++)
        if((i != 2) && ((timer[i] < '0') || (timer[i] > '9')))
            return false;

    return true;
  
}

int DayPlanning::getHours(String timer)
{
    int hours = 0;

    hours += (timer[0] - '0') * 10;
    hours += (timer[1] - '0');

    return hours;
  
}

int DayPlanning::getMinutes(String timer)
{
    int minutes = 0;

    minutes += (timer[3] - '0') * 10;
    minutes += (timer[4] - '0');

    return minutes;
  
}

void DayPlanning::setStartingTime(String timer)
{
    setStartingHour(getHours(timer));
    setStartingMinute(getMinutes(timer));
  
}

void DayPlanning::setEndingTime(String timer)
{
    setEndingHour(getHours(timer));
    setEndingMinute(getMinutes(timer));

}

