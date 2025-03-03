#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> BFS(vector<vector<int> > &graph, int s, int n)
{
    vector<int> visited(n + 1, -1);
    queue<int> q;
    visited[s] = 0;
    q.push(s);

    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        for (int i = 0; i < graph[u].size(); i++)
        {
            int v = graph[u][i];
            if (visited[v] == -1)
            {
                visited[v] = visited[u] + 1;
                q.push(v);
            }
        }
    }

    return visited;
}

int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<int> > graph(n + 1);

    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    int best = -1;
    int max = n;

    for (int i = 1; i <= n; i++)
    {
        vector<int> find = BFS(graph, i, n);

        int tempmax = 0;

        for (int j = 1; j <= n; j++)
        {
            if (find[j] > tempmax)
            {
                tempmax = find[j];
            }
        }

        if (tempmax < max)
        {
            max = tempmax;
            best = i;
        }
    }

    cout << best << endl;
}