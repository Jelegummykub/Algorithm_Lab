#include <iostream>
#include <vector>
using namespace std;

int f(int n , int k){
    
    vector<vector<int> > memo(n + 1 , vector<int>(n + 1 , -1));

    for(int i = 0 ; i <= n ; i++){
        memo[i][0] = 1;
        memo[i][i] = 1;
    }

    for(int i = 1 ; i <= n ; i++){
        for(int j = 1 ; j < i ; j++){
            memo[i][j] = memo[i - 1][j - 1] + memo[i - 1][j];
        }
    }

    return memo[n][k];
}

int f1(int n , int k){
    vector<vector<int> > memo(n + 1 , vector<int> (n + 1 , -1));

    if(k == 0 || n == k){
        return 1;
    }

    if(memo[n][k] != -1){
        return memo[n][k];
    }

    memo[n][k] = f1(n - 1 , k - 1) + f1(n - 1 , k);

    return memo[n][k];
}

int main(){
    int n , k;

    cin >> n >> k;

    int result = f(n,k);

    int result1 = f1(n,k);

    cout << result << endl;
    cout << result1 << endl;

}