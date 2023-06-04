#include <bits/stdc++.h>
using namespace std;

struct Student
{
    int roll_no;
    string name;
    string division;
    string address;
};

void get(Student stud)
{
    fstream f;
    f.open("yup.txt", ios::out | ios::app);

    f << stud.roll_no << " " << stud.name << " " << stud.division << " " << stud.address;

    f.close();
}

void delete_info(int roll)
{
    fstream f;
    f.open("yup.txt", ios::in);

    fstream myf;

    myf.open("yupp.txt", ios::out);

    Student stud;

    while (f >> stud.roll_no >> stud.name >> stud.division >> stud.address)
    {
        if (stud.roll_no != roll)
        {
            myf << stud.roll_no << " " << stud.name << " " << stud.division << " " << stud.address;
        }
    }
    myf.close();

    f.close();

    remove("yup.txt");
    rename("yupp.txt", "yup.txt");
}

void display(int roll)
{
    fstream f;

    f.open("yup.txt", ios::in);

    Student stud;

    while (f >> stud.roll_no >> stud.name >> stud.division >> stud.address)
    {
        if (stud.roll_no == roll)
        {
            cout << "Roll no: " << stud.roll_no << endl;
            cout << "Name: " << stud.name << endl;
            cout << "Division: " << stud.division << endl;
            cout << "Address: " << stud.address << endl;
            f.close();
            return;
        }
    }

    cout << "No student found " << endl;

    f.close();
}

int main()
{

    int choice;

    while (true)
    {
        cout << "************* MENU *************\n";
        cout << "1. Add student" << endl;
        cout << "2. Delete student" << endl;
        cout << "3. Display student" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            cout << "Enter student details: " << endl;

            int roll_number;
            string name, division, address;

            cout << "Enter Roll number: ";
            cin >> roll_number;
            cout << "Enter Name: ";
            cin >> name;
            cout << "Enter Division: ";
            cin >> division;
            cout << "Enter Address: ";
            cin >> address;

            Student student = {roll_number, name, division, address};

            get(student);

            break;
        }
        case 2:
        {
            cout << "Enter student roll number to delete: " << endl;

            int roll_number;
            cout << "Enter Roll number to delete: ";
            cin >> roll_number;

            delete_info(roll_number);

            break;
        }
        case 3:
        {
            cout << "Enter student roll number to display: " << endl;

            int roll_number;
            cin >> roll_number;

            display(roll_number);

            break;
        }
        case 4:
        {
            return 0;
        }
        default:
        {
            cout << "Invalid choice!" << endl;
            break;
        }
        }
        cout << endl << endl;
    }
}