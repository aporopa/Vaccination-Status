#ifndef DATE_H_
#define DATE_H_
#include <string>

using namespace std;

class Date{

    private:
        //Default variables
        int day {1};
        int month {1};
        int year {2021};
    
    public:
        //constructors
        Date() = default;
        Date(int d, int m, int y);

        //getter functions
        int getDay() const;
        int getMonth() const;
        int getYear() const;

        //setter functions
        bool setDay(int);
        bool setMonth(int);
        bool setYear(int);

        //string function
        string showDate();
};

#endif