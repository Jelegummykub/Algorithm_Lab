#include <iostream>
#include <vector>

using namespace std;

int count1 = 0;

void print(vector<int> &x, int n)
{
    int temp = 0;
    bool check = true;

    for (int i = n; i > 0; i--)
    {
        temp++;
        if (x[i])
        {
            cout << temp;
            check = false;
        }
    }

    if (check)
    {
        cout << 0;
    }
    cout << endl;
}

void subset(vector<int> &x, int l, int r)
{
    if (l == r)
    {
        count1++;
        print(x, r);
    }
    else
    {
        x[l + 1] = 0;
        subset(x, l + 1, r);
        x[l + 1] = 1;
        subset(x, l + 1, r);
    }
}

int main()
{
    int n;
    cin >> n;
    vector<int> x(n);

    subset(x, 0, n);
}