#include <iostream>
#include <vector>
using namespace std;

size_t sum = 0;

void merge(vector<int> &a, int l, int m, int r)
{
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];

    for (int i = 0; i < n1; i++)
    {
        L[i] = a[l + i];
    }

    for (int j = 0; j < n2; j++)
    {
        R[j] = a[m + 1 + j];
    }
    size_t i = 0;
    size_t j = 0;
    size_t v = 0;
    size_t k = l;

    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            sum += L[i] * j + v;
            a[k] = L[i];
            i++;
        }
        else
        {
            v += R[j];
            a[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        sum += L[i] * j + v;
        a[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        a[k] = R[j];
        j++;
        k++;
    }
}

void mergesort(vector<int> &a, int l, int r)
{
    if (l < r)
    {
        size_t m = l + (r - l) / 2;
        mergesort(a, l, m);
        mergesort(a, m + 1, r);
        merge(a, l, m, r);
    }
}

int main()
{
    int n, x, y;
    cin >> n;

    vector<int> a(n);

    for (int i = 0; i < n; i++)
    {
        cin >> x >> y;
        a[y - 1] = x;
    }

    mergesort(a, 0, n - 1);

    // for (int i = 0; i < n; i++)
    // {
    //     cout << a[i] << " ";
    // }

    cout << sum;
}