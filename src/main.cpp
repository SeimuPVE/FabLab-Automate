#include "MainMenu.h"


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
    lcd->WriteL1("Please check");
    lcd->WriteL2("   your settings");

    while(!b->buttonOk())
        b->checkButtons();

    MainMenu menu(lcd, b);
    menu.execute();

}
