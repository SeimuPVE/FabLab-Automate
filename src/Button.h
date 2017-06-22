#ifndef BUTTON
#define BUTTON

#include "Arduino.h"

#define BUZZER_PORT 9
#define encoder0PinA 2
#define encoder0PinB 4
#define encoder0PinC 3


class Button
{
    private:
        bool buttonUpState;
        bool buttonDownState;
        bool buttonOkState;

        unsigned int encoder0PinALast;
        unsigned int encoder0PinCLast;
        unsigned int nA;
        unsigned int nC;

    public:
        Button();
        
        void checkButtons();
        bool checkButtonsUnblocking();

        bool buttonUp();
        bool buttonDown();
        bool buttonOk();
  
};

#endif
