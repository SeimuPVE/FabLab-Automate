#ifndef BUTTON
#define BUTTON

#include "Arduino.h"

/**
 * Port for the buzzer.
 */
#define BUZZER_PORT 9
/**
 * Port for the pin A of the button.
 */
#define encoder0PinA 2
/**
 * Port for the pin B of the button.
 */
#define encoder0PinB 4
/**
 * Port for the pin C of the button.
 */
#define encoder0PinC 3
/**
 * Port for the button ON.
 */
#define BUTTON_ON 5
/**
 * Port for the button OFF.
 */
#define BUTTON_OFF 7


/**
 * Class to use a rotary button.
 */
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
