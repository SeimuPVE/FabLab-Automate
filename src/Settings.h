#ifndef SETTINGS
#define SETTINGS

#include <Time.h>
#include "SaverLoader.h"
#include "WeekPlanning.h"
#include "DS1302RTC.h"

#define PORT_CLK 12
#define PORT_DAT 11
#define PORT_RST 10

#define SAVER_STARTING_ADDRESS 0

#define SEPARATOR ":"

#define LABEL_IS_CONTINUE "Continue"
#define LABEL_IS_RECURRENT "Recurrent"
#define LABEL_IS_CRASH_MODE "Stop when error"
#define LABEL_IS_NOT_CRASH_MODE "Manage errors"
#define LABEL_IS_NO "ON"
#define LABEL_IS_NC "OFF"


/**
 * Settings of the sensors.
 */
class Settings
{
    private:
        WeekPlanning *planning;
        DS1302RTC *rtc = new DS1302RTC(PORT_RST, PORT_DAT, PORT_CLK);
        bool continueMode;
        bool crashMode;
        unsigned int frequency;
        unsigned int interval;
        unsigned int sample_size;
        unsigned int bornSup;
        unsigned int bornInf;
        bool normallyOpen;

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
         * Get if the mode is continue or recurrent.
         * @return : true if it's continue, false else.
         */
        bool isContinue() const;

        /**
         * Get if it's the crash mode or the automatic control mode.
         * @return : true if it's crash mode, false else.
         */
        bool isCrashMode() const;

        /**
         * Get the frequency of capture.
         * @return : frequency of capture.
         */
        unsigned int getFrequency() const;

        /**
         * Get the interval between two recurrent captures.
         * @return : interval between two recurrent captures.
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
         * Check if the relay is normally open or normally closed.
         * @return : true if the relay is normally open, false else.
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
         * Change the crash mode type.
         * @param newCrashMode : new value.
         */
        void setCrashMode(bool newCrashMode);

        /**
         * Change the frequency of the capture for continue mode.
         * @param newNumberCounts : new frequency.
         */
        void setFrequency(unsigned int newNumberCounts);

        /**
         * Change the interval between twe captures for the recurrent mode.
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
         * Set if the relay is normally open or normally closed.
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
         * Get a String to print if the mode manage errors or not on the LCD screen.
         * @return : String to print if manage errors or not.
         */
        String getStrIsCrashMode();

        /**
         * Get a String to print the intervals on the LCD screen.
         * @return : String to print the intervals.
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
