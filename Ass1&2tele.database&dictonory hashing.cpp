#include<iostream>
using namespace std;

class Hash{

    public:

    int*arr;
    int N;

    Hash(int n)
    {
        N = n;
        arr = new int[n];
    }

    void state()
    {
        for (int i = 0; i < 10; i++)
        {
            arr[i] = -1;
        }
        
    }

    void insert(int x)
    {
        int y = x%N;

        while(y <= 9)
        {

            if(arr[y] == -1)
            {
                arr[y] = x;
                break;
            }
            else{
                if(y == 9)
                {
                    y = 0;
                }
                else
                {
                    y++;
                }
                
            }
        }
    }

    void print()
    {
        for(int i=0; i<10; i++)
        {
            cout << i << " -> " << arr[i] << endl;
        }
    }

};

int main(){

    int n;
    cout << "Enter number of telephone directories" << endl;
    cin >> n;

    Hash h1(n);
    

    h1.state();

    h1.insert(21);
    h1.insert(4);
    h1.insert(25);
    h1.insert(34);
    h1.insert(13);
    h1.insert(37);
    h1.insert(73);
    h1.insert(94);

    h1.print();
    
    return 0;
}