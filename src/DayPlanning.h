#ifndef DAYPLANNING
#define DAYPLANNING

#include "Arduino.h"
#include "Printer.h"


/**
 * Planning of a day.
 */
class DayPlanning
{
    private:
        String dayName;
        unsigned int startingHour;
        unsigned int startingMinute;
        unsigned int endingHour;
        unsigned int endingMinute;

    public:
        /**
         * Constructor. Set default values.
         */
        DayPlanning();
        /**
         * Constructor.
         * @param newDayName : day name.
         * @param newStartingTime : starting time at format "HH:mm".
         * @param newEndingTime : ending time at format "HH:mm".
         */
        DayPlanning(String newDayName, String newStartingTime, String newEndingTime);

        /**
         * Get the name of the day.
         * @return : name of the day.
         */
        String getDayName();
        /**
         * Get the starting hour.
         * @return : starting hour.
         */
        unsigned int getStartingHour() const;
        /**
         * Get the starting minute.
         * @return starting minute.
         */
        unsigned int getStartingMinute() const;
        /**
         * Get the ending hour.
         * @return : ending hour.
         */
        unsigned int getEndingHour() const;
        /**
         * Get the ending minute.
         * @return : ending minute.
         */
        unsigned int getEndingMinute() const;

        /**
         * Set a name for the day.
         * @param newDayName : new day name.
         */
        void setDayName(String newDayName);
        /**
         * Set a starting hour for the day.
         * @param newStartingHour : new starting hour.
         */
        void setStartingHour(unsigned int newStartingHour);
        /**
         * Set a starting minute for the day.
         * @param newStartingMinute : new starting minute.
         */
        void setStartingMinute(unsigned int newStartingMinute);
        /**
         * Set a new ending hour for the day.
         * @param newEndingHour : new ending hour.
         */
        void setEndingHour(unsigned int newEndingHour);
        /**
         * Set a new ending minute for the day.
         * @param newEndingMinute : new ending minute.
         */
        void setEndingMinute(unsigned int newEndingMinute);

        /**
         * Get the starting time at String format like "HH:mm"
         * @return : starting time at String format.
         */
        String getStartingTime();
        /**
         * Get the ending time at String format like "HH:mm"
         * @return : ending time at String format.
         */
        String getEndingTime();

        /**
         * Check if the timer is at a good String format.
         * @param timer : timer to check.
         * @return : true if the format is good, false else.
         */
        bool isValidTimer(String timer);
        /**
         * Get the hour from a given timer at format "HH:mm".
         * @param timer : timer to check.
         * @return : hour from the timer.
         */
        unsigned int getHours(String timer) const;
        /**
         * Get the minute from a given timer at format "HH:mm".
         * @param timer : timer to check.
         * @return : minute from the timer.
         */
        unsigned int getMinutes(String timer) const;

        /**
         * Set a new starting time from a timer at format "HH:mm".
         * @param timer : timer to use.
         */
        void setStartingTime(String timer);
        /**
         * Set a new ending time from a timer at format "HH:mm".
         * @param timer : timer to use.
         */
        void setEndingTime(String timer);
  
};

#endif
