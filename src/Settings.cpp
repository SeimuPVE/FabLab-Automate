#include "Settings.h"

Settings::Settings()
{
    setContinue(true);
    setFrequency(10);
    setBornSup(500.0);
    setBornInf(400.0);
    setNO(false);
  
}

WeekPlanning Settings::getPlanning()
{
    return planning;
  
}

bool Settings::isContinue()
{
    return iContinue;
  
}

int Settings::getFrequency()
{
    return frequency;
  
}

double Settings::getBornSup()
{
    return bornSup;
  
}

double Settings::getBornInf()
{
    return bornInf;
  
}

bool Settings::isNO()
{
    return NormalyOpen;
  
}

void Settings::setContinue(bool newPonctual)
{
    iContinue = newPonctual;
  
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
    NormalyOpen = newNO;

}

void Settings::setDayStartingTime(int dayTag, String startingTime)
{
    planning.setDayStartingTime(dayTag, startingTime);
  
}

void Settings::setDayEndingTime(int dayTag, String endingTime)
{
    planning.setDayEndingTime(dayTag, endingTime);
  
}

void Settings::setAllStartingTime(String startingTime)
{
    planning.setAllStartingTime(startingTime);

}

void Settings::setAllEndingTime(String endingTime)
{
    planning.setAllEndingTime(endingTime);
  
}

void Settings::setDay(int dayTag, String startingHour, String endingHour)
{
    planning.setDay(dayTag, startingHour, endingHour);
  
}

void Settings::setAll(String startingHour, String endingHour)
{
    planning.setAll(startingHour, endingHour);
  
}

String Settings::getStrDay(int dayTag)
{
    String str;
    
    str += "S:";
    str += getPlanning().getDay(dayTag).getStartingTime();

    str += "  E:";
    str += getPlanning().getDay(dayTag).getEndingTime();

    return str;
    
}

String Settings::getStrCurrentDate()
{
    return "Current date...";
    
}

String Settings::getStrIsContinue()
{
    if(iContinue)
        return "        Ponctual";
    return "        Continue";
  
}

String Settings::writeFrequency()
{
    return "Change this label";

}

String Settings::getStrBorns()
{
    return "Change this label";

}

String Settings::getStrNormalyOpen()
{
    if(isNO())
        return "    Normaly open";
    return "   Normaly close";

}
