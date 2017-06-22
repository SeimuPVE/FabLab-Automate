#include "Settings.h"

Settings::Settings()
{
    if(timeStatus() == timeNotSet)
        setTime(0, 0, 0, 0, 0, 0);
    dateTime = now();

    setContinue(true);
    setFrequency(9999); // Continue.
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

time_t Settings::getDateTime() const
{
    return dateTime;

}

void Settings::setDateTime(unsigned int hour, unsigned int minute, unsigned int day, unsigned int month, unsigned int year)
{
    setTime(hour, minute, 0, day, month, year);
    dateTime = now();

}

bool Settings::isContinue() const
{
    return iContinue;
  
}

unsigned int Settings::getFrequency() const
{
    return frequency;
  
}

unsigned int Settings::getInterval() const
{
    return interval;

}

unsigned int Settings::getSample_size() const
{
    return sample_size;

}

unsigned int Settings::getBornSup() const
{
    return bornSup;
  
}

unsigned int Settings::getBornInf() const
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

void Settings::setFrequency(unsigned int newNumberCounts)
{
    frequency = newNumberCounts;
  
}

void Settings::setInterval(unsigned int interval)
{
    Settings::interval = interval;

}

void Settings::setSample_size(unsigned int sample_size)
{
    Settings::sample_size = sample_size;

}

void Settings::setBornSup(unsigned int newBornSup)
{
    bornSup = newBornSup;
  
}

void Settings::setBornInf(unsigned int newBornInf)
{
    bornInf = newBornInf;
  
}

void Settings::setNO(bool newNO)
{
    normalyOpen = newNO;

}

void Settings::setDay(unsigned int dayTag, unsigned int startingHour, unsigned int startingMinute, unsigned int endingHour, unsigned int endingMinute)
{
    planning->getDay(dayTag)->setStartingHour(startingHour);
    planning->getDay(dayTag)->setStartingMinute(startingMinute);
    planning->getDay(dayTag)->setEndingHour(endingHour);
    planning->getDay(dayTag)->setEndingMinute(endingMinute);

    dateTime = now();

}

String Settings::getStrDay(unsigned int dayTag)
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

    if(hour(dateTime) < 10)
        result += '0';
    result += hour(dateTime);

    result += ":";

    if(minute(dateTime) < 10)
        result += '0';
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

void Settings::save()
{
    unsigned int starting_addr = 0;

    SaverLoader::saveBool(starting_addr, iContinue);
    SaverLoader::saveUnsignedInt(starting_addr + 1, frequency);
    SaverLoader::saveUnsignedInt(starting_addr + 3, interval);
    SaverLoader::saveUnsignedInt(starting_addr + 5, sample_size);
    SaverLoader::saveUnsignedInt(starting_addr + 7, bornSup);
    SaverLoader::saveUnsignedInt(starting_addr + 9, bornInf);
    SaverLoader::saveBool(starting_addr + 11, normalyOpen);
    planning->save(12);

}

void Settings::load()
{
    unsigned int starting_addr = 0;

    iContinue = SaverLoader::loadBool(starting_addr);
    frequency = SaverLoader::loadUnsignedInt(starting_addr + 1);
    interval = SaverLoader::loadUnsignedInt(starting_addr + 3);
    sample_size = SaverLoader::loadUnsignedInt(starting_addr + 5);
    bornSup = SaverLoader::loadUnsignedInt(starting_addr + 7);
    bornInf = SaverLoader::loadUnsignedInt(starting_addr + 9);
    normalyOpen = SaverLoader::loadBool(starting_addr + 11);
    planning->load(12);

}
