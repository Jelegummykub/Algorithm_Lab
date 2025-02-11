#include <iostream>
#include <vector>
using namespace std;

void counting(vector<int> &a, int n)
{
    int max = a[0];
    for (int i = 1; i < n; i++)
    {
        if (a[i] > max)
        {
            max = a[i];
        }
    }

    vector<int> count(max + 1, 0);
    vector<int> B(n);

    for (int i = 0; i < n; i++)
    {
        count[a[i]]++;
    }

    for (int i = max; i >= 0; i--)
    {
        count[i] += count[i + 1];
    }

    for (int i = 0; i < n; i++)
    {
        B[count[a[i]] - 1] = a[i];
        count[a[i]]--;
    }

    // for (int i = 0; i < n; i++)
    // {
    //     cout << B[i] << " ";
    // }
}

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    counting(a, n);

    cout << a[k - 1];
}