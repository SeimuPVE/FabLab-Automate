#include "Settings.h"

Settings::Settings()
{
    if(timeStatus() == timeNotSet)
        setTime(0, 0, 0, 0, 0, 0);
    dateTime = now();
    
    setContinue(true);
    setFrequency(480); // Continue.
    setInterval(1); // Ponctual.
    setSample_size(10);
    setBornSup(200.0);
    setBornInf(0.0);
    setNO(false);

}

WeekPlanning *Settings::getPlanning() const
{
    return planning;
  
}

void Settings::setDateTime(int hour, int minute, int day, int month, int year)
{
    setTime(hour, minute, 0, day, month, year);
    dateTime = now();

}

bool Settings::isContinue() const
{
    return iContinue;
  
}

int Settings::getFrequency() const
{
    return frequency;
  
}

int Settings::getInterval() const
{
    return interval;

}

int Settings::getSample_size() const
{
    return sample_size;

}

int Settings::getBornSup() const
{
    return bornSup;
  
}

int Settings::getBornInf() const
{
    return bornInf;
  
}

bool Settings::isNO() const
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

void Settings::setInterval(int interval)
{
    Settings::interval = interval;

}

void Settings::setSample_size(int sample_size)
{
    Settings::sample_size = sample_size;

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

void Settings::setDay(int dayTag, int startingHour, int startingMinute, int endingHour, int endingMinute)
{
    planning->getDay(dayTag)->setStartingHour(startingHour);
    planning->getDay(dayTag)->setStartingMinute(startingMinute);
    planning->getDay(dayTag)->setEndingHour(endingHour);
    planning->getDay(dayTag)->setEndingMinute(endingMinute);

}

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
