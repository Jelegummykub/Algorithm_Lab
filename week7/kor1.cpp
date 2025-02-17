#include <iostream>
#include <vector>
using namespace std;

void permute(vector<string> &x, int l, int r)
{
    if (l == r)
    {
        for (int i = 0; i <= r; i++)
        {
            cout << x[i] << " ";
        }
        cout << endl;
        return;
    }
    for (int i = l; i <= r; i++)
    {
        swap(x[l], x[i]);
        permute(x, l + 1, r);
        swap(x[l], x[i]);
    }
}

int main()
{
    int n;
    cin >> n;
    vector<string> x(n);

    for (int i = 0; i < n; i++)
    {
        cin >> x[i];
    }

    permute(x, 0, n - 1);
}
