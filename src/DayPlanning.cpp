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

unsigned int DayPlanning::getStartingHour() const
{
    return startingHour;
    
}

unsigned int DayPlanning::getStartingMinute() const
{
    return startingMinute;
    
}

unsigned int DayPlanning::getEndingHour() const
{
    return endingHour;
    
}

unsigned int DayPlanning::getEndingMinute() const
{
    return endingMinute;

}


void DayPlanning::setDayName(String newDayName)
{
    dayName = newDayName;
  
}

void DayPlanning::setStartingHour(unsigned int newStartingHour)
{
    startingHour = newStartingHour;
    
}

void DayPlanning::setStartingMinute(unsigned int newStartingMinute)
{
    startingMinute = newStartingMinute;
  
}

void DayPlanning::setEndingHour(unsigned int newEndingHour)
{
    endingHour = newEndingHour;
  
}

void DayPlanning::setEndingMinute(unsigned int newEndingMinute)
{
    endingMinute = newEndingMinute;
  
}

String DayPlanning::getStartingTime()
{
    String startingTime = "";
    
    if(getStartingHour() < 10)
    {
        startingTime.concat('0');
        startingTime.concat(getStartingHour());

    }
    else
    {
        startingTime.concat(getStartingHour()/10);
        startingTime.concat(getStartingHour()%10);
      
    }

    startingTime += 'h';

    if(getStartingMinute() < 10)
    {
        startingTime.concat('0');
        startingTime.concat((char)(getStartingMinute() + '0'));
      
    }
    else
    {
        startingTime.concat((char)(getStartingMinute()/10 + '0'));
        startingTime.concat((char)(getStartingMinute()%10 + '0'));
      
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

unsigned int DayPlanning::getHours(String timer) const
{
    unsigned int hours = 0;

    hours += (timer.charAt(0) - '0') * 10;
    hours += (timer.charAt(1) - '0') + 0;

    return hours;
  
}

unsigned int DayPlanning::getMinutes(String timer) const
{
    unsigned int minutes = 0;

    minutes += (timer.charAt(3) - '0') * 10;
    minutes += (timer.charAt(4) - '0') + 0;

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
