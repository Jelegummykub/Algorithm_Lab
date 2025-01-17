#include <iostream>
#include <cmath>
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

        if (i <= j)
        {
            swap(a[i], a[j]);
        }
    }

    swap(a[l], a[j]);
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

void search(int arr[], int m, int k, int n)
{
    quicksort(arr, 0, n - 1);

    int temp = 0;
    while (temp < n && arr[temp] < m)
    {
        temp++;
    }
    // cout << "fdfs" << temp << endl;

    int left = temp - 1;
    int right = temp;

    while (right - left <= k)
    {
        cout << left << " " << right << endl;

        if (abs(arr[left] - m) > abs(arr[right] - m))
        {
            right++;
        }
        else if (abs(arr[left] - m) < abs(arr[right] - m))
        {
            left--;
        }
    }
}

int main()
{
    int n;
    int m = 0;
    int k = 0;
    cin >> n;

    int a[n];

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    cin >> m;
    cin >> k;

    search(a, m, k, n);
}
