#include <iostream>
using namespace std;

void print(int x[], int l)
{
    for (int i = 1; i <= l; i++)
    {
        cout << x[i] << " ";
    }
    cout << endl;
}

void subset(int x[], int l, int n)
{
    print(x, l);
    int j;
    if (l == 0)
    {
        j = 1;
    }
    else
    {
        j = x[l] + 1;
    }

    for (int i = j; i <= n; i++)
    {
        x[l + 1] = i;
        subset(x, l + 1, n);
    }
}

int main()
{
    int n = 3;
    int x[n + 1];
    subset(x, 0, n);
}