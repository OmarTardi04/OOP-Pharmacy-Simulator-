#pragma once
#include <iostream>
#include "Address2.h"
#include "Customers2.h"
#include "Date2.h"
#include "Medications2.h"
using namespace std;

class Medication			//A class that is responsible for storing attributes of medications
{
private:					//Data members:
	string Name;			//Name of medication
	string Description;		//Description of medication
	float Price;			//Medication price
	int Stock;				//Medication stock
	Date ExpiryDate;		//Medication Expiry date
	string Barcode;			//Medication Barcode
	const int MedID;
	static int NumOfMeds;

public:
	//Constructors
	Medication();
	Medication(string , string , float , int , Date& , string );
	Medication(Medication&);
	//setters
	void SetName(string n);
	void SetDescription(string d);
	void SetPrice(float p);
	void SetStock(int s);
	void SetExpiryDate(Date& myDate);
	void SetBarcode(string b);

	//getters
	string GetName();
	string GetDescription();
	float GetPrice();
	int GetStock();
	Date& GetExpiryDate();
	string GetBarcode();
	int GetMedID() const;

	//functions
	void print()const;
};


class OffTheShelf : public Medication {
private:
	bool BOGOF;
	Date OfferEnds;

public:
	// Constructors
	OffTheShelf();
	OffTheShelf(string name, string description, float price, int stock, Date expiryDate, string barcode, bool bogof,Date Offer);

	// Setters and getters
	void setBOGOF(bool bogof);
	bool getBOGOF() const;

	const Date& getOfferEnds() const;
	void setOfferEnds(Date date);

	// Print method
	void print() const;
};


class Prescriptions :public Medication {									// class that contains prescription medication info, that inherits Medication class
private:
	int FDANumber;														// FDA number
	Date ApprovalDate;													// Approval Date
public:
	Prescriptions();																															// Default contstructor
	Prescriptions(int fdaNumber, Date appDate_, string name_, string description_, float price_, int stock_, Date& expDate_, string barcode_);	// Parameterized constructor
	void setfdanumber(int num);																													// FDA number setter
	void setappDate(Date d);																													// Approval date setter
	int getfdanumber();																															// FDA number getter
	Date getappdate();																															// Approval date getter

	void print();																																// function that prints the medication information as well as FDA number and Approval date 
};