#include <iostream>
using namespace std;

class node
{
public:
    int roll_no;
    node *next;

    node(int roll_n0)
    {
        this->roll_no = roll_n0;
        this->next = NULL;
    }
};

void insert(node *&head, int d)
{
    node *temp = new node(d);
    temp->next = head;
    head = temp;
}

void intersection(node *vanilla, node *butter)
{
    node *travel = vanilla;
    while (travel != NULL)
    {
        node *travel2 = butter;
        while (travel2 != NULL)
        {
            if (travel2->roll_no == travel->roll_no)
            {
                cout << travel->roll_no << " ";
                break;
            }
            travel2 = travel2->next;
        }
        travel = travel->next;
    }
    cout << endl;
}

void eithervobont(node *&vanilla, node *&butter, node *&std)
{
    node *travel = std;
    while (travel != NULL)
    {
        bool p1 = false, p2 = false;
        node *travel2 = vanilla;
        while (travel2 != NULL)
        {
            if (travel2->roll_no == travel->roll_no)
            {
                p1 = true;
                break;
            }
            travel2 = travel2->next;
        }

        travel2 = butter;
        while (travel2 != NULL)
        {
            if (travel2->roll_no == travel->roll_no)
            {
                p2 = true;
                break;
            }
            travel2 = travel2->next;
        }

        if (!(p1 == true && p2 == true))
        {
            cout << travel->roll_no << " ";
        }
        travel = travel->next;
    }
    cout << endl;
}

void neither(node *vanilla, node *butter, node *std)
{
    node *travel = std;
    while (travel != NULL)
    {
        bool p = false;
        node *temp = vanilla;
        while (temp != NULL)
        {
            if (temp->roll_no == travel->roll_no)
            {
                p = true;
                break;
            }
            temp = temp->next;
        }

        temp = butter;
        while (temp != NULL)
        {
            if (temp->roll_no == travel->roll_no)
            {
                p = true;
                break;
            }
            temp = temp->next;
        }

        if (p == false)
        {
            cout << travel->roll_no << " ";
        }
        travel = travel->next;
    }
    cout << endl;
}

int main()
{
    node *vanilla = NULL;
    node *butter = NULL;
    node *std = NULL;

    insert(std, 10);
    insert(std, 20);
    insert(std, 30);
    insert(std, 40);
    insert(std, 50);
    insert(std, 60);
    insert(std, 70);
    insert(std, 80);
    insert(std, 90);
    insert(std, 100);

    insert(vanilla, 10);
    insert(vanilla, 20);
    insert(vanilla, 30);
    insert(vanilla, 100);

    insert(butter, 20);
    insert(butter, 60);
    insert(butter, 70);
    insert(butter, 100);

    intersection(vanilla, butter);

    eithervobont(vanilla, butter, std);
    neither(vanilla, butter, std);

    return 0;
}