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
         * @param addr : address to save the variable on the EEPROM memory.
         * @param val : value to save.
         */
        static void saveUnsignedInt(unsigned int addr, unsigned int val);
        /**
         * Save a boolean.
         * @param addr : address to save the variable on the EEPROM memory.
         * @param val : value to save.
         */
        static void saveBool(unsigned int addr, bool val);

        /**
         * Load an unsigned int.
         * @param addr : address to load the variable on the EEPROM memory.
         * @param val : value to load.
         */
        static unsigned int loadUnsignedInt(unsigned int addr);
        /**
         * Load a boolean.
         * @param addr : address to load the variable on the EEPROM memory.
         * @param val : value to load.
         */
        static bool loadBool(unsigned int addr);

};

#endif
