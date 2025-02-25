#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(pair<int, int> &x, pair<int, int> &y)
{
    return x.second < y.second;
}

void acvity(vector<pair<int, int> > &a, int n, int cpu)
{
    sort(a.begin(), a.end(), compare);

    priority_queue<int, vector<int>, greater<int> > q;

    int count = 0;
    for (int i = 0; i < cpu; i++)
    {
        q.push(0);
    }

    for (int i = 0; i < a.size(); i++)
    {
        int start = a[i].first;
        int end = a[i].second;

        int finish = q.top();

        if (finish <= start)
        {
            q.pop();
            q.push(end);
            count++;
        }
    }
    cout << count << endl;
}

int main()
{
    int n;
    int cpu = 0;
    cin >> n >> cpu;
    vector<pair<int, int> > a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i].first >> a[i].second;
    }

    acvity(a, n, cpu);
}