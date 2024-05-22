#include <iostream>
#include <string>
#include "Customers2.h"
#include "Address2.h"

using namespace std;

int Customer::NumOfCustomers = 1;		//initializing static integer

//Constructors:
	//Default Constructor:
Customer::Customer() :CustomerId(NumOfCustomers++) {
	
	SetName("Empty");
	CustomerAddress.setEmail("Empty@");
	CustomerAddress.setCity("Empty");
	CustomerAddress.setMobile("0000");
	CustomerAddress.setStreet("Empty");
	
}
//Parameterized Constructor:
Customer::Customer(string name, Address address) :CustomerId(NumOfCustomers++) {

	SetName(name);
		 //Setters are used to ensure validation is applied
	SetAddress(address);

}
//Copy Constructor:
Customer::Customer(Customer& obj) :CustomerId(NumOfCustomers++), Name(obj.Name), CustomerAddress(obj.CustomerAddress) {}
//Setters:
	//Customer Name Setter:
		//Validations used:
			/*1)No empty name inputs
			  2)No Numbers or Symbols in name inputs
			  3)Ask user to renter name in case invalid input is made*/
void Customer::SetName(string name_) {

	for (int i = 0; i < 2; i++) {
		if (CheckNonLetter(name_)) { Name = name_; }
		else {
			cout << "Invalid name input, enter name again (Non-letter values or empty entries are not allowed): " << endl;
			i--; 	//resets main loop to ask user to renter name input
			getline(cin, name_);
		}
	}
}
//Customer Address Setter:
		//Validations used:
			/*1)No empty Address inputs
			  2)Ask user to renter address in case invalid input is made
			  Assumed addresses can have numerical values*/
void Customer::SetAddress(Address address_) {
	CustomerAddress.setEmail(address_.getEmail());
	CustomerAddress.setCity(address_.getCity());
	CustomerAddress.setMobile(address_.getMobile());
	CustomerAddress.setStreet(address_.getStreet());
}

//Getters:
string Customer::GetName() {
	return Name;
}
Address& Customer::GetAddress() {
	return CustomerAddress;
}
int Customer::GetId() const  {
	return CustomerId;
}
//Member Functions:
void Customer::Print() const {
	cout << endl;
	cout<< "         Name:  " << Name << endl;
	cout << "  Customer ID:  " << CustomerId << endl;
	CustomerAddress.PrintAddress();
}
bool Customer::CheckNonLetter(string str) //Function that checks if the passed string contains any non letter entries.
{
	int flag = 0;
	for (int j = 0; j < str.length(); j++)
	{
		if (str[j] < 65 && str[j] != 32 || (str[j] > 90 && str[j] < 97) || str[j]>123)
		{
			flag++; break;
		}
	}
	if (flag > 0 || str == "") {
		return false;
	}
	else { return true; }
}

bool Customer::CheckNonNumber(string str)  //Function that checks if the passed string contains any non numerical entries.
{
	int flag = 0;
	for (int j = 0; j < str.length(); j++)
	{
		if (str[j] < 48 || str[j] > 57)
		{
			flag++; break;
		}
	}
	if (flag > 0 || str == "") {
		return false;
	}
	else { return true; }

}




