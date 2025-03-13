#include <iostream>
#include <vector>
using namespace std;

int fac1(int n, int k)
{

    vector<vector<int> > memo(n + 1, vector<int>(n + 1, -1));

    if (k == 0 || n == k)
    {
        return 1;
    }

    if (memo[n][k] != -1)
    {
        return memo[n][k];
    }

    memo[n][k] = fac1(n - 1, k - 1) + fac1(n - 1, k);
    return memo[n][k];
}

int main()
{
    int n, k;
    cin >> n >> k;

    int result = fac1(n, k);
    cout << result << endl;
}