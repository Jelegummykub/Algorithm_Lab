#include <iostream>
#include <vector>
using namespace std;

int min_diff = 999999999;

void subset(vector<pair<int, int> > &x, int index, int sum1, int sum2, int n)
{
    if (index == n)
    {
        int diff = sum1 - sum2;
        if (diff < 0)
            diff = -diff;
        if (diff < min_diff)
        {
            min_diff = diff;
        }
        return;
    }
    subset(x, index + 1, sum1 + x[index].first, sum2 + x[index].second, n);
    subset(x, index + 1, sum1 + x[index].second, sum2 + x[index].first, n);
}

int main()
{
    int n;
    cin >> n;

    vector<pair<int, int> > x(n);

    for (int i = 0; i < n; i++)
    {
        cin >> x[i].first >> x[i].second;
    }
    subset(x, 0, 0, 0, n);

    cout << min_diff << endl;
}
