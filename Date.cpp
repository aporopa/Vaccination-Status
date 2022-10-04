#include <string>
#include <iomanip>
#include "Date.h"

//getter functions that will serve to fill the string function and input data into the calcDays function
Date::Date(int d, int m, int y) {
    day = d;
    month = m;
    year = y;

    if(setDay(d) == false || setMonth(m) == false || setYear(y) == false){
        day = 1;
        month = 1;
        year = 2021;
    }

}
int Date::getDay() const{
    return day;
}

int Date::getMonth() const{
    return month;
}

int Date::getYear() const{
    return year;
}

//setter functions that will check the validity of the users input
bool Date::setDay(int daySet){
    bool validate = true;

    if(((daySet <= 31) && (daySet > 0)) && (month == 1 || (month < 13 && month > 2)))
        day = daySet;

    else if(month == 2 && daySet > 28){
        validate = false;
    }
    else if (month == 2 && daySet <= 28){
        day = daySet;
    }
    
    else{
        validate = false;
        Date();
    }
    
    return validate;
}

bool Date::setMonth(int monthSet){
    bool validate = true;

    if((monthSet <= 12) && (monthSet >= 1))
        month = monthSet;
    
    else{
        validate = false;
        Date();
    }
    
    return validate;
}

bool Date::setYear(int yearSet){
    bool validate = true;

    if((yearSet == 2022) || (yearSet == 2021))
        year = yearSet;
    
    else{
        validate = false;
        Date();
    }

    return validate;
}

//Will compile the date data from user into a string that looks like a classic date with slashes
string Date::showDate(){
    string userDate;
    string userDay;
    string userMonth;

    userDay = to_string(day);
    userMonth = to_string(month);

    if (day < 10 && day > 0)
        userDay = "0" + userDay;
    else
        userDay = userDay;

    if (month < 10 && month > 0)
        userMonth = "0" + userMonth;
    else
        userMonth = userMonth;
    
    
    userDate = (userMonth + "/" + userDay + "/" + to_string(year)); 

    return (userDate);   
}