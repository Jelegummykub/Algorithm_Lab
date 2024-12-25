#include <iostream>
using namespace std;

void countingsort(int arr[] , int n){
    int count[999] = {0};
    int B[n+1];
    for(int i = 0 ; i < n ; i++){
       for(int j = 0 ; j < n ; j++){
           if(arr[i] > arr[j]){
               count[i]++;
           }
       }
    }

    for(int i = 0 ; i < n ; i++){
        B[count[i]] = arr[i];
    }

    for(int i = 0 ; i < n ; i++){
        cout << B[i] << " ";
    }
   
    
}

int main(){
    int n;
    cin >> n;
    int a[n];
    for(int i = 0 ; i < n ; i++){
        cin >> a[i];
    }

    countingsort(a , n);
}