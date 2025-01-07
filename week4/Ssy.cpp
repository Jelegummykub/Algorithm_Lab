#include <iostream>
using namespace std;

void process(int a[], int n)
{
    for (int i = 1; i < n; i++)
    {
        for (int j = i; j > 0 && a[j] < a[j - 1]; j--)
        {
            swap(a[j], a[j - 1]);
        }
    }

    int keep[1000];
    int count = 0;
    int max = -1;

    for (int i = 0; i < n; i++)
    {
        int C[10];
        int size = 0;
        while (a[i] > 0)
        {
            C[size++] = a[i] % 10;
            a[i] /= 10;
        }

        for (int j = size - 1; j >= 0; j--)
        {
            if (C[j] > max)
            {
                max = C[j];
            }
            keep[count++] = C[j];
        }
    }

    int array[10] = {0};
    int temp = -999;
    int countnum = 1;

    for (int i = 0; i < count; i++)
    {
        cout << keep[i];
        if (temp != keep[i])
        {
            temp = keep[i];
            if (array[keep[i]] != countnum)
            {
                array[keep[i]] = 1;
            }
        }
        else
        {
            array[keep[i]]++;
        }
        if (array[keep[i]] > countnum)
        {
            countnum = array[keep[i]];
            array[keep[i]] = countnum;
        }
    }
    cout << endl;

    for (int i = 0; i <= max; i++)
    {
        if (array[i] == countnum)
        {
            cout << i << " ";
        }
    }
    cout << endl;

    temp = -999;
    for (int i = 0; i < count; i++)
    {
        if (temp != keep[i])
        {
            temp = keep[i];
            cout << keep[i];
        }
    }
}

int main()
{
    int n;
    cin >> n;
    int a[n];

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    process(a, n);
}