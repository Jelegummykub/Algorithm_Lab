#include <iostream>
using namespace std;

void nqueen(int k, int n, int x[])
{
    if (k == n)
    {
        int flag = 0;
        for (int j = 1; j < k; j++)
        {
            for (int p = 0; p < j; p++)
            {
                if (abs(p - j) == abs(x[p] - x[j]) || (x[j] == x[p]))
                {
                    flag = 1;
                }
            }
        }
        if (flag == 0)
        {
            for (int i = 0; i < k; i++)
            {
                cout << x[i] << " ";
            }
            cout << endl;
        }
    }
    else
    {
        for (int row = 0; row < n; row++)
        {
            bool check = true;
            for (int j = 0; j < k; j++)
            {
                // cout << j << " ";
                // cout << endl;
                if (x[j] == row || abs(j - k) == abs(x[j] - row))
                {
                    check = false;
                    break;
                }
            }
            if (check)
            {
                x[k] = row;
                nqueen(k + 1, n, x);
            }
        }
    }
}

int main()
{
    int n;
    cin >> n;
    int x[n];

    nqueen(0, n, x);
}