#include <iostream>
#include <vector>
using namespace std;

int f(int n){
    vector<int> memo(n + 1 , -1);

    memo[0] = 0;
    memo[1] = 1;
    memo[2] = 1;

    for(int i = 3 ; i <= n ;i++){
        memo[i] = memo[i-1] + memo[i-2] - memo[i-3];
    }

    return memo[n];

}

int main(){
    int n;
    cin >> n;

    int result = f(n);
    cout << result << endl;
}