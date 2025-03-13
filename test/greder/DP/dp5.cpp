#include <iostream>
#include <vector>
using namespace std;

int f(int n){
    vector<int> memo(n + 1 , -1);

    if(n == 0 || n == 1){
        return 1;
    }

    if(memo[n] != -1){
        return memo[n];
    }

    memo[n] = (3 * f(n-2)) + (2 * f(n-1));

    return memo[n];
}

int main(){
    int n;
    cin >> n;

    int result = f(n);
    cout << result << endl;
}




// #include <iostream>
// #include <vector>
// using namespace std;

// int f(int n)
// {
//     vector<int> memo(n + 1, -1);

//     if (n == 0 || n == 1)
//     {
//         return 1;
//     }

//     if (memo[n] != -1)
//     {
//         return memo[n];
//     }

//     memo[n] = ((3 * f(n - 1)) + (2 * f(n - 2)));
//     return memo[n];
// }

// int main()
// {
//     int n;
//     cin >> n;

//     int result = f(n);
//     cout << result << endl;
// }