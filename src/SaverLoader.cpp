#include "SaverLoader.h"

static void SaverLoader::saveInt(int addr, int val)
{
    EEPROM.write(addr, (uint8_t )(val >> 8) & 0x00FF);
    EEPROM.write(addr + 1, (uint8_t )val & 0x00FF);

}

static void SaverLoader::saveBool(int addr, bool val)
{
    EEPROM.write(addr, (uint8_t )val);

}

static int SaverLoader::loadInt(int addr)
{
    int val = 0;
    uint8_t fort = EEPROM.read(addr);
    uint8_t faible = EEPROM.read(addr + 1);

    val = fort;
    val = val << 8;
    val = val | faible;

    return val;

}

static bool SaverLoader::loadBool(int addr)
{
    return (bool) EEPROM.read(addr);

}
