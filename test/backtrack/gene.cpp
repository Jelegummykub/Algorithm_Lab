#include <iostream>
#include <vector>
using namespace std;

void print(vector<int> &x, int n)
{
    for (int i = 1; i <= n; i++)
    {
        cout << x[i] << " ";
    }
    cout << endl;
}

void subset1(vector<int> &a, int l, int r)
{
    if (l == r)
    {
        print(a, r);
        return;
    }
    else
    {
        a[l + 1] = 0;
        subset1(a, l + 1, r);
        a[l + 1] = 1;
        subset1(a, l + 1, r);
    }
}

int main()
{
    int n;
    cin >> n;

    vector<int> a(n + 1);

    subset1(a, 0, n);
}