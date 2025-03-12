#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int dijkstra(vector<vector<pair<int, int> > > &graph, int n, int s, int t)
{
    vector<int> dist(n, INT_MAX);
    dist[s] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > q;
    q.push(make_pair(0, s));

    while (!q.empty())
    {
        int u = q.top().second;
        int d = q.top().first;

        q.pop();

        if (dist[u] < d)
        {
            continue;
        }

        for (int i = 0; i < graph[u].size(); i++)
        {
            int v = graph[u][i].first;
            int w = graph[u][i].second;

            if (dist[u] + w < dist[v])
            {
                dist[v] = dist[u] + w;
                q.push(make_pair(dist[v], v));
            }
        }
    }

    return dist[t] == INT_MAX ? -1 : dist[t];
}

int main()
{
    int c;
    cin >> c;

    for (int i = 0; i < c; i++)
    {
        int n, m, s, t;
        cin >> n >> m >> s >> t;

        vector<vector<pair<int, int> > > graph(n);

        for (int j = 0; j < m; j++)
        {
            int a, b, w;
            cin >> a >> b >> w;

            graph[a].push_back(make_pair(b, w));
            graph[b].push_back(make_pair(a, w));
        }

        int result = dijkstra(graph, n, s, t);
        cout << result << endl;
    }
}