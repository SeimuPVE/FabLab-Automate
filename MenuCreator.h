#ifndef MENUCREATOR
#define MENUCREATOR

#include "Arduino.h"


class MenuCreator
{
    private:
        char **titleList;
        int listSize;
        int currentChoice;

        bool buttonUpState;
        bool buttonDownState;
        bool buttonOkState;
        
    public:
        MenuCreator();

        void setTitles(String newTitleList[], int newListSize);
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

