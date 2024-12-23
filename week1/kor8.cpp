#include <iostream>
using namespace std;

int main(){

    int n = 0;
    cin >> n;
    int A[n];

    for(int i = 0 ; i < n ; i++){
        cin >> A[i];
    }

    int tempmax = 0;
    int s = 0;
    int e = 0;

    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n - i ; j++){
            int sum = 0;

            for(int k = 0 ; k <= i ; k++){
                sum += A[j + k];
            }

            if(sum > tempmax){
                tempmax = sum;
                s = j;
                e = j + i;
            }
        }
    }
    cout << tempmax << endl;

}