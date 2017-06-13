#include "MainMenu.h"
#include "Sensors.h"
#include "WeekPlanning.h"


void setup()
{
    Serial.begin(9600);
    pinMode(PORT_SENSOR, INPUT);
    pinMode(PORT_RELAIS, OUTPUT);
    
}

void loop()
{
/*    MainMenu menu;
    menu.execute();*/

/*    DayPlanning monday("Monday", "10h10", "10h10");
    Serial.println("Starting time : " + monday.getStartingTime());
    Serial.println("Ending time : " + monday.getEndingTime());
    delay(1000);*/
    WeekPlanning week;
    week.printPlanning();
    delay(10000);
    
/*    if(Sensors::getMesure() < 500)
        Sensors::setRelais(false);
    else
        Sensors::setRelais(true);*/

}

