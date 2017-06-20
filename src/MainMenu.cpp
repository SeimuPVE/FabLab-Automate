#include "MainMenu.h"


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
    int i = 0, j, average, sample_size, born_inf, born_sup;
    bool off = false;
    time_t t1, t2;

    sample_size = sensors->getSettings()->getSample_size();
    born_inf = sensors->getSettings()->getBornInf();
    born_sup = sensors->getSettings()->getBornSup();

    if(sensors->getSettings()->isNO())
        sensors->setRelais(true);
    else
        sensors->setRelais(false);


    if(sensors->getSettings()->isContinue())
    {
        int sample[sample_size];
        average = 0;

        printer->Clear();
        printer->WriteL1("Testing...");
        printer->WriteL2(sensors->getMesure());

        for(i = 0; i < sample_size; i++)
        {
            sample[i] = sensors->getMesure();
            average += sample[i];
            delay(60 * 60 / sensors->getSettings()->getFrequency());

        }
        average /= sample_size;

        printer->Clear();
        printer->WriteL1("Testing...");
        printer->WriteL2(average);

        if(average < born_inf || average > born_sup)
        {
            sensors->setRelais(!sensors->getRelais());
            off = true;

        }

        t1 = now();
        t2 = t1;

        while(!button->buttonOk() && !off)
        {
            if(second(t2 - t1) + 1 > (60 * 60 / sensors->getSettings()->getFrequency()))
            {
                sample[i] = sensors->getMesure();

                i++;
                if(i > sample_size)
                    i = 0;

                average = 0;
                for(j = 0; j < sample_size; j++)
                    average += sample[j];
                average /= sample_size;

                printer->Clear();
                printer->WriteL1("Testing...");
                printer->WriteL2(average);

                if(average < born_inf || average > born_sup)
                {
                    sensors->setRelais(!sensors->getRelais());
                    off = true;

                }

                t1 = t2;

            }

            t2 = now();
            button->checkButtonsUnblocking();

        }

    }
    else
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

