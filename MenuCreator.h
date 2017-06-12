#ifndef MENUCREATOR
#define MENUCREATOR

#include "Arduino.h"


class MenuCreator
{
    private:
        char **titleList;
        int listSize;
        int currentChoice;
        void (*functions)(int);

        bool buttonUpState;
        bool buttonDownState;
        bool buttonOkState;
        
    public:
        MenuCreator(String newTitleList[], int newListSize, void (*newFunctions)(int));
        void launchMenu();
        
        void printLaunchMode();
        void printChoice();

        void checkButtons();
        bool buttonUp();
        bool buttonDown();
        bool buttonOk();
  
};

#endif

