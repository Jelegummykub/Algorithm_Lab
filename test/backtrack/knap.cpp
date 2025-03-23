#include <iostream>
#include <vector>
using namespace std;

int knap(vector<int> &v, vector<int> &wt, int n, int w)
{

    if (n == 0 || w == 0)
    {
        return 0;
    }

    int sum = 0;

    if (wt[n - 1] <= w)
    {
        sum = v[n - 1] + knap(v, wt, n - 1, w - wt[n - 1]);
    }

    return max(sum, knap(v, wt, n - 1, w));
}

int main()
{
    int n, w;
    cin >> n >> w;

    vector<int> v(n);
    vector<int> wt(n);

    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        cin >> wt[i];
    }

    int re = knap(v, wt, n, w);

    cout << re << endl;
}