#include <iostream>
#include <vector>
using namespace std;

vector<vector<int> > x(100, vector<int>(100, -1));

int subset(vector<int> &A, int n, int sum,int count)
{
    if (sum == 0){
        return count+1;
    } 
    if (n == 0 || sum < 0) {
        return 0;
    }

    if (x[n][sum] != -1){
        return x[n][sum];
    } 

    if (A[n-1] > sum)
    {
        return x[n][sum] = subset(A, n - 1, sum, count);
    }
    
    return x[n][sum] = max(subset(A,n-1,sum-A[n-1],count+1), subset(A, n - 1, sum, count));
}

int main(){

    int n, k;
    cin >> n;
    vector<int> A(n);
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }
    cin >> k;
    cout << subset(A, n, k,0) << endl;

}