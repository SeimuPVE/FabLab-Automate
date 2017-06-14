#include "Printer.h"


void Printer::Begin()
{
    Serial.begin(9600);

}

void Printer::Write(String str)
{
    Serial.print(str);
  
}

void Printer::ReturnLine()
{
    Serial.println();
  
}

