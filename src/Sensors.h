#ifndef SENSORS
#define SENSORS

#include "Arduino.h"
#include "Settings.h"

#define PORT_SENSOR 0
#define PORT_RELAIS 6


/**
 * Class to use sensors and actionners.
 */
class Sensors
{
    private:
        Settings *settings;
        bool relais;
        
    public:
        /**
         * Constructor.
         */
        Sensors();
        /**
         * Destructor.
         */
        ~Sensors();

        /**
         * Get the settings of this class.
         * @return : settings of the class.
         */
        Settings *getSettings();

        /**
         * Get the measure of the sensor.
         * @return : measure value.
         */
        unsigned int getMeasure();
        /**
         * Set the state of the relay.
         * @param state : new state.
         */
        void setRelay(bool state);
        /**
         * Get the state of the relay.
         * @return : state of the relay.
         */
        bool getRelay() const;
  
};

#endif
