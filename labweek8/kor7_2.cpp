#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(pair<int, int> &x, pair<int, int> &y)
{
    return x.first < y.first;
}

void activity(vector<pair<int, int> > &a, int n)
{
    sort(a.begin(), a.end(), compare);

    int last_end = -1;
    vector<pair<int, int> > result;

    for (int i = 0; i < n; i++)
    {
        if (a[i].first >= last_end)
        {
            result.push_back(a[i]);
            last_end = a[i].second;
        }
    }

    cout << result.size() << endl;
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i].first << " " << result[i].second << endl;
    }
}

int main()
{
    int n;
    cin >> n;
    vector<pair<int, int> > a(n);

    for (int i = 0; i < n; i++)
    {
        cin >> a[i].first >> a[i].second;
    }

    activity(a, n);
}