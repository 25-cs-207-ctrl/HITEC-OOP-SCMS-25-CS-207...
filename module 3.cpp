#include <iostream>
#include <fstream>
using namespace std;
class LibraryItem
{
protected:
    int itemID;
    string title;
    string author;
    int publicationYear;
public:
    virtual void checkout() = 0;
	string getTitle()
    {
        return title;
    }
    int getItemID()
    {
        return itemID;
    }
	virtual void display() = 0;
};
class Book : public LibraryItem
{
private:
    string ISBN;
    string genre;
    int copiesAvailable;
public:
    Book() {}

    Book(int id, string t, string a, int year,
         string isbn, string g, int copies)
    {
        itemID = id;
        title = t;
        author = a;
        publicationYear = year;
        ISBN = isbn;
        genre = g;
        copiesAvailable = copies;
    }
    void checkout()
    {
        if (copiesAvailable > 0)
        {
            copiesAvailable--;
            cout << "Book Issued Successfully\n";
        }
        else
        {
            cout << "No Copies Available\n";
        }
    }
    void display()
    {
        cout << "\nBook ID: " << itemID;
        cout << "\nTitle: " << title;
        cout << "\nAuthor: " << author;
        cout << "\nYear: " << publicationYear;
        cout << "\nISBN: " << ISBN;
        cout << "\nGenre: " << genre;
        cout << "\nCopies: " << copiesAvailable;
    }
};
class Journal : public LibraryItem
{
private:
    string ISSN;
    int volume;
    int issueNumber;
public:
    Journal() {}

    Journal(int id, string t, string a, int year,
            string issn, int vol, int issue)
    {
        itemID = id;
        title = t;
        author = a;
        publicationYear = year;
        ISSN = issn;
        volume = vol;
        issueNumber = issue;
    }
    void checkout()
    {
        cout << "Journal Issued\n";
    }
    void display()
    {
        cout << "\nJournal ID: " << itemID;
        cout << "\nTitle: " << title;
        cout << "\nAuthor: " << author;
        cout << "\nYear: " << publicationYear;
        cout << "\nISSN: " << ISSN;
        cout << "\nVolume: " << volume;
        cout << "\nIssue: " << issueNumber;
    }
};
struct IssueRecord
{
    int rollNo;
    int itemID;
};
class OverdueException
{
private:
    double fine;
public:
    OverdueException(double f)
    {
        fine = f;
    }
    double getFine()
    {
        return fine;
    }
};
class Library
{
private:
    LibraryItem* items[100];
    int count;
public:
    Library()
    {
        count = 0;
    }
    void addItem(LibraryItem* item)
    {
        items[count++] = item;
    }
    void displayAll()
    {
        for (int i = 0; i < count; i++)
        {
            items[i]->display();
            cout << "\n------------------\n";
        }
    }
    void searchByTitle(string t)
    {
        bool found = false;
        for (int i = 0; i < count; i++)
        {
            if (items[i]->getTitle() == t)
            {
                items[i]->display();
                found = true;
            }
        }
        if (!found)
        {
            cout << "Item Not Found\n";
        }
    }
};
void saveToFile()
{
    ofstream file("library.txt");
    file << "Library Data Saved";
    file.close();
}  
void loadFromFile()
{
    ifstream file("library.txt");
    string data;
    getline(file, data);
	cout << data;
	file.close();
}

int main()
{
    Library lib;
    try
{
    int daysLate = 10;
	if (daysLate > 7)
    {
        throw OverdueException(500);
    }
}
catch (OverdueException e)
{
    cout << "Fine = " << e.getFine();
}
	Book *b1 = new Book(1,"OOP", "Ali",2024,"12345","Programming",5);
	Journal *j1 = new Journal(2,"Science","Ahmed",2023,"56789",10,2);
	lib.addItem(b1);
    lib.addItem(j1);
	lib.displayAll();
	cout << "\n==========Searching...==============\n";
    lib.searchByTitle("OOP");

    return 0;
}