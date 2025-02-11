#include <iostream>
using namespace std;

int interpolation(vector<int> &a, int l, int r, int k)
{
    int p = l + (((k - a[l]) * (r - l)) / (a[r] - a[l]));

    // cout << p << " ";
    if (a[p] == k)
    {
        return p;
    }
    else if (a[p] < k)
    {
        interpolation(a, p + 1, r, k);
    }
    else
    {
        interpolation(a, l, p - 1, k);
    }
    return 0;
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

    int result = interpolation(a, 0, n - 1, k);
    cout << result << endl;
}