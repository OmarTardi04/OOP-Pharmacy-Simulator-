#pragma once
#include <iostream>
using namespace std;

class Address {																//a class that contains address information
private:																	//private data members for the address
	string Email;															//email address
	string City;															//city name
	string MobileNum;														//mobile number
	string StreetName;														//street name
public:																		//public functions to be accessed
	Address();																//default constructor
	Address(string email, string city, string mobilenum, string street);	//parameterized constructor
	Address(Address& obj);													//copy constructor
	~Address();																//destructor

	//setters
	void setEmail(string email_);
	void setCity(string city_);
	void setMobile(string num_);
	void setStreet(string street_);

	//getters
	string getEmail();
	string getCity();
	string getMobile();
	string getStreet();

	//member functions
	void PrintAddress() const;
	bool CheckEmail(string, char);  //Function that checks if the passed string contains @ or not.

};
