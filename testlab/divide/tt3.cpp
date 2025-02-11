#include <iostream>
#include <vector>
using namespace std;

int sum = 0;

int partition(vector<int> &a, int l, int r)
{
    int m = (l + r) / 2;
    int p = a[m];
    swap(a[m], a[r]);
    int i = l;

    for (int j = l; j < r; j++)
    {
        if (a[j] < p)
        {
            swap(a[i], a[j]);
            i++;
        }
    }

    swap(a[i], a[r]);
    return i;
}

int quickselect(vector<int> &a, int l, int r, int k)
{
    if (a[l] == a[r])
    {
        return a[l];
    }

    int p = partition(a, l, r);
    sum += p;
    if (k == p)
    {
        return a[k];
    }
    else if (k < p)
    {
        return quickselect(a, l, p - 1, k);
    }
    else
    {
        return quickselect(a, p + 1, r, k);
    }
}

int main()
{
    int n, k = 0;
    cin >> n >> k;
    vector<int> a(n);

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    int result = quickselect(a, 0, n - 1, k);
    cout << result << endl;
    cout << sum;
}