#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int platform(int n, vector<double> &a, vector<double> &b)
{

    int result = 1;

    for (int i = 0; i < n; i++)
    {
        int count = 1;
        for (int j = 0; j < n; j++)
        {
            if (i != j)
            {
                if (a[i] < b[j] && b[i] > a[j])
                {
                    count++;
                }
            }
        }
        result = max(count, result);
    }
    return result;
}

int main()
{
    int n;
    cin >> n;

    vector<double> a(n);
    vector<double> b(n);

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
    }

    int result = platform(n, a, b);

    cout << result << endl;
}

// TODO: Not working