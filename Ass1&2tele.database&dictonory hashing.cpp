#include <iostream>
using namespace std;

class client
{
public:
    int id;
    string telephone;
    string name;

    client()
    {
        id = -1;
        telephone = " ";
        name = " ";
    }

    client(int id, string telephone, string name)
    {
        this->id = id;
        this->telephone = telephone;
        this->name = name;
    }
};

class map
{

    public:

    client array[10];

    void insert(int id, string telephone, string name)
    {
        int ind = id % 10;

        while (ind <= 9)
        {
            if (array[ind].telephone == " ")
            {
                array[ind] = client(id, telephone, name);
                break;
            }
            else
            {
                if (array[ind].telephone != " ")
                {
                    if (ind == 9)
                    {
                        ind = 0;
                    }
                    ind++;
                }
            }
        }
    }

    void display()
    {
        for(int i=0; i<10; i++)
        {
            if(array[i].telephone != " ")
            {
                cout << "Printing all values for " << i << endl;
                cout << "name: " << array[i].name << endl;
                cout << "telephone: " << array[i].telephone << endl;
            }
            cout << endl;
            
        }
        
    }

    void search(int id)
    {
        int index = id%10;

        while(index <= 9)
        {
            if(array[index].id == id)
            {
                cout << array[index].telephone << endl;
                cout << array[index].name << endl;
                break;
            }
            else{
                if(index == 9)
                {
                    index = 0;
                }
                index++;
            }
        }
    }

};

int main()
{
    map m1;

    m1.insert(101, "1019910", "ram");
    m1.insert(102, "1077110", "shyam");
    m1.insert(103, "1078110", "karn");
    m1.insert(104, "1999110", "varm");

    m1.search(103);

    m1.display();


    return 0;
}