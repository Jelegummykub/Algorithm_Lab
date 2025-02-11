#include <iostream>
#include <vector>
using namespace std;

void permute(vector<int> &x, vector<int> &temp, int l, int r, int &count)
{
    if (temp.size() == r)
    {
        for (int i = 0; i < r; i++)
        {
            cout << temp[i] << " ";
        }
        cout << endl;
        count++;
    }

    for (int i = l; i < x.size(); i++)
    {

        temp.push_back(x[i]);
        permute(x, temp, i + 1, r, count);
        temp.pop_back();
    }
}

int main()
{
    int n, k, count = 0;
    cin >> n >> k;
    vector<int> x;

    for (int i = 1; i <= n; i++)
    {
        x.push_back(i);
    }

    vector<int> temp;

    permute(x, temp, 0, k, count);

    cout << count << endl;
}