#ifndef MENUCREATOR
#define MENUCREATOR

#include "Arduino.h"
#include "Printer.h"
#include "Button.h"


class MenuCreator
{
    protected:
        Printer *printer;
        Button *button;
        
        char **titleList;
        int titleSize;
        int currentChoice;

        bool exitFlag;

    public:
        MenuCreator(Printer *newPrinter, Button *newButton);

        void setExitFlag(bool newExitFlag);
        
        void setTitles(String newTitleList[], int newTitleSize);
        void execute();

        virtual void menuFunctions(int choice) = 0;
        
        void printChoice();
        virtual void printLabel() = 0;

};

#endif

