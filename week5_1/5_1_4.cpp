#include <iostream>
using namespace std;

int par(int arr[], int l, int r)
{
    int i = l, j = r, pivot = arr[l];
    while (i < j)
    {
        while (arr[i] < pivot)
        {
            i++;
        }
        while (arr[j] > pivot)
        {
            j--;
        }
        swap(arr[i], arr[j]);
    }
    return j;
}

void sort(int arr[], int l, int r)
{
    if (l < r)
    {
        int p = par(arr, l, r);

        sort(arr, l, p - 1);
        sort(arr, p + 1, r);
    }
}

int bisearch(int arr[], int l, int r, int find)
{
    int closest = -999;

    while (l <= r)
    {
        int m = l + (r - l) / 2;
        if (arr[m] == find)
        {
            return m;
        }

        if (closest == -999 || abs(arr[m] - find) < abs(arr[closest] - find))
        {
            closest = m;
        }

        if (find > arr[m])
        {
            l = m + 1;
        }
        else
        {
            r = m - 1;
        }
    }

    return closest;
}

int main()
{
    int n, k, M;
    cin >> n;
    int arr[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cin >> M >> k;
    sort(arr, 0, n - 1);

    int where;
    if (M < arr[0])
    {
        where = 0;
    }
    else if (M > arr[n - 1])
    {
        where = n - 1;
    }
    else
    {
        where = bisearch(arr, 0, n - 1, M);
    }

    int l = where - 1, r = where;
    while (r - l <= k)
    {
        cout << l << " " << r << endl;
        if (abs(arr[l] - M) > abs(arr[r] - M))
        {
            r++;
        }
        else
        {
            l--;
        }
    }
}