#include <iostream>
using namespace std;

int count = -1;
void Greedy(int m, int n)
{

    int square = min(m, n);

    ::count += m / square;

    if (n % m != 0)
    {
        Greedy(n, m % n);
    }
    else
    {
        return;
    }
}

int main()
{
    int m, n;
    cin >> m >> n;

    Greedy(m, n);

    cout << ::count;
}