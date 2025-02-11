#include <iostream>
using namespace std;

int maxc = 0;

void subset(int x[], int n, int i, int sum)
{
    if (i >= n)
    {
        maxc = max(maxc, sum);
        return;
    }

    subset(x, n, i + 2, sum + x[i]);
    subset(x, n, i + 1, sum);
}

int main()
{
    int n;
    cin >> n;
    int x[n];

    for (int i = 0; i < n; i++)
    {
        cin >> x[i];
    }

    subset(x, n, 0, 0);
    cout << maxc << endl;
}
