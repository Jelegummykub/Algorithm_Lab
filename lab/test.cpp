#include <iostream>
using namespace std;

int max[2] = {0, 0};

void print(int x[], int n, int v[], int w[])
{
    int vt = 0;
    int wt = 0;
    for (int i = 1; i <= n; i++)
    {
        vt += x[i] * v[i - 1];
        wt += x[i] * w[i - 1];
    }

    if (wt <= 13 && ::max[0] <= vt)
    {
        ::max[0] = vt;
        ::max[1] = wt;
    }
}

void subset(int x[], int l, int r, int v[], int w[])
{
    if (l == r)
    {
        print(x, r, v, w);
    }
    else
    {
        x[l + 1] = 0;
        subset(x, l + 1, r, v, w);
        x[l + 1] = 1;
        subset(x, l + 1, r, v, w);
    }
}

int main()
{
    int n;
    cin >> n;
    int v[n];
    int w[n];
    int x[n + 1];

    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    for (int i = 0; i < n; i++)
    {
        cin >> w[i];
    }
    subset(x, 0, n, v, w);

    cout << ::max[1] << " " << ::max[0] << endl;
}