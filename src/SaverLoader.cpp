#include "SaverLoader.h"

static void SaverLoader::saveUnsignedInt(unsigned int address, unsigned int val)
{
    EEPROM.write(address, (uint8_t )(val >> 8) & 0x00FF);
    EEPROM.write(address + 1, (uint8_t )val & 0x00FF);

}

static void SaverLoader::saveBool(unsigned int address, bool val)
{
    EEPROM.write(address, (uint8_t )val);

}

static unsigned int SaverLoader::loadUnsignedInt(unsigned int address)
{
    unsigned int val = 0;
    uint8_t byte_one = EEPROM.read(address);
    uint8_t byte_two = EEPROM.read(address + 1);

    val = byte_one;
    val = val << 8;
    val = val | byte_two;

    return val;

}

static bool SaverLoader::loadBool(unsigned int address)
{
    return (bool) EEPROM.read(address);

}
