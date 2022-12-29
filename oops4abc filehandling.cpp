#include<iostream>
#include<fstream>

using namespace std;

class student
{
    int roll_no;
    char name[10];

    public:

    void getdata()
    {
        cout << "Enter your name: ";
        cin >> name;
        cout << "Enter your roll_no: ";
        cin >> roll_no;
    }

    void display()
    {
        cout << "Your name is: " << name << endl;
        cout << "Your roll no is: " << roll_no << endl;
    }
};

int main()
{
    int n, i;
    student s;

    fstream f;
    f.open("abc.txt", ios::out);
    cout << "Enter the value of n: ";
    cin >> n;
    for ( i = 0; i < n; i++)
    {
        s.getdata();
        f.write((char*)&s, sizeof s);
    }

    f.close();

    f.open("abc.txt", ios::in);
    for ( i = 0; i < n; i++)
    {
        f.read((char*)&s, sizeof s);
        s.display();
    }

    return 0;
}