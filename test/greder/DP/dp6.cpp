#include <iostream>
#include <vector>
using namespace std;

int f(int n , int m){
    vector<int> memo(n + 1, -1);

    if(n == 0){
        return 1;
    }

    if(memo[n] != -1){
        return memo[n];
    }

    int count = 0;

    for(int i = 1 ; i <= m ; i++){
        if(n - i >= 0){
            count += f(n - i , m);
        }
    }

    return memo[n] = count;
}

int main(){
    int n , m;
    cin >> n >> m;

    int result = f(n,m);
    cout << result << endl;
}