#ifndef SAVERLOADER_H
#define SAVERLOADER_H

#include <EEPROM.h>


/**
 * Class to save and load variables on the EEPROM memory.
 */
class SaverLoader
{
    public:
        /**
         * Save an unsigned int.
         * @param address : address to save the variable on the EEPROM memory.
         * @param val : value to save.
         */
        static void saveUnsignedInt(unsigned int address, unsigned int val);
        /**
         * Save a boolean.
         * @param address : address to save the variable on the EEPROM memory.
         * @param val : value to save.
         */
        static void saveBool(unsigned int address, bool val);

        /**
         * Load an unsigned int.
         * @param address : address to load the variable on the EEPROM memory.
         * @param val : value to load.
         */
        static unsigned int loadUnsignedInt(unsigned int address);
        /**
         * Load a boolean.
         * @param address : address to load the variable on the EEPROM memory.
         * @param val : value to load.
         */
        static bool loadBool(unsigned int address);

};

#endif
