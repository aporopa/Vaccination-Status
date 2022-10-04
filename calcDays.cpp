#include <cmath>
#include "Date.h"
#include "calcDays.h"

int calcDays(Date date1, Date date2){

    //Make an array of cummulative days according to what month it is
    int calendar[12] = {31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365};
    int daysDiff1 = 0;
    int daysDiff2 = 0;
    int day1 = date1.getDay();
    int day2 = date2.getDay();
    int month1 = date1.getMonth();
    int month2 = date2.getMonth();
    const int daysInYear = 365;

    
        //Converting years to days for date1
        daysDiff1 = (date1.getYear() * daysInYear) + calendar[month1] + day1;
    

        //Converting years to days for date2
        daysDiff2 = (date2.getYear() * daysInYear) + calendar[month2] + day2;
    

    //return the absolute value of the difference between each set of days
    return (abs(daysDiff1 - daysDiff2));

}
