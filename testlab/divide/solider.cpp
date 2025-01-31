#include <iostream>
#include <vector>
using namespace std;

void merge(vector<pair<int, int>> &a, int l, int m, int r)
{
    int n1 = m - l + 1;
    int n2 = r - m;

    vector<pair<int, int>> L(n1), R(n2);

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
    size_t k = l;

    while (i < n1 && j < n2)
    {
        if (L[i].first < R[j].first || (L[i].first == R[j].first && L[i].second > R[j].second))
        {
            a[k] = L[i];
            i++;
        }
        else
        {
            a[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
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

void mergesort(vector<pair<int, int>> &a, int l, int r)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;
        mergesort(a, l, m);
        mergesort(a, m + 1, r);
        merge(a, l, m, r);
    }
}

int main()
{
    int n;
    cin >> n;
    vector<pair<int, int>> a(n);

    for (int i = 0; i < n; i++)
    {
        cin >> a[i].first >> a[i].second;
    }

    mergesort(a, 0, n - 1);

    // for (int i = 0; i < n; i++)
    // {
    //     cout << "debug : " << a[i].first << " " << a[i].second << endl;
    // }

    vector<pair<int, int>> result;
    int max = 0;

    for (int i = n - 1; i >= 0; i--)
    {
        if (a[i].second >= max)
        {
            result.push_back(a[i]);
            // cout << "debug2 : " << result[i].first << " " << result[i].second << endl;
            max = a[i].second;
            // cout << "debugmax : " << max << endl;
        }
    }

    // cout << result.size() << endl;

    mergesort(result, 0, result.size() - 1);

    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i].first << " " << result[i].second << endl;
    }
}
