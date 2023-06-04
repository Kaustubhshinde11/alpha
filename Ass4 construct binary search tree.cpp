#include <iostream>
#include <queue>

using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;
    int height;

    node(int d)
    {
        data = d;
        this->left = NULL;
        this->right = NULL;
        height = 1;
    }
};

int getheight(node *&root)
{
    if (root == NULL)
    {
        return 0;
    }
    return 1 + max(getheight(root->left), getheight(root->right));
}

node *create(node *&root, int data)
{
    node *temp = new node(data);

    if (root == NULL)
    {
        root = temp;
    }

    if (data < root->data)
    {
        root->left = create(root->left, data);
    }
    if (data > root->data)
    {
        root->right = create(root->right, data);
    }

    return root;
}

void preorder(node *root)
{
    if (root != NULL)
    {
        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }
}

void levelordertraversal(node *root)
{
    if (root == NULL)
    {
        return;
    }

    node *temp = root;
    queue<node *> q;

    q.push(root);

    while (!q.empty() || temp != NULL)
    {

        temp = q.front();
        q.pop();
        cout << temp->data << " ";

        if (temp->left)
        {
            q.push(temp->left);
        }
        if (temp->right)
        {
            q.push(temp->right);
        }
    }
}

int getmin(node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    else
    {
        node *temp = root;

        while (temp->left != NULL)
        {
            temp = temp->left;
        }

        return temp->data;
    }
}

int main()
{
    node *root = NULL;

    root = create(root, 5);
    root = create(root, 9);
    root = create(root, 15);
    root = create(root, 25);
    root = create(root, 8);
    root = create(root, 7);
    root = create(root, 23);
    root = create(root, 1);
    root = create(root, 2);
    root = create(root, 3);
    preorder(root);

    int h = getheight(root);

    int m = getmin(root);

    cout << "height is: " << h << endl;

    cout << "minimum is: " << m << endl;

    levelordertraversal(root);

    return 0;
}