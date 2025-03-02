#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


void display(vector<vector<int> > &graph , int n)
{
    for (int i = 0; i < n; i++)
    {
        if(graph[i].empty()){
            continue;
        }
        
        cout << i << " : ";
        for (int j = 0; j < graph[i].size(); j++)
        {
            cout << graph[i][j] << " ";
        }
        cout << endl;
    }
}

int main(){
    int v;
    int e;

    cin >> v >> e;

    vector<vector<int> > graph(v);

    for(int i = 0 ; i < e ; i++){
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
    }

    display(graph , e);
}