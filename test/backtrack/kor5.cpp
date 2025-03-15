#include <iostream>
#include <vector>

using namespace std;

int temp = 0;

void subset(vector<int> &x, int n, int l, int sum)
{

    if (l >= n)
    {
        temp = max(temp, sum);
        return;
    }

    subset(x, n, l + 2, sum + x[l]);
    subset(x, n, l + 1, sum);
}

int main()
{
    int n;
    cin >> n;

    vector<int> x(n);

    for (int i = 0; i < n; i++)
    {
        cin >> x[i];
    }

    subset(x, n, 0, 0);

    cout << temp << endl;
}