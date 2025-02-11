#include <iostream>
#include <vector>
using namespace std;

int partition(vector<int> &a, int l, int r)
{
    int m = (l + r) / 2;
    int p = a[m];
    swap(a[m], a[r]); // นำ pivot ไปไว้ท้ายสุด
    int i = l;

    for (int j = l; j < r; j++)
    {
        if (a[j] < p)
        {
            swap(a[i], a[j]);
            i++;
        }
    }

    swap(a[i], a[r]);     // นำ pivot กลับมาไว้ในตำแหน่งที่ถูกต้อง
    cout << i + 1 << " "; // แสดงตำแหน่งของ pivot
    return i;
}

void quicksort(vector<int> &a, int l, int r)
{
    if (l < r)
    {
        int p = partition(a, l, r);
        quicksort(a, l, p - 1);
        quicksort(a, p + 1, r);
    }
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

    quicksort(a, 0, n - 1);
    cout << endl; // เว้นบรรทัดให้ผลลัพธ์ดูชัดเจน

    return 0;
}
