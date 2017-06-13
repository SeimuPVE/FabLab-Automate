#ifndef MENUCREATOR
#define MENUCREATOR

#include "Arduino.h"


class MenuCreator
{
    protected:
        char **titleList;
        char **labelList;
        int titleSize;
        int labelSize;
        int currentChoice;

        bool exitFlag;

        bool buttonUpState;
        bool buttonDownState;
        bool buttonOkState;
        
    public:
        MenuCreator();

        bool getExitFlag();
        void setExitFlag(bool newExitFlag);
        
        void setTitles(String newTitleList[], int newTitleSize);
        void setLabels(String newLabelList[], int newLabelSize);
        void execute();

        virtual void menuFunctions(int choice) = 0;
        
        void checkButtons();
        bool buttonUp();
        bool buttonDown();
        bool buttonOk();

        void printLaunchMode();
        virtual void printLabel() = 0;
        void printChoice();

};

#endif

