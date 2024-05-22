#include <iostream>
#include <Windows.h>
#include "Address2.h"
#include "Customers2.h"
#include "Medications2.h"
#include "Date2.h"
#include "Pharmacy2.h"
using namespace std;


//Display Pharmacies:
void DisplayPharmacies(Pharmacy* Parr, int Pcounter) {
	if (Pcounter == 0) { cout << "No pharmacies have been added" << endl; return; }
	else {
		for (int i = 0; i < Pcounter; i++) {
			cout << i + 1 << ") " << Parr[i].GetName() << endl;
		}
	}
}

//Display Customers
void DisplayCustomers(Pharmacy* Pharmacies, int PharmacyChoice) {
	cout << "Displaying customer list of: " << Pharmacies[PharmacyChoice].GetName() << endl;
	Pharmacies[PharmacyChoice].disCust();
}

//Display Medications
void DisplayMedications(Pharmacy*& Pharmacies, int PharmacyChoice) {
	cout << "Displaying available medications in: " << Pharmacies[PharmacyChoice].GetName() << endl;
	Pharmacies[PharmacyChoice].disMed();
}

//Display Menu1 (menu for all pharmacies):
void DisplayMenu1(string& Choice) {
	cout << "\n******************** Menu ********************\n\n";
	cout << "Select an option:- \n\n";
	cout << "1. To add a pharmacy write:                                                  (P)\n";
	cout << "2. To remove a pharmacy write:                                               (PX)\n";
	cout << "3. To display available pharmacies write:                                    (D)\n";
	cout << "4. To manage a specific pharmacy write:                                      (M)\n";
	cout << "5. To compare medication stock between 2 pharmacies write:                   (S)\n";
	cout << "6. To compare total Customers between 2 pharmacies write:                    (C)\n";
	cout << "7. To calculate total revenue made write:                                    (T)\n";
	cout << "8. To exit program write:                                                    (X)\n";
	cin >> Choice;
}

//Display Menu2 (menu to manage a specific pharmacy):
void DisplayMenu2(string& Choice) {
	
	
	cout << "Select an option:- \n\n";
	cout << "1. To add a customer write:                 (C)\n";
	cout << "2. To add a medication write:               (M)\n";
	cout << "3. To remove a medication write:            (MX)\n";
	cout << "4. To make a purchase write:                (P)\n";
	cout << "5. To display customer's list write:        (DC)\n";
	cout << "6. To display available medication write:   (DM)\n";
	cout << "7. To exit pharmacy write:                  (X)\n";
	cin >> Choice;
}

//Add Pharmacy 1-
void AddPharmacy(Pharmacy*& Parr,string StringInput,int &Pcounter,int& size) {			
	system("CLS");
	int tempsize = Pcounter;
	cout << "How many Pharmacies would you like to add: " << endl;					
	cin >> size;
	for (int i = 0; i < 2; i++) {											//ensures a positive number greater than 0 is entered for array size
		if (size < 1) { cout << "Please enter a positive number greater than 1" << endl; i--; cin >> size; }
		else break;
	}
	Pharmacy* Ptemp = new Pharmacy[size+Pcounter];								//creates a temporary dynamic array with wanted size
	for (int i = 0; i < tempsize; i++) {								//then copies the pharmacies previously stored 
		Ptemp[i].SetName(Parr[i].GetName());
		Ptemp[i].SetCptr(Parr[i].GetCptr());
		Ptemp[i].SetMptr(Parr[i].GetMptr());
	}	
	delete[] Parr;														//clears the old dynamic array
	for (int i = tempsize; i < size + tempsize; i++) {
		cout << "Enter the name of pharmacy" << i + 1 << ":" << endl;
		cin.ignore();
		getline(cin, StringInput);
		Ptemp[i].SetName(StringInput);									//adds new pharmacy
		Pcounter++;	
	}	
	
	Parr = Ptemp;														//makes the pointer point to the new dynamic array with added pharmacies
}

void RemovePharmacy(Pharmacy*& Parr, int IntegerInput, int& Pcounter, int& size) {
	
	if (Pcounter == 0) { cout << "No pharmacies have been added for removal" << endl; return; }
	else {
		cout << "Which pharmacy would you like to permenantly close:  (choose corresponding number)" << endl;
		int choice;
		DisplayPharmacies(Parr, Pcounter);
		cin >> choice;
		size--;
		Pcounter--;
		Pharmacy* Ptemp = new Pharmacy[Pcounter];
		for (int i = 0; i < size; i++) {
			if (choice!= i+1) {
				Ptemp[i].SetName(Parr[i].GetName());
				Ptemp[i].SetCptr(Parr[i].GetCptr());
				Ptemp[i].SetMptr(Parr[i].GetMptr());
			}
		}
		Pcounter--;
		cout << "Pharmacy removed" << endl;
		delete[] Parr;
		Parr = Ptemp;
		return;
	}
	
}

