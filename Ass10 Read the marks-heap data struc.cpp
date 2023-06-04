#include <iostream>
using namespace std;

class heap
{
private:
    int N;
    int *minheap;
    int *maxheap;

public:
    heap(int n)
    {
        N = n;
        minheap = new int[N];
        maxheap = new int[N];
        minheap[0] = -1;
        maxheap[0] = -1;
    }

    void get()
    {
        int marks;
        cout << "enter the marks you want: ";
        for (int i = 1; i < N; i++)
        {
            cin >> marks;
            minheap[i] = marks;
            heapify(0, i);
            maxheap[i] = marks;
            heapify(1, i);
        }
    }

    void heapify(bool ans, int index)
    {
        if(!ans)
        {
            while((minheap[index/2] > minheap[index]) && (index > 1))
            {
                swap(minheap[index/2], minheap[index]);
                index = index/2;

                if(index <= 1)
                {
                    break;
                }
            }
        }
        else{
            while((maxheap[index/2] < maxheap[index]) && (index > 1))
            {
                swap(maxheap[index/2], maxheap[index]);
                index = index/2;

                if(index <= 1)
                {
                    break;
                }
            }
        }
    }

    

    int getmax()
    {
        cout << maxheap[1] << endl;
    }

    int getmin()
    {
        cout << minheap[1] << endl;
    }
};

int main()
{
    cout << "Enter students: " << endl;
    int N;
    cin >> N;

    heap h1(N);

    h1.get();

    cout << "Maximum value is: " << endl;

    h1.getmax();

    cout << "Minimum value is: " << endl;

    h1.getmin();
    


    return 0;
}