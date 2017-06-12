#include "MenuCreator.h"


MenuCreator::MenuCreator()
{
    currentChoice = 0;

}

void MenuCreator::setTitles(String newTitleList[], int newListSize)
{
    if((titleList = (char **) malloc(newListSize * sizeof(char *))) == NULL)
        Serial.println("Malloc error");
    
    for(int i = 0; i < newListSize; i++)
    {
        if((titleList[i] = (char *) malloc((newTitleList[i].length() + 1 ) * sizeof(char))) == NULL)
            Serial.println("Malloc error");
        
        newTitleList[i].toCharArray(titleList[i], newTitleList[i].length() + 1);

        Serial.println(titleList[i]);
      
    }

    listSize = newListSize;

    buttonUpState = false;
    buttonDownState = false;
    buttonOkState = false;
  
}

void MenuCreator::execute()
{
    while(1)
    {        
        checkButtons();
      
        if(buttonUp())
            currentChoice = (currentChoice + 1) % listSize;
        else if(buttonDown())
        {
            currentChoice--;

            if(currentChoice < 0)
                currentChoice = listSize - 1;
          
        }
        else if(buttonOk())
            menuFunctions(currentChoice);
    
        printChoice();
      
    }
  
}

// TODO : for tests, please change it.
void MenuCreator::checkButtons()
{
    char input;

    Serial.print("> ");
    while(Serial.available() <= 0);

    input = Serial.read();
    Serial.println(input);

    buttonUpState = false;
    buttonDownState = false;
    buttonOkState = false;

    switch(input)
    {
      case 'U': buttonUpState = true; break;
      case 'D': buttonDownState = true;  break;
      case 'O': buttonOkState = true;  break;
    
    }

}

bool MenuCreator::buttonUp()
{
    return buttonUpState;
  
}

bool MenuCreator::buttonDown()
{
    return buttonDownState;
        
}

bool MenuCreator::buttonOk()
{
    return buttonOkState;

}

void MenuCreator::printLaunchMode()
{
    Serial.println("Launch mode");
  
}

void MenuCreator::printChoice()
{
    Serial.println(titleList[currentChoice]);
  
}