//Compare Meds stock 3-
void CompareMeds(Pharmacy*& Parr, int Pcounter) {
	int inp1;
	int inp2;
	cout << "Medication stock comparison:" << endl;
	DisplayPharmacies(Parr, Pcounter);
	cout << "Choose the first pharmacy by entering the corresponding number: " << endl;
	//DisplayPharmacies(Parr, Pcounter);
	cin >> inp1;
	cout << " Choose the second pharmacy by entering the corresponding number: " << endl;
//	DisplayPharmacies(Parr, Pcounter);
	cin >> inp2;
	Parr[inp1 - 1].medCount(Parr[inp2 - 1]);

}

//Compare Number of customers 4-
void CompareCustomers(Pharmacy*& Parr, int Pcounter) {
	int inp1;
	int inp2;
	cout << "Customres comparison:" << endl;
	cout << "Choose the first pharmacy by entering the corresponding number: " << endl;
	DisplayPharmacies(Parr, Pcounter);
	cin >> inp1;
	cout << " Choose the second pharmacy by entering the corresponding number: " << endl;
	DisplayPharmacies(Parr, Pcounter);
	cin >> inp2;
	Parr[inp1 - 1].custCount(Parr[inp2 - 1]);
}

//Add customer to one pharmacy
void AddCustomer(Pharmacy*& Pharmacies, int PharmacyChoice, int& Counter1, string StringInput) {//Adding a customer


	cout << "Adding a customer to " << Pharmacies[PharmacyChoice].GetName() << endl;
	Customer tempCust;
	Address tempAdd;
	cout << "Enter customer's name:" << endl;
	getline(cin, StringInput); getline(cin, StringInput);
	tempCust.SetName(StringInput);

	cout << "Enter customer's Email:" << endl;
	getline(cin, StringInput);
	tempAdd.setEmail(StringInput);

	cout << "Enter customer's city:" << endl;
	getline(cin, StringInput);
	tempAdd.setCity(StringInput);

	cout << "Enter customer's mobile number:" << endl;
	getline(cin, StringInput);
	tempAdd.setMobile(StringInput);

	cout << "Enter customer's street name:" << endl;
	getline(cin, StringInput);
	tempAdd.setStreet(StringInput);

	tempCust.SetAddress(tempAdd);

	Pharmacies[PharmacyChoice].addCust(tempCust);
	Counter1++;
	return;
}

//Add medication to one pharmacy
void AddMedication(Pharmacy*& Pharmacies, int PharmacyChoice, string StringInput, int IntegerInput, float FloatInput, int& Counter2) {//Adding medication
	
	
		cout << "Adding a medication to " << Pharmacies[PharmacyChoice].GetName() << endl;
		Date tempDate;
		Medication tempMedication;

		cout << "Enter medication's name:" << endl;
		getline(cin, StringInput); getline(cin, StringInput);
		if (Counter2 > 0) {
			for (int i = 0; i < Counter2; i++) {													//check if medication exists already, if yes stock will be added accordingly 
				if (StringInput == Pharmacies[i].GetMed(i).GetName()) {
					cout << "Medication already stored, How much stock would you like to add:" << endl;
					cin >> IntegerInput;
					Pharmacies[PharmacyChoice].GetMed(i).SetStock((Pharmacies[PharmacyChoice].GetMed(i).GetStock() + IntegerInput));
					cout << "Stock added" << endl; return;;
				}
				else { break; }
			}
		}

				tempMedication.SetName(StringInput);

				cout << "Enter medication's description:" << endl;
				getline(cin, StringInput);
				tempMedication.SetDescription(StringInput);

				cout << "Enter medication's price:" << endl;
				cin >> FloatInput;
				tempMedication.SetPrice(FloatInput);

				cout << "Enter medication's stock:" << endl;
				cin >> IntegerInput;
				tempMedication.SetStock(IntegerInput);

				cout << "Enter medication's expiry date (day,month,year):" << endl;
				cin >> IntegerInput;
				tempDate.setday(IntegerInput);
				cin >> IntegerInput;
				tempDate.setmonth(IntegerInput);
				cin >> IntegerInput;
				tempDate.setyear(IntegerInput);
				tempMedication.SetExpiryDate(tempDate);

				cout << "Enter medication's barcode:" << endl;
				getline(cin, StringInput); getline(cin, StringInput);
				if(Counter2 > 0){
					for (int k = 0; k < 2; k++) {										//Check if barcode is used before, if yes it will keep asking user to enter a new barcode until valid
						for (int j = 0; j < Counter2; j++) {
							if (StringInput == Pharmacies[j].GetMed(j).GetBarcode()) {
								cout << "Barcode already in use, please use another barcode" << endl;
								k = 0;
								getline(cin, StringInput);
							}
						}
					}
				}
				tempMedication.SetBarcode(StringInput);

				Pharmacies[PharmacyChoice].addMed(tempMedication);
				cout << "Medication added successfully" << endl;
				Counter2++;
				
			}
	
