#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int dijkstra(vector<vector<pair<int, int> > > &graph, int n, vector<int>& hospital, vector<int> &dist)
{
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > q;
    
    for (int i = 0; i < hospital.size(); i++) {
        dist[hospital[i]] = 0; 
        q.push(make_pair(0, hospital[i])); 
    }
    

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

    return 0;
}

int main()
{
    int f, n;
    cin >> f >> n;

    vector<int> hospital(f);

    for (int i = 0; i < f; i++)
    {
        cin >> hospital[i];
        hospital[i]--;
    }

    vector<vector<pair<int, int> > > graph(n);

    for (int i = 0; i < n; i++)
    {
        int x, y, r;
        cin >> x >> y >> r;
        x--;
        y--;
        graph[x].push_back(make_pair(y, r));
        graph[y].push_back(make_pair(x, r));
    }

    vector<int> dist(n, INT_MAX);

    dijkstra(graph, n, hospital, dist);

    int min_dist = INT_MAX;
    int best_location = -1;
    for (int i = 0; i < n; i++)
    {
        bool has_hospital = false;
        for (int j = 0; j < f; j++) {
            if (hospital[j] == i) {
                has_hospital = true;
                break;
            }
        }

        if (!has_hospital && dist[i] < min_dist)
        {
            min_dist = dist[i];
            best_location = i;
        }
    }

    cout << best_location + 1 << endl;
}