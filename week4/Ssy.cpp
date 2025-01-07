#include <iostream>
using namespace std;

int patition(int a[], int l, int u)
{
    int pivot = a[u];
    int i = l - 1;

    for (int j = l; j < u; j++)
    {
        if (a[j] < pivot)
        {
            i++;
            swap(a[i], a[j]);
        }
    }

    swap(a[i + 1], a[u]);
    return i + 1;
}

void quicksort(int a[], int l, int u)
{
    if (l < u)
    {
        int pivot = patition(a, l, u);

        quicksort(a, l, pivot - 1);
        quicksort(a, pivot + 1, u);
    }
}

void findfrequency(int a[], int n)
{
    int keep[1000];
    int count = 0;
    int max = -1;

    for (int i = 0; i < n; i++)
    {
        int tempnumber[99];
        int size = 0;
        while (a[i] > 0)
        {
            tempnumber[size++] = a[i] % 10;
            a[i] /= 10;
        }

        for (int j = size - 1; j >= 0; j--)
        {
            if (tempnumber[j] > max)
            {
                max = tempnumber[j];
            }

            keep[count++] = tempnumber[j];
        }
    }

    // for (int i = 0; i < count; i++)
    // {
    //     cout << temp[i] << " ";
    // }
    // cout << endl;

    int tempfrequency[10] = {0};
    int tempmax = -999;
    int countnumber = 1;

    for (int i = 0; i < count; i++)
    {

        if (tempmax != keep[i])
        {
            tempmax = keep[i];
            if (tempfrequency[keep[i]] != countnumber)
            {
                tempfrequency[keep[i]] = 1;
            }
        }
        else
        {
            tempfrequency[keep[i]]++;
        }

        if (tempfrequency[keep[i]] > countnumber)
        {
            countnumber = tempfrequency[keep[i]];
        }
    }

    for (int i = 0; i <= max; i++)
    {
        if (tempfrequency[i] == countnumber)
        {
            cout << i << " ";
        }
    }
    cout << endl;

    tempmax = -999;
    for (int i = 0; i < count; i++)
    {
        if (tempmax != keep[i])
        {
            tempmax = keep[i];
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

    quicksort(a, 0, n - 1);

    for (int i = 0; i < n; i++)
    {
        cout << a[i];
    }
    cout << endl;

    findfrequency(a, n);
}