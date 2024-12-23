#include <iostream>
using namespace std;

int main()
{

    int n = 0;
    int x = 0;
    cin >> n;
    cin >> x;
    int A[n];

    for(int i = 0; i < n; i++){
        cin >> A[i];
    }

    int temp = 0;

    for(int i = 0; i < n - 1; i++){
        for (int j = i + 1; j < n; j++){
            if (A[i] + A[j] == x){
                cout << A[i] << " " << A[j] << endl;
                temp++;
            }
        }
    }

   if(temp == 0){
        cout << -1 << endl;
    }
}