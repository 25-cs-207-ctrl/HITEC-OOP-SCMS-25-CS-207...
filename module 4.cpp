#include <iostream>
#include <string>
using namespace std;
class FeeRecord
{
private:
    string studentRef;
    double semesterFee;
    double hostelFee;
    double libraryFine;
    double totalPaid;
    double balance;
public:
    FeeRecord()
    {
        studentRef = "";
        semesterFee = 0;
        hostelFee = 0;
        libraryFine = 0;
        totalPaid = 0;
        balance = 0;
    }
	FeeRecord(string ref, double sem, double hostel, double fine)
    {
        studentRef = ref;
        semesterFee = sem;
        hostelFee = hostel;
        libraryFine = fine;
		totalPaid = 0;
        balance = semesterFee + hostelFee + libraryFine;
    }
    FeeRecord(const FeeRecord& obj)
    {
        studentRef = obj.studentRef;
        semesterFee = obj.semesterFee;
        hostelFee = obj.hostelFee;
        libraryFine = obj.libraryFine;
        totalPaid = obj.totalPaid;
        balance = obj.balance;
    }
    FeeRecord& operator=(const FeeRecord& obj)
    {
        if(this != &obj)
        {
            studentRef = obj.studentRef;
            semesterFee = obj.semesterFee;
            hostelFee = obj.hostelFee;
            libraryFine = obj.libraryFine;
            totalPaid = obj.totalPaid;
            balance = obj.balance;
        }
		return *this;
    }
    void operator-=(double payment)
    {
        totalPaid += payment;
        balance -= payment;
    }
	void display()
    {
        cout << "\nStudent: " << studentRef;
        cout << "\nBalance: " << balance;
        cout << "\nPaid: " << totalPaid << endl;
    }
};
class Invoice
{
private:
    int invoiceID;
    string date;
    string* items;
    int itemCount;
    double totalAmount;
public:
    static int invoiceCounter;
	Invoice(string d, int count, double amount)
    {
        invoiceID = ++invoiceCounter;
		date = d;
        itemCount = count;
        totalAmount = amount;
		items = new string[itemCount];
    }
	void addItem(int index, string item)
    {
        items[index] = item;
    }
	void display()
    {
        cout << "\nInvoice ID: " << invoiceID;
        cout << "\nDate: " << date;
        cout << "\nAmount: " << totalAmount << endl;
    }
    ~Invoice()
    {
        delete[] items;
        cout << "\n================Invoice Destroyed============\n";
    }
};
int Invoice::invoiceCounter = 0;
int main()
{
    FeeRecord f1("BSCS01", 50000, 10000, 1000);
	cout << "\nBefore Payment\n";
    f1.display();
	f1 -= 15000;
	cout << "\nAfter Payment\n";
    f1.display();
	Invoice i1("02-06-2026", 2, 61000);
	i1.addItem(0, "Semester Fee");
    i1.addItem(1, "Hostel Fee");
	i1.display();

    return 0;
}