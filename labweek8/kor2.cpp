#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

double MRT(int n, vector<int> &a)
{

    sort(a.begin(), a.end());

    int sum = 0;
    int temp = 0;

    for (int i = 0; i < n; i++)
    {
        temp += a[i];
        sum += temp;
    }

    double result = (double)sum / n;

    return result;
}

int main()
{
    int n;
    cin >> n;

    vector<int> a(n);

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    double result = MRT(n, a);

    cout << fixed << setprecision(2) << result << endl;
}