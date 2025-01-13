#include <iostream>
using namespace std;

int findfrequency(int l, int r, int arr[], int target)
{
    int mid = (l + r) / 2;
    if (arr[l] == target)
    {
        int count = 1;

        int l = mid - 1;
        int r = mid + 1;

        while (arr[l] == target)
        {
            count++;
            l--;
        }

        while (arr[r] == target)
        {
            count++;
            r++;
        }
        return count;
    }
    else if (arr[mid] == target)
    {
        return findfrequency(l + mid, r, arr, target);
    }
    else
    {
        return findfrequency(0, mid - l, arr, target);
    }
}

int main()
{

    int n;
    int target;
    cin >> n;
    cin >> target;
    int arr[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int result = findfrequency(0, n - 1, arr, target);

    cout << result << endl;
}