//3
void RemoveMedication(Pharmacy*& Pharmacies, int PharmacyChoice, string StringInput) {
	if (Pharmacies[PharmacyChoice].disMed()) {
		cout << "Removing a medication from " << Pharmacies[PharmacyChoice].GetName() << endl;
		DisplayMedications(Pharmacies, PharmacyChoice);
		cout << "Enter the name, ID or barcode of the medication you would like to remove:" << endl;

		cin.ignore();
		getline(cin, StringInput); 
		Pharmacies[PharmacyChoice].remMed(StringInput);
	}
	else { cout << "No medications avaialble for removal" << endl; }
}

//4
void PurchaseMedication(Pharmacy*& Pharmacies, int PharmacyChoice, string StringInput, float& TotalSales, int& Counter2) {//Proccess of purchasing a drug
	if (Pharmacies[PharmacyChoice].disMed()) {
		cout << "Select medication to purchase: " << endl;							//display available medications
		cout << "Enter medication's name or barcode to select: \n";
		getline(cin, StringInput);		getline(cin, StringInput);  				 //take in user input to decide which medication he wants to purchase
		for (int i = 0; i < 10; i++) {										//loop that checks the medication array for the medication the user wants, decrements stock and adds to sales total.
			if (StringInput == Pharmacies[PharmacyChoice].GetMed(i).GetName() || StringInput == Pharmacies[PharmacyChoice].GetMed(i).GetBarcode()) {
				if (Pharmacies[PharmacyChoice].GetMed(i).GetStock() == 0) {
					cout << "\nMedication out of stock\n"; return;
				}
				else {
					cout << "How many packets would you like to purchase ?" << endl;
					int num = 0;
					cin >> num;
					if (num > Pharmacies[PharmacyChoice].GetMed(i).GetStock()) { cout << "Insufficient stock, number of packets chosen is greater than supply" << endl; i--; continue; }
					else {
						Pharmacies[PharmacyChoice].GetMed(i).SetStock((Pharmacies[PharmacyChoice].GetMed(i).GetStock() - num));
						TotalSales += Pharmacies[PharmacyChoice].GetMed(i).GetPrice() * num;
						cout << "\nPurchase successful!" << endl; return;
					}
				}
			}
		}
	}
	else { cout << "No medications available for purchase" << endl; return; }
}

