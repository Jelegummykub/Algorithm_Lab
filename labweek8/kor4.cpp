#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Gift
{
    int gift1, gift2;
    Gift() {}
    Gift(int g1, int g2) : gift1(g1), gift2(g2) {}
};

int diff(int n, vector<Gift> &gift)
{
    int sum1 = 0;
    int sum2 = 0;

    vector<int> temp(n * 2);

    for (int i = 0; i < n; i++)
    {
        temp[i * 2] = gift[i].gift1;
        temp[i * 2 + 1] = gift[i].gift2;
    }

    sort(temp.begin(), temp.end(), greater<int>());

    for (int i = 0; i < n * 2; i++)
    {
        if (sum1 <= sum2)
        {
            sum1 += temp[i];
        }
        else
        {
            sum2 += temp[i];
        }
    }

    return abs(sum1 - sum2);
}

int main()
{
    int n;
    cin >> n;

    vector<Gift> gift(n);

    for (int i = 0; i < n; i++)
    {
        int gift1, gift2;
        cin >> gift1 >> gift2;
        gift[i] = Gift(gift1, gift2);
    }

    int result = diff(n, gift);
    cout << result << endl;
}