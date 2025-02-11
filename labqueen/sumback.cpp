#include <iostream>
#include <vector>
using namespace std;

void print(vector<int> &x, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (x[i] == 1)
        {
            cout << i + 1 << " ";
        }
    }
    cout << endl;
}

void subset1(vector<int> &x, vector<int> &a, int k, int l, int n, int sum)
{
    if (sum == k)
    {
        print(x, n);
        return;
    }

    if (l >= n || sum > k)
    {
        return;
    }

    x[l] = 1;
    subset1(x, a, k, l + 1, n, sum + a[l]);

    x[l] = 0;
    subset1(x, a, k, l + 1, n, sum);
}

int main()
{
    int n, k;
    cin >> n >> k;

    vector<int> a(n, 0);
    vector<int> x(n, 0);

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    subset1(x, a, k, 0, n, 0);
}
