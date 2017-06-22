#ifndef SAVERLOADER_H
#define SAVERLOADER_H

#include <EEPROM.h>


class SaverLoader
{
    public:
        static void saveUnsignedInt(unsigned int addr, unsigned int val);
        static void saveBool(unsigned int addr, bool val);

        static unsigned int loadUnsignedInt(unsigned int addr);
        static bool loadBool(unsigned int addr);

};

#endif
