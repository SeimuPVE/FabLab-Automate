#ifndef PRINTER
#define PRINTER

#include "Arduino.h"

#include <Wire.h>
#include <LCD.h>
#include <LiquidCrystal_I2C.h>

#define I2C_ADDR 0x27
#define BACKLIGHT_PIN 3
#define En_pin 2
#define Rw_pin 1
#define Rs_pin 0
#define D4_pin 4
#define D5_pin 5
#define D6_pin 6
#define D7_pin 7


class Printer
{
    private:
        LiquidCrystal_I2C lcd;

    public:
        Printer();
        void WriteL1(String str);
        void WriteL1(String str, int pos);
        void WriteL2(String str);
        void WriteL2(String str, int pos);
        void Clear();

};

#endif

