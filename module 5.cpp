#include <iostream>
#include <string>
using namespace std;

class Student
{
public:
    string name;
    int rollNo;

    Student(string n = "", int r = 0)
    {
        name = n;
        rollNo = r;
    }
};

class Person
{
public:
    virtual void showInfo() = 0;
};

class Accommodation : virtual public Person
{
public:
    virtual void allocateRoom(Student* s) = 0;
    virtual void vacateRoom(Student* s) = 0;
};

class Reportable : virtual public Person
{
public:
    virtual void generateReport() = 0;
};

class Room
{
public:
    int roomNumber;
    string type;
    int floor;

    Student* occupants[3];
    int occupantCount;

    Room(int rn = 0, string t = "Single", int f = 0)
    {
        roomNumber = rn;
        type = t;
        floor = f;
        occupantCount = 0;

        for (int i = 0; i < 3; i++)
        {
            occupants[i] = NULL;
        }
    }

    void addStudent(Student* s)
    {
        if (occupantCount < 3)
        {
            occupants[occupantCount] = s;
            occupantCount++;
        }
        else
        {
            cout << "Room Full!" << endl;
        }
    }

    void removeStudent(Student* s)
    {
        for (int i = 0; i < occupantCount; i++)
        {
            if (occupants[i] == s)
            {
                for (int j = i; j < occupantCount - 1; j++)
                {
                    occupants[j] = occupants[j + 1];
                }

                occupants[occupantCount - 1] = NULL;
                occupantCount--;

                cout << s->name << " removed from room." << endl;
                return;
            }
        }
    }

    void displayRoom()
    {
        cout << "Room No: " << roomNumber
             << "  Type: " << type
             << "  Floor: " << floor << endl;

        cout << "Occupants: ";

        if (occupantCount == 0)
        {
            cout << "None";
        }
        else
        {
            for (int i = 0; i < occupantCount; i++)
            {
                cout << occupants[i]->name << " ";
            }
        }

        cout << endl;
    }
};

class HostelBlock
{
public:
    string blockName;
    Room rooms[3];

    HostelBlock(string name = "A")
    {
        blockName = name;

        rooms[0] = Room(101, "Single", 1);
        rooms[1] = Room(102, "Double", 1);
        rooms[2] = Room(201, "Triple", 2);
    }
};

class HostelManager : public Accommodation, public Reportable
{
private:
    HostelBlock block;

public:
    HostelManager(string name) : block(name)
    {
    }

    void allocateRoom(Student* s)
    {
        block.rooms[0].addStudent(s);

        cout << s->name
             << " allocated to Room "
             << block.rooms[0].roomNumber
             << endl;
    }

    void vacateRoom(Student* s)
    {
        block.rooms[0].removeStudent(s);
    }

    void generateReport()
    {
        cout << "\n===== Occupancy Report =====\n";

        for (int i = 0; i < 3; i++)
        {
            block.rooms[i].displayRoom();
            cout << endl;
        }
    }

    void showInfo()
    {
        cout << "Hostel Block: "
             << block.blockName << endl;
    }
};

int main()
{
    Student s1("Ali", 101);
    Student s2("Sara", 102);

    HostelManager manager("A Block");

    manager.showInfo();

    manager.allocateRoom(&s1);
    manager.allocateRoom(&s2);

    manager.generateReport();

    manager.vacateRoom(&s1);

    manager.generateReport();

    return 0;
}