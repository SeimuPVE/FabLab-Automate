#include "SaverLoader.h"

static void SaverLoader::saveUnsignedInt(unsigned int addr, unsigned int val)
{
    EEPROM.write(addr, (uint8_t )(val >> 8) & 0x00FF);
    EEPROM.write(addr + 1, (uint8_t )val & 0x00FF);

}

static void SaverLoader::saveBool(unsigned int addr, bool val)
{
    EEPROM.write(addr, (uint8_t )val);

}

static unsigned int SaverLoader::loadUnsignedInt(unsigned int addr)
{
    unsigned int val = 0;
    uint8_t fort = EEPROM.read(addr);
    uint8_t faible = EEPROM.read(addr + 1);

    val = fort;
    val = val << 8;
    val = val | faible;

    return val;

}

static bool SaverLoader::loadBool(unsigned int addr)
{
    return (bool) EEPROM.read(addr);

}
