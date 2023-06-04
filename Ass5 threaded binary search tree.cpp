#include <iostream>
using namespace std;

const int INT_MAX = 100;


class node
{
private:
    node *left;
    node *right;
    bool lthread;
    bool rthread;
    int data;

public:
    node(int d)
    {
        data = d;
        this->left = NULL;
        this->right = NULL;
        lthread = true;
        rthread = true;
    }
    friend class tbst;
};

class tbst
{

    node *root;
    node *dummy;

public:
    tbst()
    {
        root = NULL;
        dummy = NULL;
    }

    void create()
    {
        int element;
        cout << "Enter the element you want to insert " << endl;
        cin >> element;
        node *temp = new node(element);

        if (root == NULL)
        {
            root = temp;

            dummy = new node(INT_MAX);
            dummy->left = root;
            dummy->lthread = false;
            dummy->right = dummy;
            dummy->rthread = false;

            root->left = dummy;
            root->lthread = true;
            root->right = dummy;
            root->rthread = true;
        }
        else
        {
            node *curr = root;

            while (1)
            {
                if (temp->data < curr->data)
                {
                    if (curr->lthread == false)
                    {
                        curr = curr->left;
                    }
                    else
                    {
                        break;
                    }
                }
                else if (temp->data > curr->data)
                {
                    if (curr->rthread == false)
                    {
                        curr = curr->right;
                    }
                    else
                    {
                        break;
                    }
                }
            }

            if(temp->data < curr->data)
            {
                temp->left = curr->left;
                temp->lthread = true;
                temp->right = curr;
                temp->rthread = true;

                curr->left = temp;
                curr->lthread = false;
            }
            else if(temp->data > curr->data)
            {
                temp->left = curr;
                temp->lthread = true;
                temp->right = curr->right;
                temp->rthread = true;

                curr->right = temp;
                curr->rthread = false;
            }
        }
    }

    node*successor(node*curr)
    {
        if(curr->rthread == true)
        {
            return curr->right;
        }
        else{
            curr = curr->right;
            while(curr->lthread == false)
            {
                curr = curr->left;
            }
            return curr;
        }
    }

    void inorder(node*curr)
    {
        if(curr == NULL)
        {
            return;
        }

        while(curr->lthread == false)
        {
            curr= curr->left;
        }

        while(curr != dummy)
        {
            cout << curr->data << " ";
            curr = successor(curr);
        }
    }

    void inorder()
    {
        node*curr = root;
        cout << "printing the inorder traversal of threaded bst" << endl;
        inorder(curr);
    }
};

int main()
{

    tbst t1;
    t1.create();
    t1.create();
    t1.create();
    t1.create();
    t1.create();
    t1.create();
    t1.create();

    t1.inorder();

    return 0;
}