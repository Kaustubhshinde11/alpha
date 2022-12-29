#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

class person{
    public:
    char name[20];
    int code;
    int dateofbirth;
    int telephone_no;

    bool operator==(const person &p1)
    {
        if(code == p1.code)
        {
            return 1;
        }
        return 0;
    }

    int operator<(const person &p1)
    {
        if(code < p1.code)
        {
            return 1;
        }
        return 0;
    }
};

vector<person> o1;

bool compare(const person &p1, const person &p2)
{
    return p1.code < p2.code;
}

void insert()
{
    person p1;

    cout << "Enter your name: ";
    cin >> p1.name;

    cout << "Enter your code: ";
    cin >> p1.code;

    cout << "Enter your date of birth: ";
    cin >> p1.dateofbirth;

    cout << "Enter your telephone number: ";
    cin >> p1.telephone_no;

    o1.push_back(p1);
}

void print(person &p1)
{
    cout << "\n";
    cout << "Your name: " << p1.name << endl;
    cout << "Your DOB: " << p1.dateofbirth << endl;
    cout << "Your telephone number: " << p1.telephone_no << endl;
    cout << "Your code: " << p1.code << endl;
}

void search()
{
    vector<person>::iterator p;
    person p1;
    cout << "Enter the element you have to search for: ";
    cin >> p1.code;
    p = find(o1.begin(), o1.end(), p1);

    if(p == o1.end())
    {
        cout << "Element not found" << endl;

    }
    else{
        cout << "Element found " << endl;
    }
}

void Delete()
{
    vector<person>::iterator p;
    person p1;
    cout << "Enter the element to be deleted: ";
    cin >> p1.code;
    p = find(o1.begin(), o1.end(), p1);

    if(p == o1.end())
    {
        cout << "Element not found" << endl;
    }
    else
    {
        o1.erase(p);
        cout << "Element deleted" << endl;
    }
}

void display()
{
    for_each(o1.begin(), o1.end(), print);
}

int main(){
    int ch;
    do
    {
        cout << "---Menu----" << endl;
        cout << "\n1. Insert";
        cout << "\n2.Display";
        cout << "\n3.sort";
        cout << "\n4.search";
        cout << "\n5.delete";
        cout << "\n6.Exit";
        cout << "\nEnter your choice: "<< endl;
        cin >> ch;
        switch(ch)
        {
            case 1:
            {
                insert();
                break;
            }
            case 2:
            {
                display();
                break;
            }
            case 3:
            {
                search();
                break;
            }
            case 4:
            {
                sort(o1.begin(), o1.end(), compare);
                cout << "sorted code";
                display();
                break;
            }
            case 5:
            {
                Delete();
                break;
            }
            case 6:
            {
                exit(0);
            }
        }
        
    }while(ch != 7);
    

    
    return 0;
}