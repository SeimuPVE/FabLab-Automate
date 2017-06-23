#ifndef SETTINGS
#define SETTINGS

#include <Time.h>
#include "SaverLoader.h"
#include "WeekPlanning.h"

#define SEPARATOR ":"

#define LABEL_IS_CONTINUE "Continue"
#define LABEL_IS_PONCTUAL "Ponctual"
#define LABEL_IS_NO "Normaly open"
#define LABEL_IS_NC "Normaly close"


/**
 * Settings of the sensors.
 */
class Settings
{
    private:
        WeekPlanning *planning;
        time_t dateTime;
        bool iContinue; // TODO : rename it.
        unsigned int frequency;
        unsigned int interval;
        unsigned int sample_size;
        unsigned int bornSup;
        unsigned int bornInf;
        bool normalyOpen;

    public:
        /**
         * Constructor.
         */
        Settings();
        /**
         * Destructor.
         */
        ~Settings();

        /**
         * Get the planning in the settings.
         * @return : planning in the settings.
         */
        WeekPlanning *getPlanning() const;
        /**
         * Get the current time.
         * @return : current time.
         */
        time_t getDateTime() const;
        /**
         * Get if the mode is continue or ponctual.
         * @return : true if it's continue, false else.
         */
        bool isContinue() const;
        /**
         * Get the frequency of capture.
         * @return : frequency of capture.
         */
        unsigned int getFrequency() const;
        /**
         * Get the interval between two ponctuals captures.
         * @return : interval between two ponctuals captures.
         */
        unsigned int getInterval() const;
        /**
         * Get the size of a sample for the average.
         * @return : sample size.
         */
        unsigned int getSample_size() const;
        /**
         * Get the superior born before changing relay state.
         * @return
         */
        unsigned int getBornSup() const;
        /**
         * Get the inferior born before changing relay state.
         * @return
         */
        unsigned int getBornInf() const;
        /**
         * Check if the relay is normaly open or normaly closed.
         * @return : true if the relay is normaly open, false else.
         */
        bool isNO() const;

        /**
         * Change the current date and time.
         * @param hour : new hour.
         * @param minute : new minute.
         * @param day : new day.
         * @param month : new month.
         * @param year : new year.
         */
        void setDateTime(unsigned int hour, unsigned int minute, unsigned int day, unsigned int month, unsigned int year);
        /**
         * Change the parameter continue value.
         * @param newContinue : new value.
         */
        void setContinue(bool newContinue);
        /**
         * Change the frequency of the capture for continue mode.
         * @param newNumberCounts : new frequency.
         */
        void setFrequency(unsigned int newNumberCounts);
        /**
         * change the interval between twe captures for the ponctual mode.
         * @param interval : new interval.
         */
        void setInterval(unsigned int interval);
        /**
         * Change the sample size for the average.
         * @param sample_size : new sample size.
         */
        void setSample_size(unsigned int sample_size);
        /**
         * Set the new superior born.
         * @param newBornSup : new superior born.
         */
        void setBornSup(unsigned int newBornSup);
        /**
         * Set the new inferior born.
         * @param newBornInf : new inferior born.
         */
        void setBornInf(unsigned int newBornInf);
        /**
         * Set if the relay is normaly open or normaly closed.
         * @param newNO : new relay state.
         */
        void setNO(bool newNO);

        /**
         * Change a selected day planning.
         * @param dayTag : tag of the day to find it.
         * @param startingHour : new starting hour.
         * @param startingMinute : new starting minute.
         * @param endingHour : new ending hour.
         * @param endingMinute : new ending minute.
         */
        void setDay(unsigned int dayTag, unsigned int startingHour, unsigned int startingMinute, unsigned int endingHour, unsigned int endingMinute);

        /**
         * Get a String to print a day on the LCD screen.
         * @param dayTag : day tag to find it.
         * @return : String to print the day.
         */
        String getStrDay(unsigned int dayTag);
        /**
         * Get a String to print the current date on the LCD screen.
         * @return : String to print the current date.
         */
        String getStrCurrentDate();
        /**
         * Get a String to print if the mode is continue or not on the LCD screen.
         * @return : String to print if continue or not.
         */
        String getStrIsContinue();
        /**
         * Get a String to print the borns on the LCD screen.
         * @return : String to print the borns.
         */
        String getStrBorns();
        /**
         * Get a String to print if the relay is NO or NC on the LCD screen.
         * @return : String to print the relay mode.
         */
        String getStrNormalyOpen();

        /**
         * Save the settings on the EEPROM memory.
         */
        void save();
        /**
         * Load the settings on the EEPROM memory.
         */
        void load();

};

#endif
