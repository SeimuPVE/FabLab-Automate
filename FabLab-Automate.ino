#include "MainMenu.h"
#include "Sensors.h"
#include "WeekPlanning.h"
#include "Settings.h"
#include "SettingsMenu.h"


void setup()
{
    Serial.begin(9600); // For errors.
    pinMode(PORT_SENSOR, INPUT);
    pinMode(PORT_RELAIS, OUTPUT);
    
}

void loop()
{
    MainMenu menu;
    menu.execute();

    Sensors sensors;
    if(sensors.getMesure() < 500)
        sensors.setRelais(false);
    else
        sensors.setRelais(true);

}

