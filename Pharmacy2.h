#pragma once
#include "Customers2.h"
#include "Medications2.h"
using namespace std;

class Pharmacy {
private:
	const int PharmacyID;									//Pharmacy ID generated sequentially
	static int PharmacyCounter;								//Counter to generate ID
	string PharmacyName;									//String data member to store pharmacy name
	Customer* PCustomers;								//Pointer used to point to dynamic customers array
	Medication* PMedications;							//Pointer used to point to dynamic medications array
	int Msize, Csize;									//Dynamic array size for medication and customer array

public:
	Pharmacy();
	Pharmacy(string, Customer Carr[], Medication Marr[],int,int);
	~Pharmacy();

	//Setters:
	void SetName(string);				//sets pharmacy name
	void SetMptr(Medication*);			//sets medication pointer
	void SetCptr(Customer*);			//sets customer pointer
	//Getters:
	string& GetName();					//returns pharmacy name
	Medication& GetMed(int);			//returs medication from medication array from the given index
	int GetMsize();						//returns the medication array size
	int GetCsize();						//returns the customers array size
	Medication* GetMptr();				//Returns the pointer that points to the medication arary 
	Customer* GetCptr();				//Returns the pointer that points to the customers arary
	//Member functions:


	void addMed(Medication& Mdetails);			//Adds medication to medications dynamic array 
	
	void remMed(string medName);				//removes medication from dynamic medications array

	void addCust(Customer& Cdetails);			//Adds customers to customers dynamic array 

	bool disMed();								//Displays medications in stock
	
	bool disCust();								//Displays pharmacy's customers
												
	void medCount(Pharmacy& ob);				//Comparing medication count between 2 pharmacies
	
	void custCount(Pharmacy& ob);				//Comparing customer count between 2 pharmacies
};