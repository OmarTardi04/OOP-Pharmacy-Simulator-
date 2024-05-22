#include <iostream>
#include <string>
#include "Date2.h"
using namespace std;

//Constructors
    //default constructor
Date::Date() {
    Day = 1;
    Month = 1;
    Year = 2024;

}
//parameterized constructor
Date::Date(int day, int month, int year) {
    setday(day);
    setmonth(month);
    setyear(year);

}
//copy constructor
Date::Date(Date& d2) {
    Day = d2.getday();
    Month = d2.getmonth();
    Year = d2.getyear();
}

Date::~Date() {}

//Setters
    //day setter
        //Validations used:
            /*1)Only days between 0 and 31 inclusive allowed
              2)Ask user to renter in case invalid day input is made*/
void Date::setday(int day_) {
    for (int i = 0; i < 2; i++) {
        if (day_ > 0 && day_ < 32) { Day = day_; }
        else {
            cout << "Invalid day input, enter day again (day less than 1 or greater than 31 not allowed): " << endl;
            i--; 	//resets main loop to ask user to renter day input
            cin >> day_;
        }
    }

}
//month setter
    //Validations used:
        /*1)Only month between 0 and 12 inclusive allowed
          2)Makes sure that days and months are compatible
          3)ensures months with 30 days can't have 31 days
          4)ensures February has 29 days only
          3)Ask user to renter  in case invalid month input is made*/
void Date::setmonth(int month_) {

    for (int i = 0; i < 2; i++) {
        if (month_ < 1 || month_ > 12) {
            cout << "Invalid month input, please enter month between [1,12] inclusive." << endl;
            i--;
            cin >> month_;
        }
        else if (month_ == 2 && Day > 29) {
            cout << "Invalid input, February has 29 days only please enter day again." << endl;
            i--;
            int day;
            cin >> day;
            setday(day);
        }
        else if ((month_ == 4 || month_ == 6 || month_ == 9 || month_ == 11) && Day == 31) {
            cout << "Invalid input, the month entered has 30 days only please enter day again." << endl;
            i--;
            int day;
            cin >> day;
            setday(day);
        }
        else { Month = month_; }
    }
}
//year setter
    //Validations used:
        /*1)Only positive years allowed
          2)Ask user to renter  in case invalid year input is made*/
void Date::setyear(int year_) {
    for (int i = 0; i < 2; i++) {
        if (year_ > 0) { Year = year_; }
        else {
            cout << "Invalid year input, enter year again (negative year not allowed): " << endl;
            i--; 	//resets main loop to ask user to renter year input
            cin >> year_;
        }
    }
}
//Getters
int& Date::getday() {
    return Day;
}
int& Date::getmonth() {
    return Month;
}
int& Date::getyear() {
    return Year;
}

//Member functions
void Date::printdate()const {

    cout << ((Day < 10) ? "0" : "") << Day << "/";
    cout << ((Month < 10) ? "0" : "") << Month << "/";
    cout << Year << endl;

}
