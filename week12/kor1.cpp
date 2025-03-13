#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> A;

int V(int m, int n)
{
    vector<vector<int>> memo(n + 1, vector<int>(n + 1, -1));

    if (m == 0 || n == 0)
    {
        return 0;
    }

    if (memo[m][n] != -1)
    {
        return memo[m][n];
    }

    memo[m][n] = A[m][n] + max(V(m - 1, n), V(m - 1, n - 1));

    return memo[m][n];
}

int main()
{
    int m, n;
    cin >> m >> n;

    A.assign(m + 1, vector<int>(n + 1, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> A[i][j];
        }
    }

    int result = V(m, n);

    cout << result << endl;
}