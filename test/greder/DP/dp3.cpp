#include <iostream>
#include <vector>

using namespace std;

int f(int n , int k){
    vector<vector<int> > memo(n + 1, vector<int> (n + 1 , -1));

    if(k == 0 || k == 1 || n == k){
        return 1;
    }

    if(memo[n][k] != -1){
        return memo[n][k];
    }

    memo[n][k] = f(n - 1, k) + f(n - 1 , k - 2);

    return memo[n][k];
}

int main(){
    int n , k;

    cin >> n >> k;

    int result = f(n,k);
    cout << result << endl;
}