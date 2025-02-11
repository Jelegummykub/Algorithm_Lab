#include <iostream>
using namespace std;

int cal(long long x, long long i, long long n, long long sum)
{
    if (sum == x)
    {
        return 1; // นับจำนวนวิธีที่เป็นไปได้
    }
    if (sum > x || i > n)
    {
        return 0; // ถ้าผลรวมเกิน x หรือ i เกิน n แล้วให้หยุด
    }

    // ลองทั้งสองทาง: ไม่เอา i หรือเอา i รวมเข้าไป
    return cal(x, i + 1, n, sum) + cal(x, i + 1, n, sum + i);
}

int main()
{
    long long n = 20000000000; // คงค่า n ตามเดิม
    long long x;
    cin >> x;
    long long sum = 0;

    int re = cal(x, 1, n, sum);
    cout << re;
}
