#include <iostream>
using namespace std;

int findmax(int a[], int l, int r)
{
    if (l == r)
    {
        return l;
    }

    int mid = (l + r) / 2;

    if (a[mid] != a[mid - 1] && a[mid] != a[mid + 1])
    {
        return mid;
    }
    else if (a[mid] != a[mid - 1])
    {
        return findmax(a, l, mid - 1);
    }
    else
    {
        return findmax(a, mid + 1, r);
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

    int index = findmax(a, 0, n - 1);

    int result = a[index];

    cout << result + 1 << endl;
}