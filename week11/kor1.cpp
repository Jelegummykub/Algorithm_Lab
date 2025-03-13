#include <iostream>
#include <vector>
using namespace std;

int sum(vector<int> &a, int n, int k)
{
    vector<vector<int> > memo(n + 1, vector<int>(n + 1, -1));

    if (k == 0)
    {
        return 0;
    }

    if(n == 0 || k < 0){
        return -1;
    }

    if (memo[n][k] != -1)
    {
        return memo[n][k];
    }

    int temp = sum(a, n - 1, k);
    int select = -1;
    
    if (k >= a[n - 1])
    {
        int res = sum(a, n - 1, k - a[n - 1]);
        if (res != -1)
        {
            select = res + 1;
        }
    }

    return memo[n][k] = max(temp, select);
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int k;
    cin >> k;

    int result = sum(arr, n, k);
    cout << result << endl;
}
