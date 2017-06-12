#include "Arduino.h"
#include "MenuCreator.h"
#include "Tools.h"


class MainMenu : public MenuCreator
{
    private:
        // Nothing.

    public:
        MainMenu();
        
        void menuFunctions(int choice);
        
        void modeNormal();
        void modeMesure();
        void modeTest();
        void modeSettings();
  
};

