//This program allows the user to calculate how many days they should isolate based on their test results, exposure, and vaccination status.
//Abigail Poropatich
//My Class: CPSC 1020 
//Date: 09/29/2022
//Time: ~20 hours (No joke)

#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>
#include "calcDays.h"
#include "Date.h"

using namespace std;

int main(){
    char testResult;

    //Ask user for test results to begin menu
    cout << "Enter 'P' (Positive) or 'N' (Negative) test result: " << endl;
    cin >> testResult;

    //If user is positive
    if (testResult == 'P' || testResult == 'p'){
        Date positiveTest;
        int positiveDay, positiveMonth, positiveYear;

        //Prompt user for each month, day, and year individually so the check funciton can be implemented
        cout << "Test result: positive\n";
        cout << "Month tested positive: ";
        cin >> positiveMonth;
            if(!positiveTest.setMonth(positiveMonth)){
                Date();
            }
        cout << "\nDay tested positive: ";
        cin >> positiveDay;
            if(!positiveTest.setDay(positiveDay)){
                Date();
            }
        cout << "\nYear tested positive: ";
        cin >> positiveYear;
            if(!positiveTest.setYear(positiveYear)){
                Date();
            }
        cout << "\n";
        
        //Compile the date into a string with slashes and output hard coded isolation based on positive test results
        cout << "Date tested positive (MM/DD/YYYY): ";
        cout << positiveTest.showDate() << endl;
        cout << "Length of isolation: 5 days\n";
        
        return 0;
    }

    //If the user has entered that they are negative
    else if(testResult == 'N' || testResult == 'n'){
        Date positiveTest;
        char exposure;
        int positiveDay, positiveMonth, positiveYear;

        cout << "Test result: negative\n";
        cout << "Exposed to positive case 'Y' (Yes) or 'N' (No): ";
        cin >> exposure;

        //If user was negative and not exposed, they have a hard coded length of 0 days of isolation
        if(exposure == 'N' || exposure == 'n'){
            cout << "No\n" << "Length of isolation: 0 days\n";
            return 0;
        }

        //If the user says they were negative, but exposed
        else if(exposure == 'Y' || exposure == 'y'){
            Date exposed;
            char vaccine;
            int exposedM, exposedD, exposedY;

            //Ask user for their exposure date by individual objects so that the setter function may check its validity
            cout << "Yes\n";

            cout << "Month exposed: ";
            cin >> exposedM; 
                if(!exposed.setMonth(exposedM)){
                    Date();
                }
            cout << "Day exposed: ";
            cin >> exposedD;
                if(!exposed.setDay(exposedD)){
                    Date();
                } 
            cout << "Year exposed: ";
            cin >> exposedY;
                if(!exposed.setYear(exposedY)){
                    Date();
                }

            //Print the date in a string for the positive case exposure
            cout << "Date exposed to positive case (MM/DD/YYYY): ";
            cout << exposed.showDate() << endl;

            //Ask user if they have recieved the second dose of their vaccine
            cout << "Second vaccination dose recieved 'Y' (Yes) or 'N' (No): ";
            cin >> vaccine;

                    //If the user has not recieved second dose, they are negative, but they have been exposed...hard coded 10 days of isolation
                    if(vaccine == 'N' || vaccine == 'n'){
                        cout << "No\n" << "Vaccination status at time of exposure: not fully vaccinated\n" << "Length of isolation: 10 days" << endl;
                        return 0;
                    }

                    //If the user has the second dose of the vaccine, they are negative, but they have been exposed
                    else if(vaccine == 'Y' || vaccine == 'y'){
                        Date vaccineDate;
                        int vaccineM, vaccineD, vaccineY;
                        int daysCalc;

                        //Ask user when they got the second dose of their vaccine by individual objects so that the setter function can check validity
                        cout << "Month vaccine: ";
                        cin >> vaccineM; 
                            if(!vaccineDate.setMonth(vaccineM)){
                                Date();
                            }
                        cout << "Day vaccine: ";
                        cin >> vaccineD;
                            if(!vaccineDate.setDay(vaccineD)){
                                    Date();
                                } 
                        cout << "Year vaccine: ";
                        cin >> vaccineY;
                            if(!vaccineDate.setYear(vaccineY)){
                                    Date();
                                }

                        //Show date as a string
                        cout << vaccineDate.showDate() << endl;
                        cout << "Vaccination status at the time of exposure: ";

                        //Call the calcDays function so you can see how long its been since user got their second dose when compared to their exposure date
                        daysCalc = calcDays(exposed, vaccineDate);

                        //If it has been greater than 14 days since user had their second dose
                        if(daysCalc > 14){
                            cout << "fully vaccinated" << endl << "Length of isolation: 5 days" << endl;
                            return 0;
                        }

                        //If it has been less than or equal to 14 days since user got their second dose
                        else if(daysCalc <= 14){
                            cout << "not fully vaccinated" << endl << "Length of isolation: 10 days" << endl;
                            return 0;
                        }
                }
        }


    }

    return 0;
}