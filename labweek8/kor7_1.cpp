#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(pair<int, int> &x, pair<int, int> &y)
{
    int chackx = x.second - x.first;
    int chacky = y.second - y.first;

    if (chackx == chacky)
    {
        return x.second < y.second;
    }
    return chackx > chacky; 
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

// 10
// 1 4
// 3 5
// 0 6
// 5 7
// 3 8
// 5 9
// 6 10
// 8 11
// 8 12
// 2 13
