#include <iostream>
using namespace std;

int result = 0;

void subset1(int x[], int l, int r, int h, int count)
{
    if (count == h)
    {
        result++;
        return;
    }
    if (l == r)
    {
        return;
    }

    if (count > h)
    {
        return;
    }

    x[l] = 0;
    subset1(x, l + 1, r, h, count);
    x[l] = 1;
    subset1(x, l + 1, r, h, count + 1);
}

int main()
{
    int n, h;
    cin >> n >> h;
    int x[n];

    subset1(x, 0, n, h, 0);

    cout << result << endl;
}