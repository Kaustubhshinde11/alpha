#include<iostream>
using namespace std;

class queue
{
    int*arr;
    int size;
    int front;
    int rear;

    public:
    queue(int n)
    {
        size = n;
        arr= new int[size];
        front = rear = -1;
    }

    void Enqueue(int data)
    {
        if((front == 0 && rear == size-1) || (rear == (front-1)%(size-1)))
        {
            cout << "Queue is full";
        }
        else if(front == -1)
        {
            front = rear = 0;
         
        }
        else if(rear == size-1 && front != 0)
        {
            rear = 0;
        }
        else
        {
            rear++;
        }
        arr[rear] = data;
    }

    int dequeue()
    {
        if(front == -1)
        {
            return -1;
        }
        arr[front] = -1;
        if(front == rear)
        {
            front = rear = -1;
        }
        else if(front == size-1)
        {
            front = 0;
        }
        else{
            front++;
        }

    }

    void print()
    {
        if(front == -1)
        {
            cout << "Queue is empty";
        }
        else
        {
            for (int i = front; i <= rear; i++)
            {
                cout << arr[i] << " ";

            }
            cout << endl;
            
        }
    }


};

int main(){
    queue obj(5);
    obj.Enqueue(10);
    obj.Enqueue(20);
    obj.Enqueue(30);
    obj.Enqueue(40);
    obj.dequeue();
    obj.print();
    
    return 0;
}