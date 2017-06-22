#ifndef SAVERLOADER_H
#define SAVERLOADER_H

#include <EEPROM.h>


class SaverLoader
{
    public:
        static void saveInt(int addr, int val);
        static void saveBool(int addr, bool val);

        static int loadInt(int addr);
        static bool loadBool(int addr);

};

#endif