int main() { 
	string Choice{};
	string StringInput;
	float FloatInput{};
	int IntegerInput{};
	int IntegerInput2{};
	Customer CsutomerArray[50];		//array to store customers
	Medication MedicationArray[50];	//array to store Medications
	int Counter1 = 0;				//Customer counter
	int Counter2 = 0;				//Medication counter
	int pharmcounter = 0;			//Pharmacy counter
	int PharmacyChoice = 0;			//user choice of which pharmacy to manage
	float TotalSales = 0;				//total sales variable
	int size = 0;
	Pharmacy *Pharmacies = nullptr;		//Array of pharmacies  
	
		
	while (true) {
		DisplayMenu1(Choice);
		if (Choice == "P" || Choice == "p") {	//Add a pharmacy
		AddPharmacy(Pharmacies,StringInput, pharmcounter,size);	
		size++;
		}
		else if (Choice == "S" || Choice == "s") {	//Compare medication stock
			if (pharmcounter > 1) {					//make sure 2 pharmacies or more exist for comparison
				CompareMeds(Pharmacies, pharmcounter);
			}
			else
				cout << "\n\n insufficient number of pharmacies\n";	
		}
		else if (Choice == "C" || Choice == "c") {		//Compare number of customers 
			if (pharmcounter > 1) {						//make sure 2 pharmacies or more exist for comparison
				CompareCustomers(Pharmacies, pharmcounter);
			}
			else
				cout << "\n\n insufficient number of pharmacies\n";
		}
		else if (Choice == "D" || Choice == "d") { //Dsiplay added pharmacies
			DisplayPharmacies(Pharmacies, pharmcounter);
		}
		else if (Choice == "T" || Choice == "t") {	//Display total revnue made by all pharmacies
			cout << "Total revenue made: " << TotalSales << "JD" << endl;
		}
		else if (Choice == "PX" || Choice == "pX" || Choice == "Px" || Choice == "px") {
			RemovePharmacy(Pharmacies,IntegerInput, pharmcounter, size);
		}
		else if (Choice == "M" || Choice == "m") {	//choice to modify a unique pharmacy alone:
			
			if (pharmcounter < 1) { cout << "No pharmacies are added, please add a pharmacy first" << endl; continue; }	//makes sure a pharmacy exists for manegment
			cout << "Which pharmacy would you like to manage (choose the corresponding number): " << endl;				
			DisplayPharmacies(Pharmacies, pharmcounter);
			cin >> PharmacyChoice;
			system("CLS");	
			if (PharmacyChoice > pharmcounter || PharmacyChoice < 1) { cout << "Chosen pharmacy does not exist" << endl; continue; }	//ensures input of pharmacy is valid
			PharmacyChoice--;
			while (true) {
				cout << "Currently managing the following pharmacy: (" << Pharmacies[PharmacyChoice].GetName()<<")"<<endl;
				DisplayMenu2(Choice);
				if (Choice == "C" || Choice == "c") {	//Add customer
					AddCustomer(Pharmacies, PharmacyChoice, Counter1, StringInput);
				}
				else if (Choice == "M" || Choice == "m") {	//Add medications
					AddMedication(Pharmacies, PharmacyChoice, StringInput, IntegerInput, FloatInput, Counter2);
				}
				else if (Choice == "MX" || Choice == "mX" || Choice == "Mx" || Choice == "mx") {	//Remove medication
					RemoveMedication(Pharmacies, PharmacyChoice, StringInput);
				}
				else if (Choice == "P" || Choice == "p") {	//Purchase a medication
					PurchaseMedication(Pharmacies, PharmacyChoice, StringInput, TotalSales, Counter2);
				}
				else if (Choice == "DC" || Choice == "dC" || Choice == "Dc" || Choice == "dc") {	//Display pharmacy's customers
					DisplayCustomers(Pharmacies, PharmacyChoice);
				}
				else if (Choice == "DM" || Choice == "dM" || Choice == "Dm" || Choice == "dm") {	//Display pharmacy's medications
					DisplayMedications(Pharmacies, PharmacyChoice);
				}
				else if (Choice == "X" || Choice == "x") {	//exit the pharmacy back to menu 1
					break;
				}
				else {
					cout << "\nError, enter a letter form the list" << endl;	//ensure an option is chosen 
						continue;}
				
			}
		
		}
		else if (Choice == "X" || Choice == "x") {	//exit the whole system
			break;
		}
		else {
			cout << "\nError, enter a letter form the list" << endl;		//ensure an option is chosen 
			continue;
		}

	}

	////The following part contains the 4 questions in phase 3, they have been commented out so that they don't interfere with the main pharmacy project:
	
	////1 – An object in static memory with attributes in static memory
	//Date exp1(20, 10, 2025);
	//Date Offer1(10, 11, 2024);
	//OffTheShelf med1("Panadol", "Pain-Killer", 3, 5, exp1, "1234", true, Offer1);
	//med1.print();
	
	
	////2-An object in static memory with attributes in dynamic memory
	//Customer CustomerList[4];
	//CustomerList[0].SetName("Omar");
	//CustomerList[1].SetName("Mohammad");
	//CustomerList[2].SetName("Jack");
	//CustomerList[3].SetName("Roa");
	//Medication Medlist[2];
	//Medlist[0].SetName("Panadol Night");			Medlist[1].SetName("Rennie");
	//Medlist[0].SetDescription("Pain killer");		Medlist[1].SetDescription("Flux medicine");
	//Medlist[0].SetPrice(4);							Medlist[1].SetPrice(5);
	//Medlist[0].SetStock(5);							Medlist[1].SetStock(10);
	//Medlist[0].SetExpiryDate(exp1);					Medlist[1].SetExpiryDate(exp1);
	//Medlist[0].SetBarcode("123456");				Medlist[1].SetBarcode("9875");
	//
	////Customer list and Medlist are attributes of pharmacy and will be stored in heap
	//Pharmacy pharm1("Pharmacyone", CustomerList, Medlist,2,4);	
	//pharm1.GetMed(0).print(); cout << endl;
	//pharm1.GetMed(1).print();

	////3 – An object in dynamic memory with attributes in static memory
	//Address ad1("Ahmad2004@gmail.com", "Amman", "0792908134", "Jordan st.");
	//Customer* Ahmad = new Customer("Ahmad",ad1);
	//Ahmad->Print();
	


	////4 – An object in dynamic memory with attributes in dynamic memory
	//Pharmacy* Pharm2 = new Pharmacy("Dawacom",CustomerList,Medlist,2,4);
	return 0;
}
	
	
