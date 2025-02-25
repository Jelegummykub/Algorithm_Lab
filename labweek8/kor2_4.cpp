#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void checkArrays(int n, vector<int> &a, vector<int> &b, int k)
{
    sort(a.begin(), a.end());

    sort(b.begin(), b.end(), greater<int>());

    for (int i = 0; i < n; i++)
    {
        if (a[i] + b[i] < k)
        {
            cout << "No\n";
            return;
        }
    }
    cout << "\n";
    cout << "Yes\n";
}

int main()
{
    int m;
    int n;
    int k;
    cin >> m;

    for (int i = 0; i < m; i++)
    {
        cin >> n;

        vector<int> a(n);
        vector<int> b(n);

        for (int j = 0; j < n; j++)
        {
            cin >> a[j];
        }
        for (int j = 0; j < n; j++)
        {
            cin >> b[j];
        }
        cin >> k;

        checkArrays(n, a, b, k);
    }
}