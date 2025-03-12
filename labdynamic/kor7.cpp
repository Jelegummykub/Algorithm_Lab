#include <iostream>
#include <vector>
using namespace std;

int t(int m, int n)
{

    if (m == 0 || n == 0)
    {
        return 0;
    }

    if (m == 1 || n == 1)
    {
        return 1;
    }

    return t(m - 1, n) + t(m, n - 1);
}

int t1(int m, int n)
{
    vector<vector<int> > memo(n + 1, vector<int>(n + 1, -1));

    if (m == 0 || n == 0)
    {
        return 0;
    }

    if (m == 1 || n == 1)
    {
        return 1;
    }

    if (memo[m][n] != -1)
    {
        return memo[m][n];
    }

    memo[m][n] = t1(m - 1, n) + t1(m, n - 1);
    return memo[m][n];
}

int t2(int m, int n)
{
    vector<vector<int> > memo(m + 1, vector<int>(n + 1, 0));

    for (int i = 1; i <= m; i++)
    {
        memo[i][1] = 1;
    }

    for (int j = 1; j <= n; j++)
    {
        memo[1][j] = 1;
    }

    for (int i = 2; i <= m; i++)
    {
        for (int j = 2; j <= n; j++)
        {
            memo[i][j] = memo[i - 1][j] + memo[i][j - 1];
        }
    }

    return memo[m][n];
}

int main()
{
    int m, n;
    cin >> m >> n;

    int result = t(m, n);

    int result1 = t1(m, n);

    int result2 = t2(m, n);

    cout << result << endl;

    cout << result1 << endl;

    cout << result2 << endl;
}
