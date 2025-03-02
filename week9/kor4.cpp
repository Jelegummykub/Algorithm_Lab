#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

void BFS(vector<vector<int> > &graph , int k , int m , int n){
    vector<bool> visited(n + 1 , false);
    queue<pair<int , int> > q;
    visited[k] = true;
    q.push(make_pair(k , 0));

    while(!q.empty()){
        int u = q.front().first;
        int d = q.front().second;
        q.pop();

        if(d < m){
            for(int i = 0 ; i < graph[u].size() ; i++){
                int v = graph[u][i];
                if(!visited[v]){
                    visited[v] = true;
                    q.push(make_pair(v , d + 1));
                }
            }
        }
    }

    int count = 0;
    for(int i = 1 ; i <= n ; i++){
        if(!visited[i]){
            count++;
        }
    }
    cout << count << endl;
}

int main(){
    int n;
    cin >> n;
    vector<vector<int> > graph(n + 1);

    while(true){
        int p , q;
        cin >> p >> q;
        if(p == 0 && q == 0){
            break;
        }
        graph[p].push_back(q);
    }

    int k = 0 , m = 0;

    cin >> k >> m;

    BFS(graph, k, m, n);
}