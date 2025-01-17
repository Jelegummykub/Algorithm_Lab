#include <iostream>
using namespace std;

int patiton(int a[], int l, int u)
{
    int pivot = a[l];
    int i = l + 1;
    int j = u;

    while (i <= j)
    {
        while (a[i] < pivot)
        {
            i++;
        }

        while (a[j] > pivot)
        {
            j--;
        }

        swap(a[i], a[j]);
    }

    swap(a[i], a[j]);
    swap(a[l], a[j]);
    cout << "FDsdf" << j << endl;
    return j;
}

void quicksort(int a[], int l, int u)
{
    if (l < u)
    {
        int pivot = patiton(a, l, u);

        quicksort(a, l, pivot - 1);
        quicksort(a, pivot + 1, u);
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