#include "MainMenu.h"

#define MAIN_L1 "Please check"
#define MAIN_L2 "   your settings"

void setup()
{
    Serial.begin(9600);
    
    pinMode(PORT_SENSOR, INPUT);
    pinMode(PORT_RELAIS, OUTPUT);
    
}

void loop()
{
    Printer *lcd = new Printer;
    Button *b = new Button;

    lcd->Clear();
    lcd->WriteL1(F(MAIN_L1));
    lcd->WriteL2(F(MAIN_L2));

    while(!b->buttonOk())
        b->checkButtons();

    MainMenu menu(lcd, b);
    menu.execute();

}
