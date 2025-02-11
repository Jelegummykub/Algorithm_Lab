#include <iostream>
using namespace std;

void permute(int x[], int start, int end, int &count)
{
    if (start == end)
    {
        bool cal = true;
        for (int i = 1; i <= end; i++)
        {
            if (i % 2 == 0)
            {
                cal = false;
            }
            if (cal)
            {
                count++;
            }
        }
    }

    for (int i = start; i <= end; i++)
    {
        swap(x[start], x[i]);
        permute(x, start + 1, end, count);
        swap(x[start], x[i]);
    }
}

int main()
{
    int n, count = 0;
    cin >> n;
    int x[n + 1];

    for (int i = 1; i <= n; i++)
    {
        x[i] = i;
    }
    permute(x, 1, n, count);

    cout << count << endl;
}
