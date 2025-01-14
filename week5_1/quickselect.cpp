#include <iostream>
using namespace std;

int partition(int arr[], int l, int r)
{
    int mid = (l + r) / 2;
    int pivot = arr[mid];
    swap(arr[mid], arr[r]);
    int i = l;

    for (int j = l; j < r; j++)
    {
        if (arr[j] < pivot)
        {
            swap(arr[i], arr[j]);
            i++;
        }
        // cout << "Step (j=" << j << "): ";
        // for (int k = l; k <= r; k++)
        // {
        //     cout << arr[k] << " ";
        // }
        // cout << endl;
    }

    swap(arr[i], arr[r]);
    // cout << "Final partition step: ";
    // for (int k = l; k <= r; k++)
    // {
    //     cout << arr[k] << " ";
    // }
    // cout << endl;
    // cout << "dsa" << i << endl;

    return i;
}

int quickselect(int arr[], int low, int high, int k)
{
    if (low == high)
    {
        return arr[low];
    }

    int pivot = partition(arr, low, high);

    if (k == pivot)
    {
        return arr[k];
    }
    else if (k < pivot)
    {
        return quickselect(arr, low, pivot - 1, k);
    }
    else
    {
        return quickselect(arr, pivot + 1, high, k);
    }
}

int main()
{
    int arr[] = {1, 5, 10, 4, 8, 2, 6, 9, 20};
    int k = 4;
    int n = sizeof(arr) / sizeof(arr[0]);
    // cout << n;

    int result = quickselect(arr, 0, n - 1, k);
    cout << result << endl;
}