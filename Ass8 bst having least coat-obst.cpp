#include <iostream>
#include <iomanip>

using namespace std;

const int MAX = 10;

class obst
{
public:
    int N;

    int a[MAX];
    float p[MAX];
    float q[MAX];
    float w[MAX][MAX];
    float c[MAX][MAX];
    int r[MAX][MAX];

    obst(int n = 0)
    {
        N = n + 1;

        for (int i = 0; i < N; i++)
        {
            a[i] = 0;
            p[i] = 0;
            q[i] = 0;

            for (int j = 0; j < N; j++)
            {
                w[i][j] = 0;
                c[i][j] = 0;
                r[i][j] = 0;
            }
        }
    }

    void read()
    {
        cout << "Enter the key values: " << endl;

        for (int i = 1; i < N; i++)
        {
            cout << "a[ " << i << "]";
            cin >> a[i];
        }

        cout << "Enter the success probability values: " << endl;

        for (int i = 1; i < N; i++)
        {
            cout << "p[ " << i << "]";
            cin >> p[i];
        }

        cout << "Enter the failure probability values: " << endl;

        for (int i = 1; i <= N; i++)
        {
            cout << "q[ " << i << "]";
            cin >> q[i];
        }
    }

    void display()
    {
        cout << " a = { ";

        for (int i = 1; i < N; i++)
        {
            cout << setw(3) << a[i] << " , ";
        }
        cout << "\b\b}" << endl;

        cout << " p = { ";

        for (int i = 1; i < N; i++)
        {
            cout << setw(3) << p[i] << " , ";
        }
        cout << "\b\b}" << endl;

        cout << " q = { ";

        for (int i = 1; i <= N; i++)
        {
            cout << setw(3) << q[i] << " ";
        }
        cout << "\b\b}" << endl;
    }

    void display_obst()
    {
        cout << " w = {  " << endl;

        for (int i = 0; i < N; i++)
        {

            cout << "       ";

            for (int j = 0; j < N; j++)
            {
                cout << setw(3) << w[i][j] << " , ";
            }
            cout << "\b\b" << endl;
        }
        cout << "       }" << endl;

        cout << " c = { " << endl;

        for (int i = 0; i < N; i++)
        {

            cout << "       ";

            for (int j = 0; j < N; j++)
            {
                cout << setw(3) << c[i][j] << " , " ;
            }
            cout << "\b\b" << endl;
        }
        cout << "      }" << endl;

        cout << " r = { " << endl;

        for (int i = 0; i < N; i++)
        {

            cout << "       ";

            for (int j = 0; j < N; j++)
            {
                cout << setw(3) << r[i][j];
            }
            cout << "\b\b" << endl;
        }
        cout << "        }" << endl;
    }

    void create()
    {
        for (int i = 0; i < N; i++)
        {
            w[i][i] = q[i];
            c[i][i] = 0;
            r[i][i] = 0;

            w[i][i + 1] = w[i][i] + p[i + 1] + q[i + 1];
            c[i][i + 1] = w[i][i + 1];
            r[i][i + 1] = i + 1;
        }

        for (int m = 2; m <=N; m++)
        {

            for(int i=0; i<N-m; i++)
            {
                int j = i + m;

                w[i][j] = w[i][j - 1] + p[j] + q[j];

                float min = 999;
                int min_k = i+1;
                float newcost;
                for(int k = i+1; k<=j; k++)
                {
                    newcost = c[i][k-1] + c[k][j];

                    if(newcost < min)
                    {
                        min = newcost;
                        min_k = k;
                    }


                }
                c[i][j] = min + w[i][j];
                r[i][j] = min_k;
            }
            
        }
    }
};

int main()
{
    int n;
    cout << "Enter number of keys : ";
    cin >> n;
    obst b(n);
    b.read();
    b.create();
    b.display();
    b.display_obst();

    return 0;
}