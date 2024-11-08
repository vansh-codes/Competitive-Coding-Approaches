#include<bits/stdc++.h>
using namespace std;

int recursionFib(int n, vector<int> &dp);
int tabulation1Fib(int n, vector<int> &dp);
int tabulation2Fib(int n);

int main(){
    int n;
    cin>>n; //nth fibonacci number

    vector<int> dp1(n+1, -1);    // bottom up approach
    cout<<"Using Recursion: "<<recursionFib(n, dp1)<<"\n";

    vector<int> dp2(n+1);    // tabulation approach
    cout<<"Using Tabulation1: "<<tabulation1Fib(n, dp2)<<"\n";

    vector<int> dp3(n+1);    // tabulation approach -> space optimized
    cout<<"Using Tabulation2: "<<tabulation2Fib(n)<<"\n";

    return 0;
}

// filling dp using recursion
int recursionFib(int n, vector<int> &dp){   // TC: O(n) SC: O(n)
    if(n <= 1) return n;
    if(dp[n] != -1) return dp[n];
    return dp[n] = recursionFib(n-1, dp) + recursionFib(n-2, dp);
}

// filling dp using tabulation
int tabulation1Fib(int n, vector<int> &dp){ // TC: O(n) SC: O(n)
    dp[0] = 0;
    dp[1] = 1;
    for(int i = 2; i<=n; i++){
        dp[i] = dp[i-1] + dp[i-2];
    }
    
    return dp[n];
}

// storing last and secondLast values only in variables, space optimized
int tabulation2Fib(int n){                  // TC: O(n) SC: O(1)
    int prev2 = 0, prev1 = 1;
    for(int i = 2; i<=n ; i++){
        int curr = prev1 + prev2;
        prev2 = prev1;
        prev1 = curr;
    }
    
    return prev1;
}
