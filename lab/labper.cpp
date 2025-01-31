#include <iostream>
using namespace std;

int count = 0;

void permute(int x[], int start, int end)
{
    if (start == end)
    {
        for (int i = 1; i <= end; i++)
        {
            if ((x[i] == 1 && x[i + 1] == 2) || (x[i] == 2 && x[i + 1] == 1))
            {
                ::count++;
            }
        }
    }

    for (int i = start; i <= end; i++)
    {
        swap(x[start], x[i]);
        permute(x, start + 1, end);
        swap(x[start], x[i]);
    }
}

int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 1; i <= n; i++)
    {
        a[i] = i;
    }

    permute(a, 1, n);

    cout << ::count << endl;
}