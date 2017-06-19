#ifndef PRINTER
#define PRINTER

#include "Arduino.h"

#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define I2C_ADDR 0x27


class Printer
{
    private:
        LiquidCrystal_I2C lcd;

    public:
        Printer();

        void WriteL1(String str, int pos = 0);
        void WriteL2(String str, int pos = 0);
        void WriteL1(int i, int pos = 0);
        void WriteL2(int i, int pos = 0);

        void Clear();

};

#endif
