#include <iostream>
#include <string.h>

using namespace std;

class personal
{
    string lic, dob;

    public:
    personal();
    personal(personal &);
    ~personal()
    {
        cout << "Destructor is called successfully" << endl;
    }
    friend class student;
};

class student
{
    string name;
    int telephone; 
    long mobile_no;

    public:

    student();
    student(student &);
    ~student()
    {
        cout << "Destructor is called successfully" << endl;
    }

    void create(personal &);
    void display(personal &);
};


student :: student()
{
    name = "Kaustubh Shinde";
    telephone = 556;
    mobile_no = 899687280;
}

personal ::personal()
{
    lic = "ertgh";
    dob = "20";
}

student ::student(student &obj)
{
    this->name = obj.name;
    this->telephone = obj.telephone;
    this->mobile_no = obj.mobile_no;
}

personal :: personal(personal &obj)
{

    this->lic = obj.lic;
    this->dob = obj.dob;
}

void student ::create(personal &obj)
{
    cout << "Enter name: ";
    cin >> name;
    cout << "Enter telephone: ";
    cin >> telephone;
    cout << "Enter mobile: ";
    cin >> mobile_no;
    cout << "lic:";
    cin >> obj.lic;
    cout << "dob: ";
    cin >> obj.dob;
}

void student::display(personal &obj)
{
    cout << "name" << name << endl;
    cout << "telephone" << telephone << endl;
    cout << "mobile" << mobile_no << endl;
    cout << "lic" << obj.lic << endl;
    cout << "dob" << obj.dob << endl;
}

int main()
{
    int ch;
    int n;

    cout << "Enter the value of n: ";
    cin >> n;

    personal *per = new personal[n];
    student *stu = new student[n];

    do
    {
        cout << "-------MENU------" << endl;
        cout << "\n1.create";
        cout << "\n2.display";
        cout << "\n3.copy";
        cout << "\n4.default";
        cout << "\n5.Delete";
        cout << "\n6.exit";
        cout << "Enter your choice: " << endl;
        cin >> ch;
        switch (ch)
        {
        case 1:
        {
            for (int i = 0; i < n; i++)
            {
                stu[i].create(per[i]);
            }
            break;
        }
        case 2:
        {
            for (int i = 0; i < n; i++)
            {
                
                stu[i].display(per[i]);
            }
            break;
        }
        case 3:
        {
            student obj1;
            personal obj2;
            obj1.create(obj2);
            student obj3(obj1);
            personal obj4(obj2);
            obj3.display(obj4);
            break;
        }
        case 4:
        {
            student obj1;
            personal obj2;
            obj1.display(obj2);
            break;
        }
        case 5:
        {
            delete[] stu;
            delete[] per;
            break;
        }
        case 6:
        {
            exit(0);
        }
        }
    } while (ch != 9);

        return 0;
}