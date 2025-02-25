#include <iostream>
#include <algorithm>
using namespace std;

void Greedy(int x[], int n)
{
    int prev = 0;
    int cur = 0;

    for(int i = 0; i < n; i++)
    {
        int temp = cur;
        cur = max(cur, prev + x[i]);
        prev = temp;
    }

    cout << cur << endl;
    
}

int main()
{
    int n;
    cin >> n;
    int x[n];

    for (int i = 0; i < n; i++)
    {
        cin >> x[i];
    }

    Greedy(x, n);
}
