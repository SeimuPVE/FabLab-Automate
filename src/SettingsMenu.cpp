#include "SettingsMenu.h"


SettingsMenu::SettingsMenu(Printer *printer, Button *newButton, Settings *newSettings) : MenuCreator(printer, newButton)
{
    setSettings(newSettings);
    daysMenu = new DaysMenu(printer, newButton, newSettings);

    int listSize = 5;
    String titleList[] =    {
                                F(TITLE_DAYS_MENU),
                                F(TITLE_CONTINUE),
                                F(TITLE_BORNS),
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
        case 2 : setBorns(); break;
        case 3 : setNO(); break;
        case 4 : settings->save(); setExitFlag(true); break;
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
    settings->setContinue(selectBoolean(F(SELECTOR_CONTINUE), F(SELECTOR_IS_CONTINUE), F(SELECTOR_IS_PONCTUAL), settings->isContinue()));

    if(settings->isContinue())
        settings->setFrequency(selectBetweenInterval(F(SELECTOR_FREQUENCY), true, settings->getFrequency(), 0, 9999));
    else
        settings->setInterval(selectBetweenInterval(F(SELECTOR_INTERVAL), true, settings->getInterval()));

    settings->setSample_size(selectBetweenInterval(F(SELECTOR_SAMPLE_SIZE), true, settings->getSample_size()));

}

void SettingsMenu::setBorns()
{
    settings->setBornInf(selectBetweenInterval(F(SELECTOR_BORN_INF), true, settings->getBornInf()));
    settings->setBornSup(selectBetweenInterval(F(SELECTOR_BORN_SUP), true, settings->getBornSup()));

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
        case 2 : printer->WriteL2(settings->getStrBorns()); break;
        case 3 : printer->WriteL2(settings->getStrNormalyOpen()); break;
        case 4 : printer->WriteL2(F(LABEL_GO_BACK)); break;
        default : Serial.println("Error : menu functions error."); break;

    }

}
