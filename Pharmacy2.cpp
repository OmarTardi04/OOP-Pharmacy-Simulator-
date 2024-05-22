#include <iostream>
#include <string>
#include "Pharmacy2.h"
using namespace std;

int Pharmacy::PharmacyCounter = 1;
Address DefAdd;	//defualt address 
Date DefDate;	//defualt date

//Constsructor that initializes pharmacy name/ customers pointer/ Medications pointer
Pharmacy::Pharmacy() :PharmacyID(PharmacyCounter++) {
	PharmacyName = "Empty";
	PCustomers = nullptr;							
	PMedications = nullptr;		
	Csize = 0;
	Msize = 0;

}

Pharmacy::Pharmacy(string PName, Customer Carr[], Medication Marr[],int ms,int cs) :PharmacyID(PharmacyCounter++) {
	Msize = ms;
	Csize = cs;
	PharmacyName = PName;
	PCustomers = new Customer[cs];
	PMedications = new Medication[ms];

	for (int i = 0; i < cs; i++) {
		PCustomers[i].SetName(Carr[i].GetName());
		PCustomers[i].SetAddress(Carr[i].GetAddress());
	}
	for (int i = 0; i < ms; i++) {
		PMedications[i].SetName(Marr[i].GetName());
		PMedications[i].SetDescription(Marr[i].GetDescription());
		PMedications[i].SetPrice(Marr[i].GetPrice());
		PMedications[i].SetStock(Marr[i].GetStock());
		PMedications[i].SetExpiryDate(Marr[i].GetExpiryDate());
		PMedications[i].SetBarcode(Marr[i].GetBarcode());
	}
}
//Destructor that decrements the number of pharmacies when a pharmacy is permanently closed
Pharmacy::~Pharmacy() { 
	PharmacyCounter--;
	delete[] PCustomers;
	delete[] PMedications;
}

//Setters:
//SetName() : Sets pharmacy name and has the following validations:
				//1) No empty input is allowed
				//2) Keep asking user for input until valid input is given
			  //Assumption made: Pharmacy names can include symbols and numbers (Ex. Pharmacy-1)
void Pharmacy::SetName(string name) {
	while (name == "") {
		cout << endl << "Invalid pharmacy name (Empty input not allowed): ";
		cin.ignore();
		getline(cin, name);
	}
	PharmacyName = name;
}

void Pharmacy::SetMptr(Medication* Mp) { PMedications = Mp; }
void Pharmacy::SetCptr(Customer* Cp) { PCustomers = Cp; }

//Getters:
string& Pharmacy::GetName() { return PharmacyName; }
Medication& Pharmacy::GetMed(int a) { return PMedications[a]; }
int Pharmacy::GetMsize() { return Msize; }
int Pharmacy::GetCsize() { return Csize; }
Medication* Pharmacy::GetMptr() { return PMedications; }
Customer* Pharmacy::GetCptr() { return PCustomers; }

//Member Functions
//Add Medication
void Pharmacy::addMed(Medication& Mdetails) {
																									
		Msize++;																				//	1) increments medication array size					
		Medication* Ptemp = new Medication[Msize];												//  2) Initializes temporary dynamic array with added size

		for (int i = 0; i < Msize - 1; i++) {													//  3) Copies previously stored medications
			Ptemp[i].SetBarcode(PMedications[i].GetBarcode());	
			Ptemp[i].SetDescription(PMedications[i].GetDescription());
			Ptemp[i].SetExpiryDate(PMedications[i].GetExpiryDate());
			Ptemp[i].SetName(PMedications[i].GetName());
			Ptemp[i].SetPrice(PMedications[i].GetPrice());
			Ptemp[i].SetStock(PMedications[i].GetStock());
		}		
		delete[] PMedications;																	//  4) Clears the medications dynamic array
		PMedications = Ptemp;																	//  5) Points the medication array pointer to newly made array
		Ptemp[Msize-1].SetBarcode(Mdetails.GetBarcode());										//  6) Adds the new medication to last index of medication array 
		Ptemp[Msize-1].SetDescription(Mdetails.GetDescription());
		Ptemp[Msize-1].SetExpiryDate(Mdetails.GetExpiryDate());
		Ptemp[Msize-1].SetName(Mdetails.GetName());
		Ptemp[Msize-1].SetPrice(Mdetails.GetPrice());
		Ptemp[Msize-1].SetStock(Mdetails.GetStock());
		
}

	
//Remove Medication
void Pharmacy::remMed(string medName) {

	bool found = false;
	int c1 = Msize;
	int c2 = 0;

	for (int i = 0; i < c1; i++) {
		if (PMedications[i].GetName() == medName || PMedications[i].GetMedID() == stoi(medName) || PMedications[i].GetBarcode() == medName) {	//1) Takes string input from user and checking if medication exists in array
			Msize--;

			Medication* Ptemp = new Medication[Msize];																							//2) Decrements size and creates new array with reduced size

			for (int j = 0; j < Msize; j++) {
				if (j < i) {
					Ptemp[j].SetBarcode(PMedications[j].GetBarcode());
					Ptemp[j].SetDescription(PMedications[j].GetDescription());
					Ptemp[j].SetExpiryDate(PMedications[j].GetExpiryDate());
					Ptemp[j].SetName(PMedications[j].GetName());
					Ptemp[j].SetPrice(PMedications[j].GetPrice());
					Ptemp[j].SetStock(PMedications[j].GetStock());
				}
				else {
					Ptemp[j].SetBarcode(PMedications[j + 1].GetBarcode());
					Ptemp[j].SetDescription(PMedications[j + 1].GetDescription());
					Ptemp[j].SetExpiryDate(PMedications[j + 1].GetExpiryDate());
					Ptemp[j].SetName(PMedications[j + 1].GetName());
					Ptemp[j].SetPrice(PMedications[j + 1].GetPrice());
					Ptemp[j].SetStock(PMedications[j + 1].GetStock());
				}
			}

			cout << "Medication removed" << endl;
			found = true;
			delete[] PMedications;
			PMedications = Ptemp;
			break;
		}
	}
	if (found == false) {
		cout << "\n\n***Medication not found";
	}
}

