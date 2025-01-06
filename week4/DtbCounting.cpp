#include <iostream>
#include <vector>
using namespace std;

void DistributionCounting(int arr[], int l, int u, int n)
{
    int range = u - l + 1;
    vector<int> D(range, 0);
    vector<int> S(n);

    for (int i = 0; i < n; i++)
    {
        D[arr[i] - l]++;
    }

    for (int j = 1; j < range; j++)
    {
        D[j] += D[j - 1];
    }

    for (int i = n - 1; i >= 0; i--)
    {
        int j = arr[i] - l;
        S[D[j] - 1] = arr[i];
        D[j]--;
    }

    for (int i = 0; i < n; i++)
    {
        cout << S[i] << " ";
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

    int l = *min_element(a, a + n);
    int u = *max_element(a, a + n);

    DistributionCounting(a, l, u, n);

    return 0;
}
