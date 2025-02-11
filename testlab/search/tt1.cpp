#include <iostream>
#include <vector>
using namespace std;

void binary(vector<int> &a, int l, int r, int k)
{
    int m = (l + r) / 2;

    if (a[m] == k)
    {
        cout << m;
    }
    else if (a[m] < k)
    {
        binary(a, l, m - 1, k);
    }
    else
    {
        binary(a, m + 1, r, k);
    }
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

    binary(a, 0, n - 1, k);
}