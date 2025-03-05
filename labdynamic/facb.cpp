#include <iostream>
#include <vector>
using namespace std;

int factoral(int n)
{
    vector<int> temp(n);
    temp[0] = 1;
    temp[1] = 1;

    for (int i = 2; i <= n; i++)
    {
        temp[i] = i * temp[i - 1];
    }

    return temp[n];
}

int main()
{
    int n;
    cin >> n;

    int result = factoral(n);
    cout << result << endl;
}