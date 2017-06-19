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
    
    MainMenu menu(lcd, b);
    menu.execute();

}
