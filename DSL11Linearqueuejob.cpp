#include<iostream>
#include<queue>

using namespace std;

class Queue{
    int *arr;
    int front;
    int rear;
    int size;

    public:
    Queue(int n)
    {
        size = n;
        arr = new int[size];
        front = rear = 0;

    }

    void enqueue(int data)
    {
        if(rear == size)
        {
            cout << "Queue is full";
        }
        else
        {
            arr[rear] = data;
            rear++;
        }
    }

    int dequeue()
    {
        if(front == rear)
        {
            return -1;
        }
        else{
            arr[front] = -1;
            front++;
            if(front == rear){
                front = rear = 0;
            }
        }
    }

    void print()
    {
        if(front == rear)
        {
            cout << "Your Queue is empty";
        }
        else
        {
            for(int i=front; i<rear; i++)
            {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
    }
};

int main(){
    Queue q(5);
    q.enqueue(10); 
    q.enqueue(20); 
    q.enqueue(30);
    q.print();
    q.dequeue(); 
    q.print();
    return 0;
}
