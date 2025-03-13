#include <iostream>
#include <vector>
using namespace std;

vector<int> A;
vector<vector<int>> memo;

int V(int i, int j)
{
    if (i == 0 || j == 0)
    {
        return 0;
    }

    if (i == j)
    {
        return A[i];
    }

    if (memo[i][j] != -1)
    {
        return memo[i][j];
    }

    memo[i][j] = max(V(i + 1, j), V(i, j - 1)) + A[j];

    return memo[i][j];
}

int main()
{
    int n;
    cin >> n;
    A.resize(n + 1);

    memo.assign(n + 1, vector<int>(n + 1, -1));

    for (int i = 1; i <= n; i++)
    {
        cin >> A[i];
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = i; j <= n; j++)
        {
            int result = V(i, j);
            cout << result << " ";
        }
    }
}