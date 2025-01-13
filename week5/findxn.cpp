#include <iostream>
using namespace std;

// int findmax(int l, int r, int arr[])
// {
//     if (l == r)
//     {
//         return arr[l];
//     }

//     int mid = (l + r) / 2;

//     return findmax(l, mid, arr) * findmax(mid + 1, r, arr);
// }

int findxn(int x, int n)
{

    int mid = 0;

    if (n == 0)
    {
        return 1;
    }

    if (n % 2 == 0)
    {
        mid = findxn(x, n / 2);
        return mid * mid;
    }
    else
    {
        mid = findxn(x, n / 2);
        return x * mid * mid;
    }
}

int main()
{
    int n;
    int x;

    cin >> n;
    cin >> x;

    // int arr[n];

    // for (int i = 0; i < n; i++)
    // {
    //     arr[i] = x;
    // }

    // int result = findmax(0, n - 1, arr);
    int result = findxn(x, n);

    cout << result << endl;
}