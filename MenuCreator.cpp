#include "MenuCreator.h"


MenuCreator::MenuCreator()
{
    currentChoice = 0;

    buttonUpState = false;
    buttonDownState = false;
    buttonOkState = false;

}

bool MenuCreator::getExitFlag()
{
    return exitFlag;
  
}

void MenuCreator::setExitFlag(bool newExitFlag)
{
    exitFlag = newExitFlag;
  
}

void MenuCreator::setTitles(String newTitleList[], int newTitleSize)
{
    if((titleList = (char **) malloc(newTitleSize * sizeof(char *))) == NULL)
        Printer::Write("Malloc error : can't create title list in the menu creator.");
    
    for(int i = 0; i < newTitleSize; i++)
    {
        if((titleList[i] = (char *) malloc((newTitleList[i].length() + 1 ) * sizeof(char))) == NULL)
            Printer::Write("Malloc error : can't add title to the list in the menu creator.");
        
        newTitleList[i].toCharArray(titleList[i], newTitleList[i].length() + 1);

    }

    titleSize = newTitleSize;
  
}

void MenuCreator::setLabels(String newLabelList[], int newLabelSize)
{
    if((labelList = (char **) malloc(newLabelSize * sizeof(char *))) == NULL)
        Printer::Write("Malloc error : can't create label list in the menu creator.");
    
    for(int i = 0; i < newLabelSize; i++)
    {
        if((labelList[i] = (char *) malloc((newLabelList[i].length() + 1 ) * sizeof(char))) == NULL)
            Printer::Write("Malloc error : can't add label to the list in the menu creator.");
        
        newLabelList[i].toCharArray(labelList[i], newLabelList[i].length() + 1);
      
    }

    labelSize = newLabelSize;
  
}

void MenuCreator::execute()
{
    exitFlag = false;
    
    printChoice();
    Printer::ReturnLine();
    printLabel();

    while(!exitFlag)
    {        
        checkButtons();
      
        if(buttonUp())
            currentChoice = (currentChoice + 1) % titleSize;
        else if(buttonDown())
        {
            currentChoice--;

            if(currentChoice < 0)
                currentChoice = titleSize - 1;
          
        }
        else if(buttonOk())
            menuFunctions(currentChoice);
    
        printChoice();
        Printer::ReturnLine();
        printLabel();
      
    }
  
}

// TODO : for tests, please change it.
void MenuCreator::checkButtons()
{
    char input;

    Serial.println();
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
    Printer::Write("Launch mode");
  
}
void MenuCreator::printChoice()
{
    Printer::Write("-> ");
    Printer::Write(titleList[currentChoice]);
  
}

