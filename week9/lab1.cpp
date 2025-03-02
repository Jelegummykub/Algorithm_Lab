#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void addEdge(vector<vector<int> > &graph, int a, int b)
{
    graph[a][b] = 1;
    graph[b][a] = 1;
}

void display(vector<vector<int> > &graph)
{
    for (int i = 0; i < graph.size(); i++)
    {
        for (int j = 0; j < graph[i].size(); j++)
        {
            cout << graph[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    int v = 0;
    int e = 0;
    cin >> v >> e;

    vector<vector<int> > graph(v, vector<int>(v, 0));

    for (int i = 0; i < e; i++)
    {
        int a, b;
        cin >> a >> b;
        addEdge(graph, a, b);
    }

    display(graph);
}