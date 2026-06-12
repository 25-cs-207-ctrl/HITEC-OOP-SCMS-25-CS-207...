#include<iostream>
using namespace std;
class person{
	protected:
		string name;
		string CNIC;
		int age;
		string contact;
	public:
		person(string n, string c, int a, string con){
			name = n;
			CNIC = c;
			age = a;
			contact = con;
		}
		virtual void displayinfo() = 0;
};
class student : public person{
	private:
		int rollno;
		int smester;
		float gpa;
		public:
		student(string n, string c, int a, string con, int r, int s, float g) : person(n, c, a, con){
			rollno = r;
			smester = s;
			gpa = g;
		}
		void displayinfo(){
			cout<<"\n=============STUDENT INFO=================\n"<<endl;
			cout<<"Name: "<<name<<endl;
			cout<<"CNIC: "<<CNIC<<endl;
			cout<<"Roll no: "<<rollno<<endl;
			cout<<"Smester: "<<smester<<endl;
			cout<<"GPA: "<<gpa<<endl;
		}
		void calgrade(){
			if(gpa >= 3.5){
				cout<<"Grade A "<<endl;
			}
			else if(gpa >= 3.0){
				cout<<"Grade B"<<endl;
			}
			else{
				cout<<"Grade C "<<endl;
			}
		}
};
class faculty : public person{
	private:
		int employeeID;
		string department;
		string designation;
		public:
			faculty(string n, string c, int a, string con, int ID, string dep, string des) : person(n, c, a, con){
				employeeID = ID;
				department = dep;
				designation = des;
			}
			void displayinfo(){
				cout<<"\n========= Faculty Info ================\n"<<endl;
				cout<<"Name: "<<name<<endl;
				cout<<"Employee ID: "<<employeeID<<endl;
				cout<<"Departmnrt : "<<department<<endl;
				cout<<"Designation: "<<designation<<endl;
			}
};
class staff : public person{
	private:
		int staffID;
		string role;
		int salary;
	public:
		staff(string n, string c, int a, string con, int st, string r, float sal) : person(n, c, a, con){
			staffID = st;
			role = r;
			salary = sal;
		}
		void displayinfo(){
			cout<<"\n======== STAFF INFO ===========\n "<<endl;
			cout<<"Name: "<<name<<endl;
			cout<<"Staff ID: "<<staffID<<endl;
			cout<<"Role: "<<role<<endl;
			cout<<"salary: "<<salary<<endl;
		}
};
int main(){
	student s1("Ali", "36203....... ", 17, "03000...... ", 101, 3, 3.7);
	faculty f1("Ahmed", "6789...... ", 40, "6789...... ", 201, "computer science", "professor");
	staff sta("usman", "5467 ", 35,"0345.... ", 301, "clerk",50000 );
	s1.displayinfo();
	s1.calgrade();
	f1.displayinfo();
	sta.displayinfo();
	return 0;
}