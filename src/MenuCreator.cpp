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

void MenuCreator::setTitles(String newTitleList[], unsigned int newTitleSize)
{
    if((titleList = (char **) malloc(newTitleSize * sizeof(char *))) == NULL)
        Serial.println("Memory error : can't create title list in the menu creator.");
    
    for(unsigned int i = 0; i < newTitleSize; i++)
    {
        if((titleList[i] = (char *) malloc((newTitleList[i].length() + 1) * sizeof(char))) == NULL)
            Serial.println("Memory error : can't add title to the list in the menu creator.");
        
        newTitleList[i].toCharArray(titleList[i], newTitleList[i].length() + 1);

    }

    titleSize = newTitleSize;
  
}

void MenuCreator::execute()
{
    currentChoice = 0;
    exitFlag = false;

    printChoice();
    if(titleSize != 4)
        printLabel();

    while(!exitFlag)
    {
        button->checkButtons();
      
        if(button->buttonUp())
        {
            currentChoice++;

            if(currentChoice >= titleSize - 1)
                currentChoice = titleSize - 1;

        }
        else if(button->buttonDown())
        {
            if(currentChoice != 0)
                currentChoice--;

        }
        else if(button->buttonOk())
            menuFunctions(currentChoice);
    
        printChoice();
        if(titleSize != 4)
            printLabel();
      
    }

    currentChoice = 0;

}

void MenuCreator::printChoice()
{
    printer->Clear();

    if(titleSize == 4)
    {
        if(currentChoice == 0)
            printer->WriteL1(F(SELECTOR_SIMPLE), 0);
        printer->WriteL1(titleList[0], 1);

        if(currentChoice == 1)
            printer->WriteL1(F(SELECTOR_SIMPLE), 7);
        printer->WriteL1(titleList[1], 8);

        if(currentChoice == 2)
            printer->WriteL2(F(SELECTOR_SIMPLE), 0);
        printer->WriteL2(titleList[2], 1);

        if(currentChoice == 3)
            printer->WriteL2(F(SELECTOR_SIMPLE), 7);
        printer->WriteL2(titleList[3], 8);

    }
    else
    {
        printer->WriteL1(F(SELECTOR_CLASSIC));
        printer->WriteL1(titleList[currentChoice], 3);

    }

}

int MenuCreator::selectBetweenInterval(String label, int super_incrementor, unsigned int initialValue, int inf, int sup)
{
    unsigned int positif_incrementer = 0, negatif_incrementer = 0;
    int result = initialValue;

    printer->Clear();
    printer->WriteL1(label);
    printer->WriteL2(result);

    while(!button->buttonOk())
    {
        button->checkButtons();

        if(button->buttonUp())
        {
            negatif_incrementer = 0;
            if(positif_incrementer < super_incrementor)
                positif_incrementer += positif_incrementer + 1;

            result += positif_incrementer;

            if(result > sup)
                result = inf;

            printer->Clear();
            printer->WriteL1(label);
            printer->WriteL2(result);

        }
        else if(button->buttonDown())
        {
            positif_incrementer = 0;
            if(negatif_incrementer < super_incrementor)
                negatif_incrementer += negatif_incrementer + 1;

            result -= negatif_incrementer;

            if(result < inf)
                result = sup;

            printer->Clear();
            printer->WriteL1(label);
            printer->WriteL2(result);

        }

    }

    return result;

}

bool MenuCreator::selectBoolean(String label, String trueLabel, String falseLabel, bool initialValue)
{
    bool result = initialValue;

    printer->Clear();
    printer->WriteL1(label);
    if(result)
        printer->WriteL2(trueLabel);
    else
        printer->WriteL2(falseLabel);

    while(!button->buttonOk())
    {
        button->checkButtons();

        if(button->buttonUp() || button->buttonDown())
        {
            result = !result;

            printer->Clear();
            printer->WriteL1(label);
            if(result)
                printer->WriteL2(trueLabel);
            else
                printer->WriteL2(falseLabel);

        }

    }

    return result;

}
