#include <iostream>
#include<stdlib.h>

using namespace std;

class Person
{
	private:
	string name;
	string department;
	public:
        void setdata()
        {
          cout << "Enter the name of person: "; cin.ignore();  getline(cin,name);
          cout << "Enter the department of the person: "; cin.ignore();  getline(cin,department);
        }
        void getdata()
        {
           cout << "\nName: "<< name;
           cout << "\nDepartment: "<< department;
        }
};

class Student:public Person
{
	private:
        string Curr_Year;
        string e_no,faculty_no;
        float CGPA;
	public:
        void setdata()
        {
                Person::setdata();
                cout << "Enter the Current Study Session: ";
                cin.ignore();  getline(cin,Curr_Year);
                cout <<"Enter Enrollment No: ";
                cin.ignore();  getline(cin,e_no);
                cout << "Enter Faculty No: ";
                cin.ignore();  getline(cin,faculty_no);
                cout <<"Enter Last Year CGPA: ";
                cin >> CGPA;
                cout << endl;
        }
	void getdata()
	{
        	Person::getdata();
        	cout << "\nCurrent Session: "<< Curr_Year<< endl;
        	cout << "Enrollment No: "<< e_no << endl;
        	cout << "Faculty No: "<< faculty_no << endl;
        	cout << "CGPA: "<< CGPA << endl;
	}
};

class UG_S:public Student
{
	public:
        void setdata()
        {
                cout <<"\nEnter records for UG student: \n";
                Student::setdata();
        }
        void getdata()
        {
        	cout <<"\nRecords for UG student: ";
        	Student::getdata();
        }
};

class PG_S:public Student
{
	private:
        string sp;
	public:
        void setdata()
        {
                cout << "\nEnter records for PG student: ";
                Student::setdata();
                cout << "Enter field of specialisation: ";
                cin.ignore();  getline(cin,sp);
        }
        void getdata()
        {
        	cout << "\nRecords for PG student: ";
        	Student::getdata();
        	cout << "Field of specialisation: " ;
        	cout << sp << endl;
        }
};

class RS_S:public Student
{
	private:
        string n;
        string sp;
	public:
        void setdata()
        {
                cout <<"\nEnter records for Research student: ";
                Student::setdata();
                cout <<"\nEnter field of specialisation: ";
                cin.ignore();  getline(cin,sp);
                cout <<"Enter total no. of publications: ";
                cin.ignore();  getline(cin,n);
        }
        void getdata()
        {
        	cout <<"\nRecords for Research student: ";
        	Student::getdata();
        	cout <<"Field of specialisation: ";
        	cout << sp;
        	cout <<"\nNo. of publications: "<<n<<endl;
        }
};

class Alumni:public Person
{
	private:
        string py;
        string e_no,c_employment;
	public:
        void setdata()
        {
        	cout << "\nEnter the records of alumni: ";
        	Person::setdata();
        	cout << "Enter year of passing: ";
        	cin.ignore();  getline(cin,py);
        	cout <<"Enter Enrollment No: ";
        	cin.ignore();  getline(cin,e_no);
        	cout << "Enter Current Employment: ";
        	cin.ignore();  getline(cin,c_employment);
        }
        void getdata()
        {
        	cout << "\nRecords of almuni: "<< endl;
        	Person::getdata();
        	cout << "\nEnrollment No: "<< e_no <<endl;
        	cout << "Year of passing: "<< py << endl;
        	cout << "Currnet Employment: "<< c_employment << endl;
        }
};

class Employee:public Person
{
	private:
        string record;
        string designation;
	public:
        void setdata()
        {
                cout << "\nEnter records for Employee: ";
                Person::setdata();
                cout << "Enter Desgination: ";
                cin.ignore();  getline(cin,designation);
                cout << "\nLeave record: ";
                cin.ignore();  getline(cin,record);
        }
        void getdata()
        {
                cout <<"\nRecords for Employee: ";
                Person::getdata();
                cout <<"\nDesignation: "<< designation << endl;
                cout <<"Leave record: "<< record << endl;
        }
};

class Faculty:public Employee
{
	private:
        string id;
        string sp;
	public:
        void setdata()
        {
                cout <<"\nEnter record of faculty member: ";
                Employee::setdata();
                cout <<"Enter Faculty ID: "<< endl;
                cin.ignore();  getline(cin,id);
                cout <<"Enter specialization: "<< endl;
                cin.ignore();  getline(cin,sp);
        }
        void getdata()
        {
                cout <<"\nRecords of faculty member: ";
                Employee::getdata();
                cout <<"Faculty ID: "<< id << endl;
                cout <<"Specialization: "<< sp << endl;
        }
};

class Staff:public Employee
{
	public:
        void setdata()
        {
                cout <<"\nEnter records of staff member: \n";
                Employee::setdata();
        }
        void getdata()
        {
        	cout <<"\nRecords of staff member: ";
        	Employee::getdata();
        }
};

int main()
{
        int p,q,r;
        Alumni A;
        UG_S U;
        PG_S P;
        RS_S R;
        Staff SF;
        Faculty Fac;
        I:cout << "\n\nENTER YOUR CHOICE\n1.Entry Record\n2.Display record\n3.For exit\n";
        cin >> p;
	switch(p)
        {
		case 1:
        	{
			cout << "\n\nENTER CHOICE TO RECORD ENTRY\n1.Student\n2.Alumni\n3.Employee: \n";
			cin >> q;
			switch(q)
                        {
				case 1:
                                {
                                        cout << "\n\nEnter choice \n1.UG Student\n2.PG Student\n3.RS student\n";
                                        cin >> r;
                                        if(r==1)
                                                U.setdata();
                                        else if(r==2)
                                                P.setdata();
                                        else if(r==3)
                                                R.setdata();
                                }break;
                                case 2:
                                {
                                        A.setdata();
                                }break;
                           	case 3:
                                {
                                       cout << "\n\nEnter choice for employee:\n1.Faculty\n2.Staff";
                                       cin >> r;
                                       if(r==1)
                                 		Fac.setdata();
                                       else if(r==2)
                                                SF.setdata();
                                }break;
                          }

                }break;
		case 2:
                {
                	cout << "\n\nENTER CHOICE TO DISPLAY ENTRY\n1.Student\n2.Alumni\n3.Employee: \n";
                        cin >> q;
                        switch (q)
                        {
                        	case 1:
                                {
                                        cout << "\n\nEnter choice \n1.UG Student\n2.PG Student\n3.RS student\n";
                                        cin >> r;
                                        if(r==1)
                                                U.getdata();
                                        else if(r==2)
                                                P.getdata();
                                        else if(r==3)
                                                R.getdata();
                                }break;
                                case 2:
                                {
                                        A.getdata();
                                }break;
                           case 3:
                                {
                                        cout << "\n\nEnter choice for employee:\n1.Faculty\n2.Staff\n";
                                        cin >> r;
                                        if(r==1)
                                        	Fac.getdata();
                                        else if(r==2)
                                                SF.getdata(); 
                                 }break;
                           }
                        }break;

          	case 3:
                	return 0;
                default:
                	cout<<"\nWrong Input...\n"; 
                	return 0;
          }
          goto I;
}
