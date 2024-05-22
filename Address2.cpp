#include <iostream>
#include "Address2.h"
#include "Customers2.h"
#include <string>
using namespace std;

//constructors
	//Default constructor
Address::Address() {
	Email = "Empty@";
	City = "Empty";
	MobileNum = "0000";
	StreetName = "Empty";

}
//Parameterized constructor
Address::Address(string email, string city, string mobilenum, string street) {
	setEmail(email);
	setCity(city);
	setMobile(mobilenum);
	setStreet(street);

}
//Copy constructor
Address::Address(Address& obj) {
	setEmail(obj.getEmail());
	setCity(obj.getCity());
	setMobile(obj.getMobile());
	setStreet(obj.getStreet());
}
//Destructor
Address::~Address() {}

//Setters
	//Email setter
		//Validation used
			/*1)No empty email inputs
			  2)Ask user to renter email in case invalid input is made*/
void Address::setEmail(string email_) {
	while (CheckEmail(email_, '@')) {
		cout << "Invalid email input, enter email again (empty entries are not allowed): " << endl;
		getline(cin, email_);	//ask user to renter email input
	}
	Email = email_;
}

//City setter
	//Validations used:
		/*1)No empty city inputs
		  2)No Numbers or Symbols in name inputs
		  3)Ask user to renter name in case invalid input is made*/
void Address::setCity(string city_) {

	for (int i = 0; i < 2; i++) {
		if (Customer::CheckNonLetter(city_)) { City = city_; }
		else {
			cout << "Invalid city input, enter city again (Non-letter values or empty entries are not allowed): " << endl;
			i--; 	//resets main loop to ask user to renter city input
			getline(cin, city_);
		}
	}
}
//Mobile number setter
	//Validations used:
		/*1)No empty mobile number inputs
		  2)Only numerical entries are allowed
		  3)Ask user to renter phone number in case invalid input is made*/
void Address::setMobile(string num_) {

	for (int i = 0; i < 2; i++) {
		if (Customer::CheckNonNumber(num_)) { MobileNum = num_; }
		else {
			cout << "Invalid phone number input, enter phone number again (Non-number values or empty entries are not allowed): " << endl;
			i--; 	//resets main loop to ask user to renter phone number input
			getline(cin, num_);
		}
	}
}
//Street name setter
	//Validations used:
		/*1)No empty street name inputs
		  2)Ask user to renter name in case invalid input is made*/
void Address::setStreet(string street_) {
	while (street_ == "") {
		cout << "Invalid street input, enter street again (empty entries are not allowed): " << endl;
		getline(cin, street_); //resets main loop to ask user to renter street input
	}StreetName = street_;
}


//Getters
string Address::getEmail() {
	return Email;
}
string Address::getCity() {
	return City;
}
string Address::getMobile() {
	return MobileNum;
}
string Address::getStreet() {
	return StreetName;
}

//Member functions
void Address::PrintAddress() const {			//Function that prints address information
	cout << "        Email:  " << Email << endl;
	cout << "         City:  " << City << endl;
	cout << "Mobile number:  " << MobileNum << endl;
	cout << "  Street Name:  " << StreetName << endl;
}

bool Address::CheckEmail(string str, char c)  //Function that checks if the passed string contains the passed character or not.
{
	int flag = 0;
	for (int j = 0; j < str.length(); j++)
	{
		if (str[j] == c)
		{
			flag++; break;
		}
	}
	if (flag == 0 || str == "") {
		return true;
	}
	else { return false; }

}