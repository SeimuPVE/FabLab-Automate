#include "Printer.h"


Printer::Printer() : lcd(I2C_ADDR, En_pin, Rw_pin, Rs_pin, D4_pin, D5_pin, D6_pin, D7_pin)
{
    lcd.begin(16, 2);

    lcd.setBacklightPin(BACKLIGHT_PIN, POSITIVE);
    lcd.setBacklight(HIGH);

    lcd.home();
    
}

void Printer::WriteL1(String str)
{
    WriteL1(str, 0);
      
}

void Printer::WriteL1(String str, int pos)
{
    lcd.setCursor(pos, 0);
    lcd.print(str);
    
}

void Printer::WriteL2(String str)
{
    WriteL2(str, 0);
    
}

void Printer::WriteL2(String str, int pos)
{
    lcd.setCursor(pos, 1);
    lcd.print(str);
  
}

void Printer::Clear()
{
    lcd.clear();
    
}

