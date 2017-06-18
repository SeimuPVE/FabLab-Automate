#include "MenuCreator.h"


MenuCreator::MenuCreator(Printer *newPrinter, Button *newButton)
{
    printer = newPrinter;
    button = newButton;
    
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
        Serial.println("Malloc error : can't create title list in the menu creator.");
    
    for(int i = 0; i < newTitleSize; i++)
    {
        if((titleList[i] = (char *) malloc((newTitleList[i].length() + 1) * sizeof(char))) == NULL)
            Serial.println("Malloc error : can't add title to the list in the menu creator.");
        
        newTitleList[i].toCharArray(titleList[i], newTitleList[i].length() + 1);

    }

    titleSize = newTitleSize;
  
}

void MenuCreator::setLabels(String newLabelList[], int newLabelSize)
{
    if((labelList = (char **) malloc(newLabelSize * sizeof(char *))) == NULL)
        Serial.println("Malloc error : can't create label list in the menu creator.");
    
    for(int i = 0; i < newLabelSize; i++)
    {
        if((labelList[i] = (char *) malloc((newLabelList[i].length()) * sizeof(char))) == NULL)
            Serial.println("Malloc error : can't add label to the list in the menu creator.");
        
        newLabelList[i].toCharArray(labelList[i], newLabelList[i].length());
        labelList[newLabelList[i].length()] = '\0';
      
    }

    labelSize = newLabelSize;
  
}

void MenuCreator::execute()
{
    exitFlag = false;

    printChoice();
    printLabel();

    while(!exitFlag)
    {        
        button->checkButtons();
      
        if(button->buttonUp())
            currentChoice = (currentChoice + 1) % titleSize;
        else if(button->buttonDown())
        {
            currentChoice--;

            if(currentChoice < 0)
                currentChoice = titleSize - 1;
          
        }
        else if(button->buttonOk())
            menuFunctions(currentChoice);
    
        printChoice();
        printLabel();
      
    }
  
}

void MenuCreator::printLaunchMode()
{
    printer->Clear();
    printer->WriteL1("Launch mode");
  
}

void MenuCreator::printChoice()
{
    printer->Clear();
    printer->WriteL1("-> ");
    printer->WriteL1(titleList[currentChoice], 3);
  
}

