#ifndef BUTTON
#define BUTTON

#include "Arduino.h"

#define encoder0PinA 2
#define encoder0PinB 4
#define encoder0PinC 3
#define encoder0Pos 0


class Button
{
    private:
        bool buttonUpState;
        bool buttonDownState;
        bool buttonOkState;

        int encoder0PinALast;
        int encoder0PinCLast;
        int nA;
        int nC;

    public:
        Button();
        
        void checkButtons();

        bool buttonUp();
        bool buttonDown();
        bool buttonOk();
  
};

#endif
