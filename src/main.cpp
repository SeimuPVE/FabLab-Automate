#include "MainMenu.h"
#include "Sensors.h"
#include "WeekPlanning.h"
#include "Settings.h"
#include "SettingsMenu.h"
#include "Printer.h"


void setup()
{
    Serial.begin(9600); // To print errors.
    
    pinMode(PORT_SENSOR, INPUT);
    pinMode(PORT_RELAIS, OUTPUT);
    
}

void loop()
{
    Printer lcd;
    Button b;
    
    MainMenu menu(&lcd, &b);
    menu.execute();

/*    Sensors sensors;
    if(sensors.getMesure() < 500)
        sensors.setRelais(false);
    else
        sensors.setRelais(true);*/

}
