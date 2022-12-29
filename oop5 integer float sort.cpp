#include <iostream>
using namespace std;

int n;

template <class T>

void sel(T S[])
{
    int min;
    T temp;

    for (int i = 0; i < n-1; i++)
    {
        min = i;
        for (int j = i + 1; j < n; j++)
        {
            if (S[j] < S[min])
                min = j;
        }
        temp = S[i];
        S[i] = S[min];
        S[min] = temp;
    }

    cout << "Sorted array given below " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << " " << S[i] << endl;
    }
}

int main()
{
    cout << "Enter Total number of integer elements " << endl;
    cin >> n;

    int S[n];
    float R[n];

    for (int i = 0; i < n; i++)
    {
        cout << "S[" << i << "] = ";
        cin >> S[i];
    }

    sel(S);

    cout << "Enter Total number of float elements " << endl;

    for (int i = 0; i < n; i++)
    {
        cout << "R[" << i << "] = " << endl;
        cin >> R[i];
    }

    sel(R);

    return 0;
}