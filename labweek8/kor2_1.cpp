#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void Greedy(int n, vector<int> &w, int l, int r)
{
    sort(w.begin(), w.end(), greater<int>());

    for (int i = 0; i < n; i++)
    {
        if (l <= r)
        {
            l += w[i];
        }
        else
        {
            r += w[i];
        }
    }

    cout << abs(l - r) << endl;
}

int main()
{
    int n;
    cin >> n;
    vector<int> w(n);

    for (int i = 0; i < n; i++)
    {
        cin >> w[i];
    }

    Greedy(n, w, 0, 0);
}
