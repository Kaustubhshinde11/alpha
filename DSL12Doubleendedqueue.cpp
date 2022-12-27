#include<iostream>
using namespace std;

class queue{
    int*arr;
    int size;
    int front;
    int rear;

    public:

    queue(int n)
    {
        size = n;
        arr = new int[size];
        front = rear = -1;
    }

    void push_front(int data)
    {
        if((front ==0 && rear == size-1) || (front != 0 && rear == (front-1)%(size-1)))
        {
            cout << "Queue is full";
        }
        else if(front == -1)
        {
            front = rear = 0;
        }
        else if(front == 0 && rear != size-1)
        {
            front = size-1;
        }
        else
        {
            front--;
        }
        arr[front] = data;
    }

    void push_back(int data)
    {
        if((front ==0 && rear == size-1) || (front != 0 && rear == (front-1)%(size-1)))
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
        else{
            rear++;
        }
        arr[rear] = data;

    }

    int pop_front()
    {
        if(front == -1)
        {
            return -1;
        }
        int ans = arr[front];
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
        return ans;
    }

    int pop_back()
    {
        if(front == -1)
        {
            return -1;
        }
        int ans = arr[front];
        arr[front] = -1;
        if(front == rear)
        {
            front = rear = -1;
        }
        else if(rear == 0)
        {
            rear = size-1;
        }
        else
        {
            rear--;
        }
        return ans;
    }

    void givefront()
    {
        if(front == -1)
        {
            cout << "Queue is empty";
        }
        else
        {
            cout << arr[front] << " ";
        }
        cout << endl;
    }

    void print()
    {
        if(front == -1)
        {
            cout << "Queue is empty" << endl;
            return;
        }

        cout << "Queue" << endl;
        if(rear>=front)
        {
            for(int i = front; i<=rear; i++)
            {
                cout << arr[i] << " ";
            }
        }
        else
        {
            for(int i = front; i<size; i++)
            {
                cout << arr[i] << " ";
            }
            for(int i = 0; i<=rear; i++)
            {
                cout << arr[i] << " ";

            }
            
        }
        cout << endl;
    }
};

int main(){
    queue obj(5);
    obj.push_front(10);
    //obj.givefront();
    obj.push_front(20);
    obj.push_front(25);
    obj.push_front(26);
    obj.push_front(27);
    obj.print();
    obj.pop_front();
    obj.print();

    
    return 0;
}