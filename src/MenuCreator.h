#ifndef MENUCREATOR
#define MENUCREATOR

#include "Arduino.h"
#include "Printer.h"
#include "Button.h"

#define SELECTOR_CLASSIC "-> "
#define SELECTOR_SIMPLE ">"


class MenuCreator
{
    protected:
        Printer *printer;
        Button *button;
        
        char **titleList;
        unsigned int titleSize;
        unsigned int currentChoice;

        bool exitFlag;

    public:
        MenuCreator(Printer *newPrinter, Button *newButton);

        void setExitFlag(bool newExitFlag);
        
        void setTitles(String newTitleList[], unsigned int newTitleSize);
        void execute();

        virtual void menuFunctions(unsigned int choice) = 0;
        
        void printChoice();
        virtual void printLabel() = 0;

};

#endif

