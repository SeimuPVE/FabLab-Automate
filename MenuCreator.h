#ifndef MENUCREATOR
#define MENUCREATOR

#include "Arduino.h"


class MenuCreator
{
    private:
        char **titleList;
        char **labelList;
        int titleSize;
        int labelSize;
        int currentChoice;

        bool buttonUpState;
        bool buttonDownState;
        bool buttonOkState;
        
    public:
        MenuCreator();

        void setTitles(String newTitleList[], int newTitleSize);
        void setLabels(String newLabelList[], int newLabelSize);
        void execute();

        virtual void menuFunctions(int choice) = 0;
        
        void checkButtons();
        bool buttonUp();
        bool buttonDown();
        bool buttonOk();

        void printLaunchMode();
        void printChoice();

};

#endif

