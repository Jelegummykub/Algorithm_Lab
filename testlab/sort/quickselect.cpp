#include <iostream>
using namespace std;

int partition(int a[], int l, int r)
{
    int mid = (l + r) / 2;
    int p = a[mid];
    swap(a[mid], a[r]);
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

int quickselect(int a[], int l, int r, int k)
{
    if (a[l] == a[r])
    {
        return a[l];
    }

    int p = partition(a, l, r);

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
    int n;
    int k;
    cin >> n >> k;
    int a[n];

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    int result = quickselect(a, 0, n - 1, k - 1);
    cout << result << endl;
}