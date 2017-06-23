#ifndef BUTTON
#define BUTTON

#include "Arduino.h"

/**
 * Port for the buzzer.
 */
#define BUZZER_PORT 9
/**
 * Por for the pin A of the button.
 */
#define encoder0PinA 2
/**
 * Por for the pin B of the button.
 */
#define encoder0PinB 4
/**
 * Por for the pin C of the button.
 */
#define encoder0PinC 3


/**
 * Class to use a rotatif button.
 */
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
        /**
         * Constructor.
         */
        Button();

        /**
         * Check the button while there isn't any new movement.
         */
        void checkButtons();
        /**
         * Check the button once.
         * @return bool : true if there was a movement, false else.
         */
        bool checkButtonsUnblocking();

        /**
         * Get if the user turned the button up.
         * @return true it the user turned the button, false else.
         */
        bool buttonUp();
        /**
         * Get if the user turned the button down.
         * @return true it the user turned the button, false else.
         */
        bool buttonDown();
        /**
         * Get if the user pushed the button ok.
         * @return true it the user pushed the button, false else.
         */
        bool buttonOk();
  
};

#endif
