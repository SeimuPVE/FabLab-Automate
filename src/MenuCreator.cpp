#include "MenuCreator.h"


MenuCreator::MenuCreator(Printer *newPrinter, Button *newButton)
{
    printer = newPrinter;
    button = newButton;
    
    currentChoice = 0;

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

void MenuCreator::printChoice()
{
    printer->Clear();
    printer->WriteL1("-> ");
    printer->WriteL1(titleList[currentChoice], 3);
  
}

