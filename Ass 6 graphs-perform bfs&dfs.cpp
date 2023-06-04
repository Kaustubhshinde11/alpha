#include <iostream>
#include <queue>
#include<stack>

using namespace std;

const int N = 10;

class graph
{
public:
    int arr[N][N];

    graph()
    {
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                arr[i][j] = 0;
            }
        }
    }

    void add(int u, int v)
    {
        arr[u][v] = 1;
        arr[v][u] = 1;
    }

    void display(int v)
    {
        for (int i = 0; i < v; i++)
        {
            for (int j = 0; j < v; j++)
            {
                cout << arr[i][j] << " ";
            }
            cout << endl;
        }
    }

    void bfs(int start, int m)
    {
        int visited[10] = {0};
        int u, v;
        queue<int> q;

        cout << start << " ";

        q.push(start);

        visited[start] = 1;

        while (!q.empty())
        {
            int u = q.front();

            q.pop();

            for (int v = 0; v < m; v++)
            {
                if (arr[u][v] == 1 && visited[v] == 0)
                {
                    cout << v << " ";
                    q.push(v);
                    visited[v] = 1;
                }
            }
        }
        cout << endl;
    }

    void dfs(int start, int m)
    {

        int visited[10] = {0};
        int u, v;
        stack<int> q;

        cout << start << " ";

        q.push(start);

        visited[start] = 1;

        while (!q.empty())
        {
            int u = q.top();

            q.pop();

            for (int v = 0; v < m; v++)
            {
                if (arr[u][v] == 1 && visited[v] == 0)
                {
                    cout << v << " ";
                    q.push(v);
                    visited[v] = 1;
                }
            }
        }
    }
};

int main()
{

    int m, n;
    cout << "Enter vertices: " << endl;
    cin >> m;

    cout << "Enter edges: " << endl;
    cin >> n;

    graph g;

    int u, v;

    cout << "Enter pair of edges: " << endl;

    for (int i = 0; i < n; i++)
    {
        cin >> u >> v;
        g.add(u, v);
    }

    g.display(m);

    cout << "Bfs: "<< endl;

    g.bfs(0, m);

    cout << "dfs: " << endl;

    g.dfs(0, m);

    return 0;
}