#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int prim(vector<vector<pair<int, int> > > &graph, int n, int start, int end, int p)
{
    vector<int> maxtemp(n, 0);
    priority_queue<pair<int, int> > q;

    maxtemp[start] = 1000000;
    q.push(make_pair(1000000, start));

    while (!q.empty())
    {
        pair<int, int> top_element = q.top();
        int temp = top_element.first;
        int node = top_element.second;
        q.pop();

        if (node == end)
        {
            return (int)ceil((p + 1) * 1.0 / temp);
        }

        for (int i = 0; i < graph[node].size(); i++)
        {
            int next_node = graph[node][i].first;
            int next_temp = min(temp, graph[node][i].second);

            if (next_temp > maxtemp[next_node])
            {
                maxtemp[next_node] = next_temp;
                q.push(make_pair(next_temp, next_node));
            }
        }
    }
    return -1;

}

int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, int> > > graph(n + 1);

    for (int i = 0; i < m; i++)
    {
        int s, t, l;
        cin >> s >> t >> l;

        graph[s].push_back(make_pair(t, l));
        graph[t].push_back(make_pair(s, l));
    }

    int start, end, p;

    cin >> start >> end >> p;

    int result = prim(graph, n, start, end, p);
    cout << result << endl;
}