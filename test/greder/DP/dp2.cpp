#include <iostream>
#include <vector>
using namespace std;

bool fsum(vector<int> &a, int n, int k)
{
    vector<vector<int>> memo(n + 1, vector<int>(k + 1, -1));

    if (k == 0)
    {
        return 1;
    }

    if (n <= 0)
    {
        return 0;
    }

    if (memo[n][k] != -1)
    {
        return memo[n][k];
    }

    if (a[n - 1] > k)
    {
        return memo[n][k] = fsum(a, n - 1, k);
    }

    return memo[n][k] = fsum(a, n - 1, k) || fsum(a, n - 1, k - a[n - 1]);
}

int main()
{
    int n, k;

    cin >> n >> k;

    vector<int> a(n);

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    if (fsum(a, n, k))
    {
        cout << "T" << endl;
    }
    else
    {
        cout << "F" << endl;
    }
}