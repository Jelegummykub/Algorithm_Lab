#include <iostream>
#include <vector>
using namespace std;

int factoral(int n)
{
    vector<int> temp(n);
    if (n == 0)
    {
        return 1;
    }

    if (temp[n] != 0)
    {
        return temp[n];
    }

    temp[n] = n * factoral(n - 1);
    return temp[n];
}

int main()
{
    int n;
    cin >> n;

    int result = factoral(n);
    cout << result << endl;
}