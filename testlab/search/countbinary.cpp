#include <iostream>
#include <vector>
using namespace std;

void binarysearch(vector<int> &a, int l, int r, int k, int &f, int &ll)
{
    if (l > r)
    {
        return;
    }

    int m = (l + r) / 2;

    if (a[m] == k)
    {
        if (f == -1 || m < f)
        {
            f = m;
        }
        if (m > ll)
        {
            ll = m;
        }
        binarysearch(a, l, m - 1, k, f, ll);
        binarysearch(a, m + 1, r, k, f, ll);
    }
    else if (a[m] < k)
    {
        binarysearch(a, m + 1, r, k, f, ll);
    }
    else
    {
        binarysearch(a, l, m - 1, k, f, ll);
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
    int f = -1;
    int ll = -1;
    binarysearch(a, 0, n - 1, k, f, ll);

    cout << ll - f + 1 << endl;
}