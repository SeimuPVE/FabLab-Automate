#include "Button.h"
#include "Sensors.h"


Button::Button()
{
    buttonUpState = false;
    buttonDownState = false;
    buttonOkState = false;

    encoder0PinALast = LOW;
    encoder0PinCLast = HIGH;
    nA = LOW;
    nC = HIGH;

    pinMode(encoder0PinA, INPUT);
    pinMode(encoder0PinB, INPUT);
    pinMode(encoder0PinC, INPUT);

    pinMode(BUTTON_ON, INPUT);
    pinMode(BUTTON_OFF, INPUT);

    digitalWrite(encoder0PinA, HIGH);
    digitalWrite(encoder0PinB, HIGH);
    digitalWrite(encoder0PinC, HIGH);

}

void Button::checkButtons()
{
    while(!checkButtonsUnblocking());

}

bool Button::checkButtonsUnblocking()
{
    bool pushed = false;

    nA = digitalRead(encoder0PinA);
    nC = digitalRead(encoder0PinC);

    if(encoder0PinCLast != 0 && nC == 0)
    {
        buttonOkState = true;
        pushed = true;

    }
    else if((encoder0PinALast == LOW) && (nA == HIGH))
    {
        if (digitalRead(encoder0PinB) == LOW)
            buttonUpState = true;
        else
            buttonDownState = true;

        pushed = true;

    }

    encoder0PinALast = nA;
    encoder0PinCLast = nC;

    if(digitalRead(BUTTON_ON) == LOW) {
        digitalWrite(PORT_RELAIS, true);
        Serial.println("ON");
    }
    else if(digitalRead(BUTTON_OFF) == LOW) {
        digitalWrite(PORT_RELAIS, false);
        Serial.println("OFF");
    }

    return pushed;

}

bool Button::buttonUp()
{
    if(buttonUpState)
    {
        buttonUpState = false;
        return true;
        
    }

    return false;
    
}

bool Button::buttonDown()
{
    if(buttonDownState)
    {
        buttonDownState = false;
        return true;
        
    }

    return false;
    
}

bool Button::buttonOk()
{
    if(buttonOkState)
    {
        tone(BUZZER_PORT, 1000);
        delay(100);
        noTone(BUZZER_PORT);

        buttonOkState = false;
        return true;
        
    }

    return false;
        
}
