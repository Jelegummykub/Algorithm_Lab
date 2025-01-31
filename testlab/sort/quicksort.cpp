#include <iostream>
using namespace std;

int partition(int a[], int l, int r)
{
    int p = a[l];
    int i = l + 1;
    int j = r;

    while (i <= j)
    {
        while (a[i] < p)
        {
            i++;
        }

        while (a[j] > p)
        {
            j--;
        }
        swap(a[i], a[j]);
    }

    swap(a[i], a[j]);
    swap(a[l], a[j]);
    return j;
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

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    quicksort(a, 0, n - 1);
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
}