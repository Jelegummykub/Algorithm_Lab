#include <iostream>
using namespace std;

void intersection(int a[], int b[], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (a[i] == b[j])
            {
                cout << a[i] << " ";
            }
        }
    }

    cout << endl;
}

void Union(int a[], int b[], int n)
{
    int c[2 * n];
    for (int i = 0; i < n; i++)
    {
        c[i] = a[i];
    }

    for (int i = 0; i < n; i++)
    {
        c[i + n] = b[i];
    }

    for (int i = 0; i < 2 * n; i++)
    {
        bool isCheck = false;
        for (int j = 0; j < i; j++)
        {
            if (c[i] == c[j])
            {
                isCheck = true;
                break;
            }
        }

        if (!isCheck)
        {
            cout << c[i] << " ";
        }
    }
}

int main()
{
    int n;
    cin >> n;
    int a[n];
    int b[n];

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
    }

    intersection(a, b, n);
    Union(a, b, n);
}
