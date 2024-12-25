#include <iostream>
using namespace std;

int interpolation(int a[] , int n , int k){
    int l = 0;
    int r = n - 1;
    

    while(l <= r && k >= a[l] && k <= a[r]){
        int inter = l + ((k - a[l]) * (r - l) / (a[r] - a[l]));

        cout << inter << " ";

        if(a[inter] == k) {
            return inter;
        }else if(a[inter] < k){
            l = inter + 1;
        }else{
            r = inter - 1;
        }

        if (l > r) break;
    }
}

int main() {
    int n;
    int k;
    cin >> n;
    cin >> k;
    int A[n];

    for(int i = 0 ; i < n ; i++){
        cin >> A[i];
    }

    int result = interpolation(A, n, k);
    
}