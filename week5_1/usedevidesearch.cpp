#include <iostream>
using namespace std;

int partition(int a[], int l, int u)
{
    int mid = (l + u) / 2;
    int pivot = a[mid];
    swap(a[mid], a[u]);
    int i = l;
    for (int j = l; j < u; j++)
    {
        if (a[j] < pivot)
        {
            swap(a[i], a[j]);
            i++;
        }
    }

    swap(a[i], a[u]);
    return i;
}

void quicksort(int a[], int l, int u)
{
    if (l < u)
    {
        int pivot = partition(a, l, u);
        quicksort(a, l, pivot - 1);
        quicksort(a, pivot + 1, u);
    }
}

int find_M(int a[], int l, int u, int m)
{
    if (l == u)
    {
        return l;
    }

    int mid = (l + u) / 2;

    if (a[mid] <= m)
    {
        return find_M(a, mid + 1, u, m);
    }
    else
    {
        return find_M(a, l, mid, m);
    }
}

void search_devide(int a[], int l, int r, int m, int k, int n)
{
    if (k == 0 || (l < 0 && r >= n))
    {
        return;
    }
    if (l >= 0 && r < n)
    {
        if (abs(a[l] - m) <= abs(a[r] - m))
        {
            cout << l << " " << r << endl;
            search_devide(a, l - 1, r, m, k - 1, n);
        }
        else
        {
            cout << l << " " << r << endl;
            search_devide(a, l, r + 1, m, k - 1, n);
        }
    }
    else if (l >= 0)
    {
        cout << l << " -1" << endl;
        search_devide(a, l - 1, r, m, k - 1, n);
    }
    else if (r < n)
    {
        cout << "-1 " << r << endl;
        search_devide(a, l, r + 1, m, k - 1, n);
    }
}

void search(int a[], int m, int k, int n)
{
    quicksort(a, 0, n - 1);

    int index = find_M(a, 0, n - 1, m);
    int left = index - 1;
    int right = index;

    search_devide(a, left, right, m, k, n);
}

int main()
{
    int n, m, k;
    cin >> n;
    int a[n];

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    cin >> m >> k;

    search(a, m, k, n);
}