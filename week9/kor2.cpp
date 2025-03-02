#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

void BFS(vector<vector<int> > &graph , int s){
    int n = graph.size();
    vector<bool> visited(n , false);
    queue<int> q;

    visited[s] = true;
    q.push(s);

    while(!q.empty()){
        int u = q.front();
        q.pop();

        for(int i = 0 ; i < graph[u].size() ; i++){
            int v = graph[u][i];
            if(!visited[v]){
                visited[v] = true;
                q.push(v);
            }
        }
    }

    vector<int> result;
    for(int i = 1 ; i < n ; i++){
        if(!visited[i]){
            result.push_back(i);
        }
    }

    if(result.empty()){
        cout << 0 << endl;
    }else {
        sort(result.begin() , result.end());
        for(int i = 0 ; i < result.size() ; i++){
            cout << result[i] << " ";
        }
        cout << endl;
    }

}

int main(){
    int n;
    cin >> n;
    vector<vector<int> > graph(n+1);

    for(int i = 0 ; i < n ; i++){
        int p;
        cin >> p;

        while(true){
            int q;
            cin >> q;
            if(q== 0){
                break;
            }
            graph[p].push_back(q);
        }
    }

    int k = 0;
    cin >> k;
    vector<int> start(k);

    for(int i = 0 ; i < k ; i++){
        cin >> start[i];
    }

    for(int i = 0 ; i < start.size() ; i++){
        BFS(graph , start[i]);
    }
}