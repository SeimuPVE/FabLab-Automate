#include "Tools.h"


int getMesure()
{
    return analogRead(PORT_SENSOR);
  
}

void setRelais(bool state)
{
    if(state == false)
        digitalWrite(PORT_RELAIS, LOW);
    else
        digitalWrite(PORT_RELAIS, HIGH);
  
}

