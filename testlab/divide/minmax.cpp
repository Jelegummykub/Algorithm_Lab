#include <iostream>
using namespace std;

int partition(int a[], int l, int r)
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

void quicksort(int a[], int l, int r)
{
    if (l < r)
    {
        int p = partition(a, l, r);
        quicksort(a, l, p - 1);
        quicksort(a, p + 1, r);
    }
}

int main()
{
    int n;
    cin >> n;
    int a[n];
    int max = 0;

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    quicksort(a, 0, n - 1);

    for (int i = 0; i < n; i++)
    {
        if (max < a[i])
        {
            max = a[i];
        }
    }
    int min = max;

    for (int i = 0; i < n; i++)
    {
        if (min > a[i])
        {
            min = a[i];
        }
    }
    cout << max << endl;
    cout << min;
}