#include "MainMenu.h"
#include "ContinueMode.h"


MainMenu::MainMenu(Printer *printer, Button *newButton) : MenuCreator(printer, newButton)
{
    sensors = new Sensors();
    settingsMenu = new SettingsMenu(printer, newButton, sensors->getSettings());

    int listSize = 4;
    String titleList[] = {"Start", "Mesure", "Test", "Settings"};
            
    setTitles(titleList, listSize);

}

void MainMenu::menuFunctions(int choice)
{
    if(choice == 0)
        modeNormal();
    else if(choice == 1)
        modeMesure();
    else if(choice == 2)
        modeTest();
    else if(choice == 3)
        modeSettings();
    else
        Serial.println("Error");

}

void MainMenu::modeNormal(void)
{
    printer->Clear();
    printer->WriteL1("Normal mode");
    printer->WriteL2("(to add)", 8);

    for(int i = 0; i < 3; i++)
    {
        printer->WriteL2(".", i);
        delay(1000);
        
    }
    
}

void MainMenu::modeMesure()
{
    while(!button->buttonOk())
    {
        printer->Clear();
        printer->WriteL1("Current mesure :");
        printer->WriteL2(sensors->getMesure());

        delay(200);

        button->checkButtonsUnblocking();

    }

}

void MainMenu::modeTest()
{
    if(sensors->getSettings()->isContinue())
    {
        ContinueMode continueMode(sensors, printer, button);
        continueMode.launch();

    }
/*    else
    {
        t1 = now();
        t2 = t1;

        printer->Clear();
        printer->WriteL1("Testing...");
        printer->WriteL2(sensors->getMesure());

        while(!button->buttonOk() && !off)
        {
            if(second(t2 - t1) + 1 > sensors->getSettings()->getInterval())
            {
                average = 0;
                for(i = 0; i < sample_size; i++)
                    average += sensors->getMesure();
                average /= sample_size;

                if(average < born_inf || average > born_sup)
                {
                    sensors->setRelais(!sensors->getRelais());
                    off = true;

                }

                printer->Clear();
                printer->WriteL1("Testing...");
                printer->WriteL2(average);

                t1 = t2;

            }

            t2 = now();
            button->checkButtonsUnblocking();

        }

    }
*/
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
