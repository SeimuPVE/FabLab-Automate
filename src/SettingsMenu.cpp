#include "SettingsMenu.h"


SettingsMenu::SettingsMenu(Printer *printer, Button *newButton, Settings *newSettings) : MenuCreator(printer, newButton)
{
    setSettings(newSettings);
    daysMenu = new DaysMenu(printer, newButton, newSettings);

    unsigned int listSize = 6;
    String titleList[] =    {
                                F(TITLE_DAYS_MENU),
                                F(TITLE_CONTINUE),
                                F(TITLE_CRASH_MODE),
                                F(TITLE_LIMITS),
                                F(TITLE_NO),
                                F(TITLE_EXIT)
                            };

    setTitles(titleList, listSize);

}

void SettingsMenu::menuFunctions(unsigned int choice)
{
    switch(choice)
    {
        case 0 : setDays(); break;
        case 1 : setContinue(); break;
        case 2 : setCrashMode(); break;
        case 3 : setBorns(); break;
        case 4 : setNO(); break;
        case 5 : settings->save(); setExitFlag(true); break;
        default : Serial.println("Error : menu functions error."); break;
        
    }
  
}

void SettingsMenu::setDays()
{
    printer->Clear();
    daysMenu->execute();

}

void SettingsMenu::setContinue()
{
    settings->setContinue(selectBoolean(F(SELECTOR_CONTINUE), F(SELECTOR_IS_CONTINUE), F(SELECTOR_IS_RECURRENT), settings->isContinue()));

    if(settings->isContinue())
        settings->setFrequency((unsigned int) selectBetweenInterval(F(SELECTOR_FREQUENCY), 500, settings->getFrequency(), 0, 9999));
    else
        settings->setInterval((unsigned int) selectBetweenInterval(F(SELECTOR_INTERVAL), 20, settings->getInterval()));

    settings->setSample_size((unsigned int) selectBetweenInterval(F(SELECTOR_SAMPLE_SIZE), 10, settings->getSample_size()));

}

void SettingsMenu::setCrashMode()
{
    settings->setCrashMode(selectBoolean(F(SELECTOR_CRASH_MODE), F(SELECTOR_IS_CRASH_MODE), F(SELECTOR_IS_NOT_CRASH_MODE), settings->isCrashMode()));

}

void SettingsMenu::setBorns()
{
    settings->setBornInf((unsigned int) selectBetweenInterval(F(SELECTOR_BORN_INF), 20, settings->getBornInf()));
    settings->setBornSup((unsigned int) selectBetweenInterval(F(SELECTOR_BORN_SUP), 20, settings->getBornSup()));

}

void SettingsMenu::setNO()
{
    settings->setNO(selectBoolean(F(SELECTOR_NO), F(SELECTOR_IS_NO), F(SELECTOR_IS_NC), settings->isNO()));

}

void SettingsMenu::setSettings(Settings *newSettings)
{
    settings = newSettings;
  
}

void SettingsMenu::printLabel()
{
    switch(currentChoice)
    {
        case 0 : printer->WriteL2(F(LABEL_SET_DAYS)); break;
        case 1 : printer->WriteL2(settings->getStrIsContinue()); break;
        case 2 : printer->WriteL2(settings->getStrIsCrashMode()); break;
        case 3 : printer->WriteL2(settings->getStrBorns()); break;
        case 4 : printer->WriteL2(settings->getStrNormalyOpen()); break;
        case 5 : printer->WriteL2(F(LABEL_GO_BACK)); break;
        default : Serial.println("Error : menu functions error."); break;

    }

}
