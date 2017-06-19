#include "Printer.h"


Printer::Printer() : lcd(I2C_ADDR, 20, 4)
{
    lcd.init();
    lcd.backlight();
    lcd.home();
    
}

void Printer::WriteL1(String str, int pos)
{
    lcd.setCursor(pos, 0);
    lcd.print(str);
    
}

void Printer::WriteL2(String str, int pos)
{
    lcd.setCursor(pos, 1);
    lcd.print(str);
  
}

void Printer::WriteL1(int i, int pos)
{
    lcd.setCursor(pos, 0);
    lcd.print(i);

}

void Printer::WriteL2(int i, int pos)
{
    lcd.setCursor(pos, 1);
    lcd.print(i);

}

void Printer::Clear()
{
    lcd.clear();
    
}
