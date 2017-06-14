#ifndef PRINTER
#define PRINTER

#include "Arduino.h"


class Printer
{
    private:
        
    public:
        static void Begin();
        static void Write(String str);
        static void ReturnLine();

};

#endif

