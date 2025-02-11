#include <iostream>
using namespace std;

int maxv = 0;
int maxw = 0;

void print(int x[], int n, int v[], int w[], int sumvt, int sumwt)
{
    if (sumwt <= 13 && sumvt > maxv)
    {
        maxv = sumvt;
        maxw = sumwt;
    }
}

void subset(int x[], int l, int r, int v[], int w[], int sumvt, int sumwt)
{
    if (l == r)
    {
        print(x, r, v, w, sumvt, sumwt);
        return;
    }

    if (sumwt > 13)
    {
        return;
    }

    x[l] = 0;
    subset(x, l + 1, r, v, w, sumvt, sumwt);
    x[l] = 1;
    subset(x, l + 1, r, v, w, sumvt + v[l], sumwt + w[l]);
}

int main()
{
    int n;
    cin >> n;
    int v[n];
    int w[n];
    int x[n];

    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    for (int i = 0; i < n; i++)
    {
        cin >> w[i];
    }
    subset(x, 0, n, v, w, 0, 0);

    cout << maxv << " " << maxw << endl;
}