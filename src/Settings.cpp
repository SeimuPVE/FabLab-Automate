#include "Settings.h"


Settings::Settings()
{
    planning = new WeekPlanning;
    setSyncProvider(rtc->get);

    if(timeStatus() == timeNotSet)
    {
        setTime(0, 0, 0, 1, 1, 2017);
        rtc->set(now());

    }

    setContinue(true);
    setCrashMode(true);
    setFrequency(9999);
    setInterval(1);
    setSample_size(10);
    setBornSup(200);
    setBornInf(0);
    setNO(false);

}

Settings::~Settings()
{
    delete planning;
    delete rtc;

}

WeekPlanning *Settings::getPlanning() const
{
    return planning;
  
}

time_t Settings::getDateTime() const
{
    return now();

}

void Settings::setDateTime(unsigned int hour, unsigned int minute, unsigned int day, unsigned int month, unsigned int year)
{
    setTime(hour, minute, 0, day, month, year);
    rtc->set(now());

}

bool Settings::isContinue() const
{
    return iContinue;
  
}

bool Settings::isCrashMode() const
{
    return crashMode;

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

void Settings::setCrashMode(bool newCrashMode)
{
    crashMode = newCrashMode;

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

    switch(dayOfWeek(now()) - 1)
    {
        case 0 : result += F(LABEL_SUNDAY); break;
        case 1 : result += F(LABEL_MONDAY); break;
        case 2 : result += F(LABEL_TUESDAY); break;
        case 3 : result += F(LABEL_WEDNESDAY); break;
        case 4 : result += F(LABEL_THURSDAY); break;
        case 5 : result += F(LABEL_FRIDAY); break;
        case 6 : result += F(LABEL_SATURDAY); break;

    }

    result += " ";

    if(hour(now()) < 10)
        result += '0';
    result += hour(now());

    result += F(SEPARATOR);

    if(minute(now()) < 10)
        result += '0';
    result += minute(now());

    return result;

}

String Settings::getStrIsContinue()
{
    if(iContinue)
        return F(LABEL_IS_CONTINUE);
    return F(LABEL_IS_PONCTUAL);

}

String Settings::getStrIsCrashMode()
{
    if(crashMode)
        return F(LABEL_IS_CRASH_MODE);
    return F(LABEL_IS_NOT_CRASH_MODE);

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
        return F(LABEL_IS_NO);
    return F(LABEL_IS_NC);

}

void Settings::save()
{
    unsigned int starting_addr = 0;

    SaverLoader::saveBool(starting_addr, iContinue);
    SaverLoader::saveBool(starting_addr + 1, crashMode);
    SaverLoader::saveUnsignedInt(starting_addr + 2, frequency);
    SaverLoader::saveUnsignedInt(starting_addr + 4, interval);
    SaverLoader::saveUnsignedInt(starting_addr + 6, sample_size);
    SaverLoader::saveUnsignedInt(starting_addr + 8, bornSup);
    SaverLoader::saveUnsignedInt(starting_addr + 10, bornInf);
    SaverLoader::saveBool(starting_addr + 12, normalyOpen);
    planning->save(13);

}

void Settings::load()
{
    unsigned int starting_addr = 0;

    iContinue = SaverLoader::loadBool(starting_addr);
    crashMode = SaverLoader::loadBool(starting_addr + 1);
    frequency = SaverLoader::loadUnsignedInt(starting_addr + 2);
    interval = SaverLoader::loadUnsignedInt(starting_addr + 4);
    sample_size = SaverLoader::loadUnsignedInt(starting_addr + 6);
    bornSup = SaverLoader::loadUnsignedInt(starting_addr + 8);
    bornInf = SaverLoader::loadUnsignedInt(starting_addr + 10);
    normalyOpen = SaverLoader::loadBool(starting_addr + 12);
    planning->load(13);

}
