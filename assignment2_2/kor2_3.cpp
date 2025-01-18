#include <iostream>
using namespace std;

void shellSort(int a[], int n)
{
    int gaps[] = {5, 1};
    int numGaps = sizeof(gaps) / sizeof(gaps[0]);

    for (int g = 0; g < numGaps; g++)
    {
        int gap = gaps[g];

        for (int i = gap; i < n; i++)
        {
            int temp = a[i];
            int j = i;

            while (j >= gap && a[j - gap] > temp)
            {
                a[j] = a[j - gap];
                j -= gap;
            }

            a[j] = temp;
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
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

    shellSort(a, n);
}