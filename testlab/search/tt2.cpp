#include <iostream>
#include <vector>
using namespace std;

void inter(vector<int> &a, int l, int r, int k)
{
    int p = ((k - a[l]) * (r - l)) / (a[r] - a[l]);

    if (a[p] == k)
    {
        cout << p;
    }
    else if (a[p] < k)
    {
        inter(a, l, p - 1, k);
    }
    else
    {
        inter(a, p + 1, r, k);
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

    inter(a, 0, n - 1, k);
}