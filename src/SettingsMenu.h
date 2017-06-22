#ifndef SETTINGSMENU
#define SETTINGSMENU

#include "Arduino.h"
#include "Time.h"
#include "MenuCreator.h"
#include "Settings.h"
#include "WeekPlanning.h"

#define TITLE_DATE "Date"
#define TITLE_CONTINUE "Continue"
#define TITLE_BORNS "Borns"
#define TITLE_NO "NO/NC"
#define TITLE_EXIT "Exit"

#define SELECTOR_STARTING_HOUR "Start H"
#define SELECTOR_STARTING_MINUTE "Start min"
#define SELECTOR_ENDING_HOUR "End H"
#define SELECTOR_ENDING_MINUTE "End min"
#define SELECTOR_HOUR "Select H"
#define SELECTOR_MINUTE "Select min"
#define SELECTOR_DAY "Select day"
#define SELECTOR_MONTH "Select month"
#define SELECTOR_YEAR "Select year"

#define SELECTOR_CONTINUE "Set continue"
#define SELECTOR_IS_CONTINUE "Continue"
#define SELECTOR_IS_PONCTUAL "Ponctual"
#define SELECTOR_FREQUENCY "Calculs by H"
#define SELECTOR_INTERVAL "Delay in seconds"
#define SELECTOR_SAMPLE_SIZE "Sample size"
#define SELECTOR_BORN_SUP "Born sup"
#define SELECTOR_BORN_INF "Born inf"
#define SELECTOR_NO "Set NO/NC"
#define SELECTOR_IS_NO "Normaly open"
#define SELECTOR_IS_NC "Normaly close"

#define LABEL_GO_BACK "Go back"


class SettingsMenu : public MenuCreator
{
    private:
        Settings *settings;

    public:
        SettingsMenu(Printer *printer, Button *newButton, Settings *settings);

        void menuFunctions(unsigned int choice);

        void setDay(unsigned int dayTag);

        void setMonday();
        void setTuesday();
        void setWednesday();
        void setThursday();
        void setFriday();
        void setSaturday();
        void setSunday();

        void setDate();
        void setContinue();
        void setBorns();
        void setNO();

        void setSettings(Settings *newSettings);

        unsigned int selectBetweenInterval(String label, bool super_incrementor, unsigned int initialValue, unsigned int inf = 0, unsigned int sup = 999);
        bool selectBoolean(String label, String trueLabel, String falseLabel, bool initialValue);

        void printLabel();

};

#endif
