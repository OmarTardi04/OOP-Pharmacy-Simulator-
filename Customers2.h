#pragma once
#include <iostream>
#include <string>	
#include "Address2.h"
using namespace std;

class Customer {									//a class that manages the pharmacy's customer attributes
private:											//private data members for customer's attributes
	string Name;									//customer name							
	Address CustomerAddress;						//customer address (Contains email, city, mobile number, street name)
	const int CustomerId;							//customer's id that is set when they were enrolled
	static int NumOfCustomers;						//Customer counter
public:												//public functions to be accessed
	Customer();										//default constructor
	Customer(string, Address );		//parameterized constructor
	Customer(Customer& obj);						//copy constructor
	//setters:
	void SetName(string);
	void SetAddress(Address address_);

	//getters:
	string GetName();
	Address& GetAddress();	//returns address by refernce to allow setting each distinct attribute from the customer's address
	int GetId() const;
	//member functions:
	void Print()const;
	static bool CheckNonLetter(string str);	//checks if string contains any entries that aren't letters
	static bool CheckNonNumber(string str); //checks if string contains any entries that aren't numbers
};