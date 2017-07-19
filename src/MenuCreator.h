#ifndef MENUCREATOR
#define MENUCREATOR

#include "Arduino.h"
#include "Printer.h"
#include "Button.h"

#define SELECTOR_CLASSIC "-> "
#define SELECTOR_SIMPLE ">"

#define TITLE_EXIT "Back"
#define LABEL_GO_BACK ""


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

        /**
         * Select a value in a given interval.
         * @param label : label to print on the first line of the screen.
         * @param super_incrementer : maximum value for progressive incrementer.
         * @param initialValue : initial value printed.
         * @param inf : minimal value in the interval.
         * @param sup : maximal value in the interval.
         * @return : value selected.
         */
        int selectBetweenInterval(String label, int super_incrementor, unsigned int initialValue, int inf = 0, int sup = 999);

        /**
        * Select a boolean in the menu.
        * @param label : label to print on the first line of the screen.
        * @param trueLabel : label to print if the value is true.
        * @param falseLabel : label to print if the value is false.
        * @param initialValue : initial value to print.
        * @return : value selected.
        */
        bool selectBoolean(String label, String trueLabel, String falseLabel, bool initialValue);

};

#endif
