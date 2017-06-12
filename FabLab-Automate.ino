#include "MainMenu.h"
#include "Tools.h"


void setup()
{
    Serial.begin(9600);
    pinMode(PORT_SENSOR, INPUT);
    pinMode(PORT_RELAIS, OUTPUT);
    
}

void loop()
{
    MainMenu menu;
    menu.execute();
    
/*    if(getMesure() < 500)
        setRelais(false);
    else
        setRelais(true);*/

}

