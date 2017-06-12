#include "MenuCreator.h"
#include "ModesExecutor.h"
#include "Tools.h"


void setup()
{
    Serial.begin(9600);
    pinMode(PORT_SENSOR, INPUT);
    pinMode(PORT_RELAIS, OUTPUT);
    
}

void loop()
{
    setupMainMenu();
    
/*    if(getMesure() < 500)
        setRelais(false);
    else
        setRelais(true);*/

}

