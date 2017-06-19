#include "Settings.h"

Settings::Settings()
{
    if(timeStatus() == timeNotSet)
        setTime(0, 0, 0, 0, 0, 0);
    dateTime = now();

    setContinue(true);
    setFrequency(10);
    setBornSup(500.0);
    setBornInf(400.0);
    setNO(false);

}

WeekPlanning *Settings::getPlanning()
{
    return planning;
  
}

void Settings::setDateTime(int hour, int minute, int day, int month, int year)
{
    setTime(hour, minute, 0, day, month, year);
    dateTime = now();

}

bool Settings::isContinue()
{
    return iContinue;
  
}

int Settings::getFrequency()
{
    return frequency;
  
}

int Settings::getBornSup()
{
    return bornSup;
  
}

int Settings::getBornInf()
{
    return bornInf;
  
}

bool Settings::isNO()
{
    return normalyOpen;
  
}

void Settings::setContinue(bool newContinue)
{
    iContinue = newContinue;
  
}

void Settings::setFrequency(int newNumberCounts)
{
    frequency = newNumberCounts;
  
}

void Settings::setBornSup(double newBornSup)
{
    bornSup = newBornSup;
  
}

void Settings::setBornInf(double newBornInf)
{
    bornInf = newBornInf;
  
}

void Settings::setNO(bool newNO)
{
    normalyOpen = newNO;

}

/*void Settings::setDayStartingTime(int dayTag, String startingTime)
{
    planning->setDayStartingTime(dayTag, startingTime);
  
}

void Settings::setDayEndingTime(int dayTag, String endingTime)
{
    planning->setDayEndingTime(dayTag, endingTime);
  
}

void Settings::setAllStartingTime(String startingTime)
{
    planning->setAllStartingTime(startingTime);

}

void Settings::setAllEndingTime(String endingTime)
{
    planning->setAllEndingTime(endingTime);
  
}

void Settings::setDay(int dayTag, String startingHour, String endingHour)
{
    planning->setDay(dayTag, startingHour, endingHour);
  
}

void Settings::setAll(String startingHour, String endingHour)
{
    planning->setAll(startingHour, endingHour);
  
}*/

String Settings::getStrDay(int dayTag)
{
    String str;
    
    str += "S:";
    str += getPlanning()->getDay(dayTag)->getStartingTime();

    str += "  E:";
    str += getPlanning()->getDay(dayTag)->getEndingTime();

    return str;
    
}

String Settings::getStrCurrentDate()
{
    String result;
    dateTime = now();

    switch(dayOfWeek(dateTime) - 1)
    {
        case 0 : result += "Sunday"; break;
        case 1 : result += "Monday"; break;
        case 2 : result += "Tuesday"; break;
        case 3 : result += "Wednesday"; break;
        case 4 : result += "Thursday"; break;
        case 5 : result += "Friday"; break;
        case 6 : result += "Saturday"; break;

    }

    result += " ";
    result += hour(dateTime);
    result += ":";
    result += minute(dateTime);

    return result;

}

String Settings::getStrIsContinue()
{
    if(iContinue)
        return "        Continue";
    return "        Ponctual";

}

String Settings::getStrFrequency()
{
    String result = "";

    result += frequency;
    result += " calculs by H";

    return result;

}

String Settings::getStrBorns()
{
    String result = "";

    result += "Inf:";
    result += bornInf;

    result += " Sup:";
    result += bornSup;

    return result;

}

String Settings::getStrNormalyOpen()
{
    if(isNO())
        return "    Normaly open";
    return "   Normaly close";

}
