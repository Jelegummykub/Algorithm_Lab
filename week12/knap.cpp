#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int knap(vector<int> &v , vector<int> &w , int n , int wt){

    vector<vector<int> > memo(n + 1, vector<int>(wt + 1, -1));

    if(n == 0 || wt == 0){
        return 0;
    }

    if(memo[n][wt] != -1){
        return memo[n][wt];
    }

    if(w[n-1] > wt){
        memo[n][wt] = knap(v, w, n-1, wt);
        return memo[n][wt];
    }

    memo[n][wt] = max(v[n-1] + knap(v, w, n-1, wt - w[n-1]), knap(v, w, n-1, wt));
    return memo[n][wt];
}

int knap1(vector<int> &v , vector<int> &w , int n , int wt){
    
    vector<vector<int> > memo(n + 1, vector<int>(wt + 1, 0));

    for(int i = 1 ; i <= n ; i++){
        for(int j = 1 ; j <= wt ; j++){
            if(w[i-1] > j){
                memo[i][j] = memo[i-1][j];
            }else {
                memo[i][j] = max(v[i-1] + memo[i-1][j - w[i-1]], memo[i-1][j]);
            }
        }
    }

    return memo[n][wt];
} 

int main(){
    int n;
    cin >> n;


    vector<int> v(n);
    vector<int> w(n);

    for(int i = 0 ; i < n ; i++){
        cin >> v[i];
    }

    for(int i = 0 ; i < n ; i++){
        cin >> w[i];
    }

    int wt;
    cin >> wt;

    int result = knap(v, w, n, wt);
    int result1 = knap1(v, w, n, wt);


    cout << result << endl;
    cout << result1 << endl;


}