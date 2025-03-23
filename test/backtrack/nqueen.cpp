#include <iostream>
#include <vector>
using namespace std;

void nqueen(vector<int> &x, int l, int n){
    if(l == n){
        for(int i = 0 ; i < n ; i++){
            cout << x[i] << " ";
        }
        cout << endl;
        return;
    }

    for(int i = 0 ; i < n ; i++){
        bool check = true;
        for(int j = 0 ; j < l ; j++){
            if(x[j] == i || x[j] == i + l - j || x[j] == i - l + j){
                check = false;
                break;
            }
        }

        if(check){
            x[l] = i;
            nqueen(x, l + 1, n);
        }
    }
}

int main(){
    int n;
    cin >> n;

    vector<int> x(n);

    nqueen(x, 0, n);
}