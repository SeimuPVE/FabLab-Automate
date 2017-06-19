#ifndef SENSORS
#define SENSORS

#include "Arduino.h"
#include "Settings.h"

#define PORT_SENSOR 0
#define PORT_RELAIS 6


class Sensors
{
    private:
        Settings *settings;
        
    public:
        Sensors();

        Settings *getSettings();
        
        int getMesure();
        void setRelais(bool state);
  
};

#endif
