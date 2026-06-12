#include <iostream>
#include <vector>
using namespace std;
class Student
{
private:
    int id;
    string name;

public:
    Student(int i, string n)
    {
        id = i;
        name = n;
    }

    string getName()
    {
        return name;
    }
};
class CapacityExceededException
{
public:
    string message()
    {
        return "Course Capacity Full!";
    }
};
class Course
{
private:
    string courseCode;
    string courseName;
    int creditHours;
    string instructor;
    int maxCapacity;
    int enrolledCount;

public:
    vector<Student*> waitingList;
    Course(string code, string name, int credits,
           string inst, int capacity)
    {
        courseCode = code;
        courseName = name;
        creditHours = credits;
        instructor = inst;
        maxCapacity = capacity;
    }
    string getCourseCode()
    {
        return courseCode;
    }

    string getCourseName()
    {
        return courseName;
    }
    void setCourseName(string name)
    {
        courseName = name;
    }
    void enrollStudent(Student* s)
    {
        if (enrolledCount >= maxCapacity)
        {
            throw CapacityExceededException();
        }

        enrolledCount++;
        cout << s->getName()
             << " enrolled successfully.\n";
}
    bool operator==(Course c)
    {
        return courseCode == c.courseCode;
    }
    vector<Student*> operator+(Course c)
    {
        vector<Student*> merged = waitingList;

        for (int i = 0; i < c.waitingList.size(); i++)
        {
            merged.push_back(c.waitingList[i]);
        }

        return merged;
    }
    friend ostream& operator<<(ostream& out, Course& c);
};
ostream& operator<<(ostream& out, Course& c)
{
    out << "\nCourse Code: " << c.courseCode;
    out << "\nCourse Name: " << c.courseName;
    out << "\nCredit Hours: " << c.creditHours;
    out << "\nInstructor: " << c.instructor;
    out << "\nCapacity: " << c.maxCapacity;
    out << "\nEnrolled Students: " << c.enrolledCount;
    out << endl;

    return out;
}
class Enrollment
{
private:
    Student* student;
    Course* course;
    string enrollmentDate;
    string grade;

public:
    Enrollment(Student* s, Course* c,
               string date, string g)
    {
        student = s;
        course = c;
        enrollmentDate = date;
        grade = g;
    }
};

int main()
{
    Student s1(1, "Ali");
    Student s2(2, "Ahmed");

    Course c1("CS101", "Programming", 3,
              "Sir Asad", 1);

    Course c2("CS101", "Programming", 3,
              "Sir Hamza", 2);
    if (c1 == c2)
    {
        cout << "Both courses have same code.\n";
    }
    try
    {
        c1.enrollStudent(&s1);
        c1.enrollStudent(&s2);
    }
    catch (CapacityExceededException e)
    {
        cout << e.message() << endl;
    }
    c1.waitingList.push_back(&s1);
    c2.waitingList.push_back(&s2);

    vector<Student*> result = c1 + c2;

    cout << "\nMerged Waiting List Size: "
         << result.size() << endl;
    cout << c1;

    return 0;
}