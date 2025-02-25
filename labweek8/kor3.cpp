#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(pair<double, double> &x, pair<double, double> &y)
{
    return x.second < y.second;
}

void platform(vector<pair <double , double> > &a, int n)
{
    sort(a.begin(), a.end(), compare);

    priority_queue<double, vector<double>, greater<double> > q;

    q.push(0);

    for (int i = 0; i < a.size(); i++)
    {
        int start = a[i].first;
        int end = a[i].second;

        int finish = q.top();

        if (finish <= start)
        {
            q.pop(); 
        }
        q.push(end);
    }
    cout << q.size() << endl;
}

int main()
{
    int n;
    cin >> n;

    vector<pair<double, double> > a(n);

    for(int i = 0 ; i < n ; i++){
        cin >> a[i].first >> a[i].second;
    }

    platform(a , n);
}