#include <iostream>
#include <vector>
#include <queue>
#include <iomanip>
using namespace std;

void dijkstra(vector<vector<pair<int ,int> > > &graph , int n , int i , vector<int> &dist){
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > q;
    dist[i] = 0;
    q.push(make_pair(0, i));

    while(!q.empty()){
        int u = q.top().second;
        int d = q.top().first;
        q.pop();

        if(dist[u] < d){
            continue;
        }

        for(int j = 0 ; j < graph[u].size() ; j++){
            int v = graph[u][j].first;
            int w = graph[u][j].second;

            if(dist[u] + w < dist[v]){
                dist[v] = dist[u] + w;
                q.push(make_pair(dist[v], v));
            }
        }
    }
}

int main(){
    int n = 100;
    vector<vector<pair<int, int> > > graph(n);
    
    while(true){
        int a , b;
        cin >> a >> b;

        if(a == 0 && b == 0){
            break;
        }

        graph[a].push_back(make_pair(b, 1));
    }

    int sum = 0;
    int count = 0;

    for(int i = 0 ; i < n ; i++){
        vector<int> dist(n+1, INT_MAX);
        dijkstra(graph, n, i, dist);
        for(int j = 0 ; j < n ; j++){
            if(i != j && dist[j] != INT_MAX){
                sum += dist[j];
                count++;
            }
        }
    }

    double avg = (double) sum / count;
    cout << fixed << setprecision(3) << avg << endl;
}