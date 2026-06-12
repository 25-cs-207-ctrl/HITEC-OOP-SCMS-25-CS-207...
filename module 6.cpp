#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
class Student
{
public:
    int id;
    string name;
    float gpa;

    Student(int i, string n, float g)
    {
        id = i;
        name = n;
        gpa = g;
    }
};
class Book
{
public:
    string title;
    bool overdue;

    Book(string t, bool o)
    {
        title = t;
        overdue = o;
    }
};
class Utils
{
public:
    static void printLine()
    {
        cout << "-----------------------------------" << endl;
    }

    static void showDate()
    {
        cout << "Date: 06-06-2026" << endl;
    }

    static bool validateID(int id)
    {
        return id > 0;
    }
};
class Reports
{
public:
    static void campusReport(Student students[], int sCount,
                             Book books[], int bCount)
    {
        Utils::printLine();
        cout << "CAMPUS REPORT" << endl;
        Utils::showDate();
        Utils::printLine();

        cout << "\nStudents:\n";
        for (int i = 0; i < sCount; i++)
        {
            cout << students[i].id << " "
                 << students[i].name << " GPA: "
                 << students[i].gpa << endl;
        }

        cout << "\nBooks:\n";
        for (int i = 0; i < bCount; i++)
        {
            cout << books[i].title << endl;
        }
        Utils::printLine();
    }
};
bool compareGPA(Student a, Student b)
{
    return a.gpa > b.gpa;
}

int main()
{
    Student* students = new Student[3]
    {
        Student(101,"Ali",3.2),
        Student(102,"Sara",3.8),
        Student(103,"Ahmed",3.5)
    };

    Book* books = new Book[3]
    {
        Book("C++ Programming",false),
        Book("Data Structures",true),
        Book("OOP Concepts",false)
    };
    Reports::campusReport(students,3,books,3);

    sort(students, students + 3, compareGPA);

    cout << "\nStudents Sorted By GPA:\n";
    for(int i=0;i<3;i++)
    {
        cout << students[i].name
             << " GPA: "
             << students[i].gpa << endl;
    }
    Book* overdueBook = find_if(
        books,
        books + 3,
        [](Book b)
        {
            return b.overdue == true;
        });

    if(overdueBook != books + 3)
    {
        cout << "Overdue Book Found: "
             << overdueBook->title << endl;
    }
    cout << "\n\n===== CAMPUS PDF REPORT =====\n";
    cout << "Total Students: 3\n";
    cout << "Total Books: 3\n";
    cout << "Overdue Book: "
         << overdueBook->title << endl;
    cout << "=============================\n";

    delete[] students;
    delete[] books;

    return 0;
}