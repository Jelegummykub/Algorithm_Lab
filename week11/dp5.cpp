#include <iostream>
#include <vector>
using namespace std;

int f(int n, vector<int> &memo) {
    if (n == 1 || n == 2) {
        return 1;
    }
    if (memo[n] != -1) {
        return memo[n];
    }
    memo[n] = 3 * f(n - 2, memo) + 2 * f(n - 1, memo);
    return memo[n];
}

int main() {
    int n;
    cin >> n;

    vector<int> memo(n + 1, -1);
    cout << f(n, memo) << endl;
}
