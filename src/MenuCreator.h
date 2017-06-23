#ifndef MENUCREATOR
#define MENUCREATOR

#include "Arduino.h"
#include "Printer.h"
#include "Button.h"

#define SELECTOR_CLASSIC "-> "
#define SELECTOR_SIMPLE ">"


/**
 * Abstract class to prepare a new menu.
 */
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
        /**
         * Constructor.
         * @param newPrinter : way to print information.
         * @param newButton : button to navigate in the menu.
         */
        MenuCreator(Printer *newPrinter, Button *newButton);

        /**
         * Setter for exitFlag.
         * @param newExitFlag : new exitFlag.
         */
        void setExitFlag(bool newExitFlag);

        /**
         * Set titles of the menu.
         * @param newTitleList : list of titles.
         * @param newTitleSize : list size.
         */
        void setTitles(String newTitleList[], unsigned int newTitleSize);
        /**
         * Execute the menu.
         */
        void execute();

        /**
         * Prepare all methods in the menu in function of the choice.
         * @param choice
         */
        virtual void menuFunctions(unsigned int choice) = 0;

        /**
         * Print the selected choice.
         */
        void printChoice();
        /**
         * Print the labels.
         */
        virtual void printLabel() = 0;

};

#endif

