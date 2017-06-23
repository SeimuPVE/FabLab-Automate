#include "MainMenu.h"
#include "ContinueMode.h"
#include "PonctualMode.h"


MainMenu::MainMenu(Printer *printer, Button *newButton) : MenuCreator(printer, newButton)
{
    sensors = new Sensors();
    settingsMenu = new SettingsMenu(printer, newButton, sensors->getSettings());

    int listSize = 4;
    String titleList[] = {TITLE_START, TITLE_MESURE, TITLE_TEST, TITLE_SETTINGS};
            
    setTitles(titleList, listSize);

}

MainMenu::~MainMenu()
{
    delete sensors;
    delete settingsMenu;

}

void MainMenu::menuFunctions(unsigned int choice)
{
    if(choice == 0)
        modeNormal();
    else if(choice == 1)
        modeMeasure();
    else if(choice == 2)
        modeTest();
    else if(choice == 3)
        modeSettings();
    else
        Serial.println("Error");

}

void MainMenu::modeNormal(void)
{
    if(sensors->getSettings()->isContinue())
    {
        ContinueMode continueMode(sensors, printer, button, false);
        continueMode.launch();

    }
    else
    {
        PonctualMode ponctualMode(sensors, printer, button, false);
        ponctualMode.launch();

    }

}

void MainMenu::modeMeasure()
{
    int last_value, current_value = sensors->getMeasure();

    printer->Clear();

    while(!button->buttonOk())
    {
        last_value = current_value;
        current_value = sensors->getMeasure();

        if(last_value > current_value)
            printer->Clear();

        printer->WriteL1(LABEL_CURRENT_MESURE);
        printer->WriteL2(current_value);

        delay(100);

        button->checkButtonsUnblocking();

    }

}

void MainMenu::modeTest()
{
    if(sensors->getSettings()->isContinue())
    {
        ContinueMode continueMode(sensors, printer, button, true);
        continueMode.launch();

    }
    else
    {
        PonctualMode ponctualMode(sensors, printer, button, true);
        ponctualMode.launch();

    }

}

void MainMenu::modeSettings()
{
    printer->Clear();
    settingsMenu->execute();
  
}

void MainMenu::printLabel()
{
    printer->WriteL2(titleList[(currentChoice + 1) % titleSize], 3);
  
}
