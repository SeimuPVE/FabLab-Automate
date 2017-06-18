#include "Button.h"


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

    digitalWrite(encoder0PinA, HIGH);
    digitalWrite(encoder0PinB, HIGH);
    digitalWrite(encoder0PinC, HIGH);

}

void Button::checkButtons()
{
    bool pushed = false;

    while(!pushed)
    {
        nA = digitalRead(encoder0PinA);
        nC = digitalRead(encoder0PinC);
        nC = digitalRead(encoder0PinC);
    
        if(encoder0PinCLast == true && nC == false)
        {
            buttonOkState = true;
            pushed = true;
            
        }
        else if((encoder0PinALast == LOW) && (nA == HIGH))
        {
            if (digitalRead(encoder0PinB) == LOW)
                buttonDownState = true;
            else
                buttonUpState = true;

            pushed = true;
    
        }
    
        encoder0PinALast = nA;
        encoder0PinCLast = nC;
        
    }
    
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
        buttonOkState = false;
        return true;
        
    }

    return false;
        
}

