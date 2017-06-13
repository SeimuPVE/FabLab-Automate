#ifndef SENSORS
#define SENSORS

#include "Arduino.h"

#define PORT_SENSOR 0
#define PORT_RELAIS 6


class Sensors
{
    public:
        static int getMesure();
        static void setRelais(bool state);
  
};

#endif

