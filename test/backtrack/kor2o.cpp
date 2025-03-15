#include <iostream>

using namespace std;

vector<vector<int> > memo(101 , vector<int>(101 , -1));
int fac2(int n , int k){

    if(k == 0 || n == k){
        return 1;
    }

    if(memo[n][k] != -1){
        return memo[n][k];
    }

    memo[n][k] = fac2(n - 1, k - 1) + fac2(n - 1, k);
    return memo[n][k];
}

int main(){
    int n , k;
    cin >> n >> k;

    int re = fac2(n,k);

    cout << re  << endl;
}