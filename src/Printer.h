#ifndef PRINTER
#define PRINTER

#include "Arduino.h"

#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define I2C_ADDR 0x27


/**
 * Printer to print information on LCD screen.
 */
class Printer
{
    private:
        LiquidCrystal_I2C lcd;

    public:
        /**
         * Constructor.
         */
        Printer();

        /**
         * Write a string on the first line of the screen.
         * @param str : string to write.
         * @param pos : column to start writing.
         */
        void WriteL1(String str, int pos = 0);
        /**
         * Write a string on the second line of the screen.
         * @param str : string to write.
         * @param pos : column to start writing.
         */
        void WriteL2(String str, int pos = 0);
        /**
         * Write an int on the first line of the screen.
         * @param i : int to write.
         * @param pos : column to start writing.
         */
        void WriteL1(int i, int pos = 0);
        /**
         * Write an int on the second line of the screen.
         * @param i : int to write.
         * @param pos : column to start writing.
         */
        void WriteL2(int i, int pos = 0);

        /**
         * Clean the LCD screen.
         */
        void Clear();

};

#endif
