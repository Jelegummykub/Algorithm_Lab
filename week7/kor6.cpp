#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> select;

void subset(vector<int> &x, int l, int sum, int n, int m)
{
    if (select.size() == 3)
    {
        if (sum <= m)
        {
            sort(select.begin(), select.end());
            cout << select[0] << endl
                 << select[1] << endl
                 << select[2] << endl;
            exit(0);
        }
        return;
    }

    if (l == n)
    {
        return;
    }

    select.push_back(x[l]);
    subset(x, l + 1, sum + x[l], n, m);
    select.pop_back();
    subset(x, l + 1, sum, n, m);
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> book(n);

    for (int i = 0; i < n; i++)
    {
        cin >> book[i];
    }

    subset(book, 0, 0, n, m);
}
