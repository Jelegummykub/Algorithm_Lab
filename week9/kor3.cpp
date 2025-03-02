#include <iostream>
#include <vector>
using namespace std;

bool DFS(vector<vector<int> > &graph , int s , int parent , vector<bool> &visited){
    visited[s] = true;

    for(int i = 0 ; i < graph[s].size() ; i++){
        int v = graph[s][i];
        if(!visited[v]){
            if(DFS(graph , v , s , visited)){
                return true;
            }
        }else if(v != parent){
            return true;
        }
    }

    return false;
}

int cycles(vector<vector<int> > &graph , int n){
    vector<bool> visited(n + 1 , false);
    int count = 0;

    for(int i = 0 ; i < n ; i++){
        if(!visited[i]){
            if(DFS(graph , i , -1 , visited)){
                count++;
            }
        }
    }

    return count;

}

int main(){
    int n;
    cin >> n;

    vector<vector<int> > graph(n + 1);

    for(int i = 0 ; i < n ; i++){
        int p;
        cin >> p;

        while(true){
            int q;
            cin >> q;

            if(q == 0){
                break;
            }

            graph[p].push_back(q);
            graph[q].push_back(p);
        }
    }

    int result = cycles(graph , n);
    cout << result << endl;
}