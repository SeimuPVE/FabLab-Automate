#include "Sensors.h"


Sensors::Sensors()
{
    settings = new Settings;
    settings->load();

}

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
    relais = state;

    if(state == false)
        digitalWrite(PORT_RELAIS, LOW);
    else
        digitalWrite(PORT_RELAIS, HIGH);
  
}

bool Sensors::getRelais() const
{
    return relais;

}
