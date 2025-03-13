#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int prim(vector<vector<pair<int, int> > > &graph, int n, int s)
{
    vector<bool> visited(n, false);

    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > q;

    q.push(make_pair(0, s));

    int sum = 0;

    while (!q.empty())
    {
        int w = q.top().first;
        int u = q.top().second;
        q.pop();

        if (visited[u])
        {
            continue;
        }

        visited[u] = true;
        sum += w;

        for (int i = 0; i < graph[u].size(); i++)
        {
            int v = graph[u][i].first;
            int w = graph[u][i].second;

            if (!visited[v])
            {
                q.push(make_pair(w, v));
            }
        }
    }

    return sum;
}

int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, int> > > graph(n + 1);

    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;

        graph[u].push_back(make_pair(v, w));
        graph[v].push_back(make_pair(u, w));
    }

    int s;
    cin >> s;

    int result = prim(graph, n, s);
    cout << result << endl;
}