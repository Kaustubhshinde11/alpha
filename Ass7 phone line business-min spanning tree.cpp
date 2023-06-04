#include<iostream>
using namespace std;

const int MAX = 100;

class graph{

    public:

    int vertices;
    int edges;
    int arr[100][100];

    void create()
    {
        cout << "Enter the vertices: ";
        cin >> vertices;

        int start, end, weight;

        for(int i =0; i<vertices; i++)
        {
            for(int j=0; j<vertices; j++)
            {
                arr[i][j] = 0;
            }
        }


        cout << "Enter total edges: " << endl;
        cin >> edges;

        for(int i=0; i<edges; i++)
        {
            cout << "Enter the start and end vertex ";
            cin >> start >> end;
            cout << "Enter the weight of " << start << " to " << end << endl;
            cin >> weight;
            arr[start][end] = weight;
            arr[end][start] = weight;
        }

    }

    void display()
    {
        for(int i =0; i<vertices; i++)
        {
            for(int j=0; j<vertices; j++)
            {
                cout << arr[i][j] << " ";
            }
            cout << endl;
        }
    }

    int minset(int key[], bool mset[])
    {
        int min = MAX;
        int min_index;
        for(int i=0; i<vertices; i++)
        {
            if(key[i] < min && mset[i] == false)
            {
                min = key[i];
                min_index = i;
                
            }
        }
        return min_index;
    }

    void prims()
    {
        int parent[vertices];
        int key[vertices];
        bool mset[vertices];

        for(int i=0; i<vertices; i++)
        {

            key[i] = MAX;
            mset[i] = false;
        }

        key[0] = 0;
        parent[0] = 1;

        for(int i=0; i<vertices; i++)
        {
            int u = minset(key, mset);
            mset[u] = true;
            for(int j=0; j<vertices; j++)
            {
                if(arr[u][j] != 0 && mset[j] == false && arr[u][j] < key[j])
                {
                    parent[j] =u;
                    key[j] = arr[u][j];
                }
            }
        }

        int MST[vertices][vertices];

        for(int i=0; i<vertices; i++)
        {
            for(int j=0; j<vertices; j++)
            {
                MST[i][j] = 0;
            }
        }

        for(int i=1; i<vertices; i++)
        {
            MST[parent[i]][i] = arr[parent[i]][i];
            MST[i][parent[i]] = arr[i][parent[i]];
        }

        int min_cost = 0;

        for(int i=1; i<vertices; i++)
        {
            
            min_cost += MST[parent[i]][i];

        }

        cout << "Prims min_cost: " << min_cost << endl;
        
    }
};

int main(){
    graph g;
    g.create();
    g.display();
    g.prims();
    return 0;
}