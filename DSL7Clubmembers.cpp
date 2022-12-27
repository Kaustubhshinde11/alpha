#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node*next;

    node(int data)
    {
        this-> data = data;
        this-> next = NULL;
    }
    ~node()
    {
        int val = this->data;
        if(this->next != NULL)
        {
            delete next;
            this-> next = NULL;
        }
    }

};

void insertathead(node* &head, int d)
{
    node* temp = new node(d);
    temp-> next = head;
    head = temp;
}

void insertattail(node* &tail, int d)
{
    node*temp = new node(d);
    tail-> next = temp;
    tail = temp;
}

void insertatposition(node*&head, node*&tail, int position, int d)
{
    if(position == 1)
    {
        insertathead(head, d);
        return;
    }

    node*temp = head;
    int count = 1;
    while(count < position -1)
    {
        temp = temp-> next;
        count++;
    }

    if(temp-> next == NULL)
    {
        insertattail(tail, d);
        return;
    }

    node*insertatmiddle = new node(d);
    insertatmiddle-> next = temp-> next;
    temp-> next = insertatmiddle;
}

void deleteit(node*&head, int position)
{
    if(position == 1)
    {
        node*curr = head;
        head = curr->next;
        curr-> next = NULL;
        delete curr;
    }
    else{
        node*curr = head;
        node*prev = NULL;
        int count = 1;
        while(count < position)
        {
            prev = curr;
            curr = curr-> next;
            count++;
        }
        prev-> next = curr-> next;
        curr-> next = NULL;
        delete curr;

    }
}

void print(node*&head)
{
    if(head == NULL)
    {
        cout << "emoty";
        return;
    }
    
    node*temp = head;
    while(temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp-> next;
    }
    cout << endl;
}

int main(){

    node*node1 = new node(5);

    node*head = node1;
    node*tail = node1;

    insertathead(head, 10);
    insertathead(head, 20);
    insertattail(tail, 29);
    print(head);
    deleteit(head, 3);
    print(head);
    
    return 0;
}