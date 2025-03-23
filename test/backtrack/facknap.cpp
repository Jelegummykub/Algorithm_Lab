#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

struct Item
{
    double weight;
    double value;
    int index;
};

bool check(Item a, Item b)
{
    return (a.value / a.weight) > (b.value / b.weight);
}

double fractionalKnapsack(int W, vector<Item> &item, vector<double> &ratio)
{
    sort(item.begin(), item.end(), check);

    double max = 0.0;

    for (int i = 0; i < item.size(); i++)
    {
        if (W >= item[i].weight)
        {
            max += item[i].value;
            W -= item[i].weight;
            ratio[item[i].index] = 1.0;
        }
        else
        {
            max += item[i].value * (W / item[i].weight);
            ratio[item[i].index] = W / item[i].weight;
            break;
        }
    }
    return max;
}

int main()
{
    int n, W;
    cin >> n >> W;

    vector<Item> item(n);
    vector<double> ratio(n, 0.0);

    for (int i = 0; i < n; i++)
    {
        cin >> item[i].weight;
        item[i].index = i;
    }

    for (int i = 0; i < n; i++)
    {
        cin >> item[i].value;
    }

    double result = fractionalKnapsack(W, item, ratio);

    for (int i = 0; i < n; i++)
    {
        cout << fixed << setprecision(2) << ratio[i] << " ";
    }

    cout << endl;

    cout << fixed << setprecision(2) << result << endl;
}