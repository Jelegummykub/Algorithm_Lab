#include <iostream>
using namespace std;

long long Multiply(int a, int b)
{
    if (a < 10)
    {
        return a * b;
    }
    int a1 = a, b1 = 1, a2, b2;
    while (a1 > 10)
    {
        b1++;
        a1 /= 10;
    }

    int z = 1;
    for (int i = 0; i < b1 / 2; i++)
    {
        z *= 10;
    }

    a1 = a / z;
    b1 = b / z;
    a2 = a % z;
    b2 = b % z;

    long long D = Multiply(a2, b2);
    long long B = Multiply(a2, b1);
    long long C = Multiply(a1, b2);
    long long A = Multiply(a1, b1);

    cout << A << " " << B << " " << C << " " << D << endl;

    return A * z * z + (B + C) * z + D;
}

int main()
{
    int a, b;
    cin >> a >> b;

    cout << Multiply(a, b);
}