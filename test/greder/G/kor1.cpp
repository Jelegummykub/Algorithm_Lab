#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int BFS(vector<vector<int> > &graph, int s, int d)
{
    int n = graph.size();

    vector<int> visited(n, -1);
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

    return visited[d];
}

int main()
{
    int n;
    cin >> n;

    vector<vector<int> > graph(n + 1);

    for (int i = 0; i < n; i++)
    {
        int p;
        cin >> p;

        while (true)
        {
            int q;
            cin >> q;

            if (q == 0)
            {
                break;
            }

            graph[p].push_back(q);
            graph[q].push_back(p);
        }
    }

    int s, d;
    cin >> s >> d;

    int resulr = BFS(graph, s, d);

    cout << resulr << endl;
}