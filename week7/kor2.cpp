#include <iostream>
#include <vector>
using namespace std;

void permute(vector<int> &x, vector<int> &temp, int r, int &count)
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

    for (int i = 0; i < x.size(); i++)
    {
        bool found = false;
        for (int j = 0; j < temp.size(); j++)
        {
            if (temp[j] == x[i])
            {
                found = true;
                break;
            }
        }
        if (!found)
        {
            temp.push_back(x[i]);
            permute(x, temp, r, count);
            temp.pop_back();
        }
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

    permute(x, temp, k, count);

    cout << count << endl;
}