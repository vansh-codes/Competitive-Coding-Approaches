/* 
? You are climbing a staircase. It takes n steps to reach the top. Each time you can either climb 1 or 2 steps. 
TODO: In how many distinct ways can you climb to the top?
https://leetcode.com/problems/climbing-stairs/description/
 */

// similar to fibonacci series
#include<bits/stdc++.h>
using namespace std;

int recursionClimb(int n, vector<int> &dp);
int tabulation1Climb(int n, vector<int> &dp);
int tabulation2Climb(int n);

int main(){
    int n;
    cin>>n; //nth stair

    vector<int> dp1(n+1, -1);    // bottom up approach
    cout<<"Using Recursion: "<<recursionClimb(n, dp1)<<"\n";

    vector<int> dp2(n+1);    // tabulation approach
    cout<<"Using Tabulation1: "<<tabulation1Climb(n, dp2)<<"\n";

    vector<int> dp3(n+1);    // tabulation approach -> space optimized
    cout<<"Using Tabulation2: "<<tabulation2Climb(n)<<"\n";

    return 0;
}

// filling dp using recursion
int recursionClimb(int n, vector<int> &dp){   // TC: O(n) SC: O(n)
    if(n==0 || n == 1) return 1;
    if(dp[n] != -1) return dp[n];
    return dp[n] = recursionClimb(n-1, dp) + recursionClimb(n-2, dp);
}

// filling dp using tabulation
int tabulation1Climb(int n, vector<int> &dp){ // TC: O(n) SC: O(n)
    dp[0] = 1;
    dp[1] = 1;
    for(int i = 2; i<=n; i++){
        dp[i] = dp[i-1] + dp[i-2];
    }
    
    return dp[n];
}

// storing last and secondLast values only in variables, space optimized
int tabulation2Climb(int n){                  // TC: O(n) SC: O(1)
    int prev2 = 1, prev1 = 1;
    for(int i = 2; i<=n ; i++){
        int curr = prev1 + prev2;
        prev2 = prev1;
        prev1 = curr;
    }
    
    return prev1;
}