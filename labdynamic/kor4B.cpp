#include <iostream>
#include <vector>
using namespace std;

int g(int n){

    if(n == 0){
        return 0;
    }

    if(n == 1 || n == 2){
        return 1;
    }

    return g(n - 1) + g(n - 2) - g(n - 3);
}

int g1(int n){
    vector<int> memo(n + 1 , -1);

    if(n == 0){
        return 0;
    }

    if(n == 1 || n == 2){
        return 1;
    }

    if(memo[n] != -1){
        return memo[n];
    }

    memo[n] = g1(n - 1) + g1(n - 2) - g1(n - 3);
    return memo[n];
}

int g2(int n){
    vector<int> memo(n + 1 , -1);

    memo[0] = 0;
    memo[1] = 1;
    memo[2] = 1;

    for(int i = 3 ; i <= n ; i++){
        memo[i] = memo[i - 1] + memo[i - 2] - memo[i - 3];
    }

    return memo[n];
}

int main(){
    int n;
    cin >> n;

    int result = g(n);

    int result1 = g1(n);

    int result2 = g2(n);

    cout << result << endl;

    cout << result1 << endl;

    cout << result2 << endl;
}