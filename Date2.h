#pragma once
#include <iostream>
using namespace std;

class Date {												//a class that contains date information
private:													//private data members of the class
	int Day;												//day
	int Month;											//month
	int Year;											//year
public:														//public functions to be accessed
	Date();													//default constructor
	Date(int day, int month, int year);			//parameterized constructor
	Date(Date& d2);											//copy constructor
	~Date();

	void setday(int day_);
	void setmonth(int month_);
	void setyear(int year_);

	int& getday();
	int& getmonth();
	int& getyear();

	void printdate() const;




};