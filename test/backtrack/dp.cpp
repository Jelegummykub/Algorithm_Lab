#include <iostream>
#include <vector>

using namespace std;

vector<long long> memo_f(1000, -1);
vector<long long> memo_g(1000, -1);
vector<long long> memo_x(1000, -1);

long long g(int n);
long long x(int n);

long long f(int n)
{
    if (n <= 0)
    {
        return 1;
    }

    if (memo_f[n] != -1)
    {
        return memo_f[n];
    }

    memo_f[n] = f(n - 1) + g(n - 2) + x(n - 3);
    return memo_f[n];
}

long long g(int n)
{
    if (n <= 0)
    {
        return 1;
    }

    if (memo_g[n] != -1)
    {
        return memo_g[n];
    }

    memo_g[n] = g(n - 1) + g(n - 2);
    return memo_g[n];
}

long long x(int n)
{
    if (n <= 0)
    {
        return 1;
    }

    if (memo_x[n] != -1)
    {
        return memo_x[n];
    }

    memo_x[n] = x(n - 1) + x(n - 2);
    return memo_x[n];
}

int main()
{
    int n;
    cin >> n;

    cout << f(n) << endl;
}
