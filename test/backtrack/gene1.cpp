#include <iostream>
#include <vector>
using namespace std;

void print(vector<int> &x, int l)
{
    for (int i = 1; i <= l; i++)
    {
        cout << x[i] << " ";
    }
    cout << endl;
}

void subset2(vector<int> &a, int l, int r)
{
    print(a, l);

    int j;

    if (l == 0)
    {
        j = 1;
    }
    else
    {
        j = a[l] + 1;
    }

    for (int i = j; i <= r; i++)
    {
        a[l + 1] = i;
        subset2(a, l + 1, r);
    }
}

int main()
{
    int n;
    cin >> n;

    vector<int> a(n + 1);

    subset2(a, 0, n);
}