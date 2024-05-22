#include <iostream>
#include "Medications2.h"
#include "Date2.h"
#include "Customers2.h"
#include "Address2.h"
using namespace std;

int Medication::NumOfMeds = 1;
//Default Constructor
Medication::Medication() : MedID(NumOfMeds++) {
    SetName("No name");
    SetDescription("No Description");
    SetPrice(0);
    SetStock(0);
    SetBarcode("0000");
    ExpiryDate.setday(1);
    ExpiryDate.setmonth(1);
    ExpiryDate.setyear(2024);
}
//Parameterized Constructor
Medication::Medication(string name, string description, float price, int stock, Date& ExpiryDate_, string barcode) :MedID(NumOfMeds++)
{
    SetName(name);
    SetDescription(description);
    SetPrice(price);
    SetStock(stock);
    SetExpiryDate(ExpiryDate_);
    SetBarcode(barcode);

}
//Copy Constructor
Medication::Medication(Medication& myMed) : MedID(NumOfMeds++), Name(myMed.Name), Description(myMed.Description), Price(myMed.Price), Stock(myMed.Stock),
ExpiryDate(myMed.ExpiryDate), Barcode(myMed.Barcode)
{

}
// Setters
//Assumptions made:
    //1)Medication names can contain numbers or symbols to represent different dosages 
void Medication::SetName(string n) {
    while (n == "") {
        cout << endl << "Invalid medication name (Empty input is not allowed): ";
        getline(cin, n);

    }
    Name = n;
}


void Medication::SetDescription(string d) {
    while (d == "") {
        cout << endl << "Invalid description (Empty input is not allowed): ";
        getline(cin, d);

    }
    Description = d;
}


void Medication::SetPrice(float p) {
    // Validate that the price is non-negative
    //Keep asking for input until a valid entry is given
    for (int i = 0; i < 2; i++)
    {
        if (p < 0) {
            cout << "Invalid Price input, negative prices or non numerical entries are not allowed" << endl;
            i--;    //resets loop to ask user for entry again
            cin >> p;
        }
    }Price = p;
}

void Medication::SetStock(int s) {
    // Validate that the stock is non-negative
   //Keep asking for input until a valid entry is given
    for (int i = 0; i < 2; i++)
    {
        if (s < 0) {
            cout << "Invalid Stock input, negative Stock or non numerical entries are not allowed" << endl;
            i--;    //resets loop to ask user for entry again
            cin >> s;
        }
    }Stock = s;
}

void Medication::SetExpiryDate(Date& myDate) {
    ExpiryDate.setday(myDate.getday());
    ExpiryDate.setmonth(myDate.getmonth());
    ExpiryDate.setyear(myDate.getyear());
}

void Medication::SetBarcode(string b) {
    // Validate that the barcode does not contain letters
    for (int i = 0; i < 2; i++) {
        if (Customer::CheckNonNumber(b)) { Barcode = b; }
        else {
            cout << "Invalid Barcode value,barcode can only contain numerical values and cant be empty" << endl;
            i--;
            cin >> b;
        }
    }
}
// Getters
string Medication::GetName() {
    return Name;
}
string Medication::GetDescription() {
    return Description;
}
float Medication::GetPrice() {
    return Price;
}
int Medication::GetStock() {
    return Stock;
}
Date& Medication::GetExpiryDate() {
    return ExpiryDate;
}
string Medication::GetBarcode() {
    return Barcode;
}
int Medication::GetMedID() const {
    return MedID;
}
// Function to print Medication details
void Medication::print()const {
    cout << "  Medication ID: " << MedID << endl;
    cout << "           Name: " << Name << endl;
    cout << "    Description: " << Description << endl;
    cout << "          Price: " << Price << " JD" << endl;
    cout << "          Stock: " << Stock << endl;
    cout << "    Expiry Date: ";
    ExpiryDate.printdate();
    cout << "        Barcode: " << Barcode << endl;
}


//OffTheShelf:

OffTheShelf::OffTheShelf() : BOGOF(false), OfferEnds() {}

OffTheShelf::OffTheShelf(string name, string description, float price, int stock, Date expiryDate, string barcode, bool bogof,Date Offer)
    : Medication(name, description, price, stock, expiryDate, barcode), BOGOF(bogof) {
    // Set OfferEnds based on the BOGOF status
    // For non-discounted meds, OfferEnds is set to 2 years from now
    // For meds on offer, OfferEnds is set to 3 months from now
    setBOGOF(bogof);
    setOfferEnds(Offer);
}


// Setters and Getters
void OffTheShelf::setBOGOF(bool bogof) {
    BOGOF = bogof;
}

bool OffTheShelf::getBOGOF() const {
    return BOGOF;
}

const Date& OffTheShelf::getOfferEnds() const {
    return OfferEnds;
}

void OffTheShelf::setOfferEnds(Date date) {

    if (BOGOF) { 
        if (date.getmonth() < 10) { date.setmonth(date.getmonth() + 3); } 
        else if (date.getmonth() == 10) { date.setmonth(1); }
        else if (date.getmonth() == 11) { date.setmonth(2); }               //Insurues no month is greater than 12 after addition
        else if (date.getmonth() == 12) { date.setmonth(3); }   
    }
    else { date.setyear(date.getyear() + 2); }
    OfferEnds = date;
}

// Print method
void OffTheShelf::print() const {
    Medication::print(); // Call base class print method
    cout << "---------------------------" << endl;
    cout << "          BOGOF: " << (BOGOF ? "Yes" : "No") << endl;
    cout << "     Offer Ends: ";
    OfferEnds.printdate();
    cout << endl << endl;
}




//Prescription:

//Default constructor
Prescriptions::Prescriptions() :Medication() {		//Calls Medication Default Constructor
    setfdanumber(0);
    ApprovalDate = Date();

}
//Parameterized constructor //	Calling medications parameterized constructor to make sure each medication of type prescription has medication attributes
Prescriptions::Prescriptions(int fdaNumber, Date appDate_, string name_, string description_, float price_, int stock_, Date& expDate_, string barcode_) :Medication(name_, description_, price_, stock_, expDate_, barcode_) {
    setfdanumber(fdaNumber);
    setappDate(appDate_);

}
//setters
    //FDA Number setter
        //Validations:
            //1) makes sure no negative entries are entered
void Prescriptions::setfdanumber(int num) {
    for (int i = 0; i < 2; i++) {
        if (num >= 0) { FDANumber = num; }
        else
        {
            cout << "Invalid FDA Number input, enter FDA number again (Negative entries are not allowed): " << endl;
            i--;
            cin >> num;
        }
    }
}

//Approval Date setter
    //calls Date Parameterized constructor
void Prescriptions::setappDate(Date d) { ApprovalDate = d; } //calls copy constructor

//Getters
int  Prescriptions::getfdanumber() { return FDANumber; }

Date Prescriptions::getappdate() { return ApprovalDate; }
//Prints information of medication as well as FDA number and Approval date
void Prescriptions::print() {
    Medication::print();
    cout << "---------------------------" << endl;
    cout << "     FDA Number: " << FDANumber << endl << "  Approval Date: ";
    ApprovalDate.printdate();
    cout << endl << endl;
}