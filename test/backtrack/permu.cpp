#include <iostream>
#include <vector>
using namespace std;

void rightrotate(vector<int> &a, int l, int r)
{
    int temp = a[r];

    for (int i = r; i > l; i--)
    {
        a[i] = a[i - 1];
    }

    a[l] = temp;
}

void leftrotate(vector<int> &a, int l, int r)
{
    int temp = a[l];

    for (int i = l; i < r; i++)
    {
        a[i] = a[i + 1];
    }

    a[r] = temp;
}

void permu(vector<int> &a, int l, int r)
{
    if (l == r)
    {
        for (int i = 0; i < r; i++)
        {
            cout << a[i] << " ";
        }
        cout << endl;
        return;
    }

    for (int i = l; i < r; i++)
    {
        rightrotate(a, l, i);
        permu(a, l + 1, r);
        leftrotate(a, l, i);
    }
}

int main()
{
    int n;
    cin >> n;

    vector<int> a(n);

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    permu(a, 0, n);
}
