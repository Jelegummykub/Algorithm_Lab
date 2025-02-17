#include <iostream>
using namespace std;
int value[9999];
int maxx = 0;
int price = 0;
int save[3];
void subset(int A[], int left, int k, int right, int temp)
{
    if (temp > price)
    {
        return;
    }
    if (left == k)
    {
        int temp[3];
        int sum = 0;
        for (int i = 0; i < k; i++)
        {
            sum += value[A[i] - 1];
            temp[i] = value[A[i] - 1];
        }
        if (sum > maxx && sum <= price)
        {
            maxx = sum;
            for (int i = 0; i < k; i++)
            {
                save[i] = temp[i];
            }
        }
        return;
    }
    else
    {
        for (int i = left; i < right; i++)
        {
            bool check = true;
            for (int j = 0; j < left; j++)
            {
                if (A[j] == i + 1 || A[j] > i + 1)
                {
                    check = false;
                    break;
                }
            }
            if (check)
            {

                A[left] = i + 1;
                temp += A[left];
                subset(A, left + 1, k, right, temp);
            }
        }
    }
}

int main()
{
    int n;
    cin >> n >> price;
    int A[3];
    for (int i = 0; i < n; i++)
    {
        cin >> value[i];
    }
    int temp = 0;

    subset(A, 0, 3, n, temp);

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (save[i] < save[j])
            {
                swap(save[i], save[j]);
            }
        }
    }

    for (int i = 0; i < 3; i++)
    {
        cout << save[i] << endl;
    }
}