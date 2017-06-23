#include "Sensors.h"


Sensors::Sensors()
{
    settings = new Settings;
    settings->load();

}

Sensors::~Sensors()
{
    free(settings);

}

Settings *Sensors::getSettings()
{
    return settings;
  
}

unsigned int Sensors::getMeasure()
{
    return analogRead(PORT_SENSOR);
  
}

void Sensors::setRelay(bool state)
{
    relais = state;

    if(state == false)
        digitalWrite(PORT_RELAIS, LOW);
    else
        digitalWrite(PORT_RELAIS, HIGH);
  
}

bool Sensors::getRelay() const
{
    return relais;

}
