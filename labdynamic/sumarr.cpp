#include <iostream>
#include <vector>
using namespace std;

double sumarr(vector<int> &arr, int n, int xnew)
{
    if (n == 0)
    {
        return arr[0];
    }

    double prev_sum = sumarr(arr, n - 1, xnew);
    arr[n] += xnew + (prev_sum * n);

    return (double)arr[n] / (n + 1);
}

int main()
{
    int n, xnew;
    cin >> n >> xnew;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    double result = sumarr(arr, n - 1, xnew);
    cout << result << endl;
}

// TODO : Not working
