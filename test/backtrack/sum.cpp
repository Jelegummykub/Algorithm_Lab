#include <iostream>
#include <vector>
using namespace std;

void print(vector<int> &x, vector<int> &a, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (x[i] == 1)
        {
            cout << a[i] << " ";
        }
    }
    cout << endl;
}

void subset(vector<int> &x, vector<int> &a, int n, int k, int l, int sum)
{
    if (sum == k)
    {
        print(x, a, n);
        return;
    }

    if (sum > k || l >= n)
    {
        return;
    }

    x[l] = 1;
    subset(x, a, n, k, l + 1, sum + a[l]);

    x[l] = 0;
    subset(x, a, n, k, l + 1, sum);
}

int main()
{
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    vector<int> x(n, 0);

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    subset(x, a, n, k, 0, 0);

    return 0;
}