//Add Customer
void Pharmacy::addCust(Customer& Cdetails) {
		
		Csize++;																				//	1) increments customers array size	
		Customer* Ctemp = new Customer[Csize];													//  2) Initializes temporary dynamic array with added size

		for (int i = 0; i < Csize - 1; i++) {													// 3) Copies previously stored customers
			Ctemp[i].SetName(PCustomers[i].GetName());
			Ctemp[i].SetAddress(PCustomers[i].GetAddress());
		}
		delete[] PCustomers;																	//  4) Clears the customers dynamic array
		PCustomers = Ctemp;																		//  5) Points the customers array pointer to newly made array
		PCustomers[Csize - 1].SetName(Cdetails.GetName());										//  6) Adds the new custoemr to last index of medication array 
		PCustomers[Csize - 1].SetAddress(Cdetails.GetAddress());								

		
	cout << "\n\n***Customer added successfully!\n";
}

//Displaying medication
bool Pharmacy::disMed() {
	if (Msize == 0) { cout << "\n\nThere are no medications in the list\n" << endl;  return false; }	//check if thre are medications to display
	else {
		
		for (int i = 0; i < Msize; i++) {					//use medications print function to display medication details
			PMedications[i].print();
			cout << endl;
		}
		return true;
	}
}
//Displaying customers
bool Pharmacy::disCust() {
	if (Csize == 0) { cout << "\n\nThere are no Customers in the list\n" << endl; return false; }	//check if thre are customers to display
	else {
		for (int i = 0; i < Csize; i++) {
			PCustomers[i].Print();									//use customers print function to display customr details
			cout << endl;
		}
		return true;
	}
}
	

//Comparing number of medication between 2 pharmacies

void Pharmacy::medCount(Pharmacy& ob) {						

	if (Msize > ob.Msize) { cout << PharmacyName << " has more medications (" << Msize << ") than " << ob.PharmacyName << " (" << ob.Msize << ") " << endl; }			//compares dynamic array sizes to represent number of medications in each pharmacy

	else if(Msize < ob.Msize) { cout << ob.PharmacyName << " has more medications (" << ob.Msize << ") than " << PharmacyName << " (" << Msize << ") " << endl; }

	else { cout << "Both " << PharmacyName << " and " << ob.PharmacyName << " have (" << Msize << ") medications" << endl; }
}

//Comparing number of customers between 2 pharmacies

void Pharmacy::custCount(Pharmacy& ob) {


	if (Csize > ob.Csize) { cout << PharmacyName << " has more customers (" << Csize << ") than " << ob.PharmacyName << " (" << ob.Csize << ") " << endl; }			//compares dynamic array sizes to represent number of customers in each pharmacy

	else if (Csize < ob.Csize) { cout << ob.PharmacyName << " has more customers (" << ob.Csize << ") than " << PharmacyName << " (" << Csize << ") " << endl; }

	else { cout << "Both " << PharmacyName << " and " << ob.PharmacyName<< " have (" << Csize << ") customers" << endl; }
}
