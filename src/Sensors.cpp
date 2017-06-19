#include "Sensors.h"


Settings *Sensors::getSettings()
{
    return settings;
  
}

int Sensors::getMesure()
{
    return analogRead(PORT_SENSOR);
  
}

void Sensors::setRelais(bool state)
{
    if(state == false)
        digitalWrite(PORT_RELAIS, LOW);
    else
        digitalWrite(PORT_RELAIS, HIGH);
  
}

