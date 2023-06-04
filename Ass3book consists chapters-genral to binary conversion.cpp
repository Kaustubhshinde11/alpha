#include<iostream>
using namespace std;

class node{

    private:
    string title;
    node*left;
    node*right;

    public:

    node(string title = NULL)
    {
        this->title = title;
        this->left = NULL;
        this->right = NULL;
    }

    void display()
    {
        cout << this->title;
    }
    friend class BST;
};

class BST{
    node*root;

    public:
    BST()
    {
        root = NULL;
    }

    BST(string title)
    {
        root = new node(title);
    }

    void display()
    {
        if(root == NULL)
        {
            cout << "Nothing to display" << endl;
            return;
        }
        else{
            cout << "The details of the chapter " << root->title << " is as follows " << endl;
            preorder(root);
        }
    }

    void preorder(node*root)
    {
        if(root != NULL)
        {
            cout << root->title << " ";
            preorder(root->left);
            preorder(root->right);
        }cout << endl;
        
    }

    node*search(node*root, string chap_name)
    {
    
        if(root == NULL)
        {
            return NULL;
        }
        else{
            while(root != NULL)
            {
                if(root->title == chap_name)
                {
                    return root;
                    break;
                }
                root = root->right;
            }
            return NULL;

        }
    }

    node*lastsearch(node*root)
    {
        if(root == NULL)
        {
            return NULL;
        }
        else{
            while(root->right != NULL)
            {
                root = root->right;
            }
            return root;
        }
    }

    void addchapter(string chap_name)
    {
        if(root == NULL)
        {
            cout << "NO chapters are present " << endl;
            return;
        }
        else{
            node*chap = root->left;

            if(chap == NULL)
            {
                root->left = new node(chap_name);
                cout << "added successfully";
            }
            else{
                chap = search(chap, chap_name);
                if(chap == NULL)
                {
                    node*last;
                    last = lastsearch(chap);

                    last->right = new node(chap_name);
                    cout << "added";
                }
                else{
                    cout << "duplicate";
                }
            }
        }
    }

    void add_section(string chapter, string section_name)
    {
        if(root == NULL)
        {
            cout << "No book so no chapter so no section " << endl;
            return;
        }
        else{
            node*chap;
            chap = root->left;
            if(chap == NULL)
            {
                cout << "No chapter is present there " << endl;
                return;
            }
            else{
                chap = search(chap, chapter);
                if(chap == NULL)
                {
                    cout << "Chapter isn't found then can't add section" << endl;
                }
                else{
                    node*section;
                    section = chap->left;

                    if(section == NULL)
                    {
                        chap->left = new node(section_name);
                        cout << chapter << "chapter has been added with " << section_name << "section successfully" << endl;                   
                    }
                    else{
                        section = search(chap->left, section_name);
                        if(section == NULL)
                        {
                        
                            section = lastsearch(chap->left);
                            section->right = new node(section_name);
                            cout << "Section has been added successfully" << endl;
                        }
                        else{
                            cout << "Duplicate section entries are not allowed " << endl;
                        }
                        
                    }
                }
            }
        }
    }
};

int main(){
    string book;
    cout << "Entr name of book " << endl;
    cin >> book;

    BST b(book);

    
    

    b.addchapter("Environment");
    b.add_section("Environment","female");
    b.display();
    
    return 0;
}