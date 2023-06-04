#include<iostream>
using namespace std;

class node{
    public:

    node*left;
    node*right;
    int data;
    int height;

    node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
        height = 1;
    }

};

int getheight(node*root)
{
    if(root == NULL)
    {
        return 0;
    }
    return root->height;
}

int getbf(node*root)
{
    if(root == NULL)
    {
        return 0;
    }
    return getheight(root->left)-getheight(root->right);
}

node*rotateleft(node*x)
{
    node*y = x->right;
    node*z = y->left;

    y->left = x;
    x->right = z;

    x->height = 1 + max(getheight(x->left), getheight(x->right));
    y->height = 1 + max(getheight(y->left), getheight(y->right));

    return y;
}

node*rightrotate(node*y)
{
    node*x = y->left;
    node*z = x->right;

    x->right = y;
    y->left = z;

    x->height = 1 + max(getheight(x->left), getheight(x->right));
    y->height = 1 + max(getheight(y->left), getheight(y->right));

    return x;

}

void preorder(node*root)
{
    if(root != NULL)
    {
        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }
}

node*buildtree(node*root, int data)
{
    if(root == NULL)
    {
        root = new node(data);
    }

    if(data < root->data)
    {
        root->left = buildtree(root->left, data);
    }
    else if(data > root->data)
    {
        root->right = buildtree(root->right, data);
    }
    else{
        return root;
    }

    root->height = 1+max(getheight(root->left), getheight(root->right));

    int bf = getbf(root);

    if((bf > 1) && (data < root->left->data))
    {
        return rightrotate(root);
        
    }
    if((bf > 1) && (data > root->left->data))
    {
        root->left = rotateleft(root->left);
        return rightrotate(root);
    }
    if((bf < -1) && (data > root->right->data))
    {
        return rotateleft(root);
    }
    if((bf < -1) && (data < root->right->data))
    {
        root->right = rightrotate(root->right);
        return rotateleft(root);
    }

    return root;

}

int main(){

    node*root = NULL;

    root = buildtree(root, 8);
    root = buildtree(root, 9);
    root = buildtree(root, 3);
    root = buildtree(root, 12);
    root = buildtree(root, 10);
    //root = buildtree(root, 10);
    

    preorder(root);
    return 0;
}