/* 
4
10 20 30 10
output: 20
https://www.naukri.com/code360/problems/frog-jump_3621012
 */

#include<bits/stdc++.h>
using namespace std;

// ============================ Recursive Approach ============================
int frogHelperRecursive(int idx, vector<int> &heights){
    if(idx==0) return 0;
    int left = frogHelperRecursive(idx-1, heights) + abs(heights[idx] - heights[idx-1]);
    int right = INT_MAX;
    if(idx>1)
        right = frogHelperRecursive(idx-2, heights) + abs(heights[idx] - heights[idx-2]);
    
    return min(left, right);
}

int frogJumpRecursive(int n, vector<int> &heights)
{
    return frogHelperRecursive(n-1, heights);
}
// ============================  END  ============================


// ============================ DP Recursive Approach ============================
int frogHelperDP(int idx, vector<int> &heights, vector<int> &dp){
    if(idx==0) return 0;
    if(dp[idx]!=-1) return dp[idx];

    int left = frogHelperDP(idx-1, heights, dp) + abs(heights[idx] - heights[idx-1]);
    int right = INT_MAX;
    if(idx>1)
        right = frogHelperDP(idx-2, heights,dp) + abs(heights[idx] - heights[idx-2]);
    
    return dp[idx] = min(left, right);
}

int frogJumpDP(int n, vector<int> &heights, vector<int> &dp){
    return frogHelperDP(n-1, heights, dp);
}
// ============================  END  ============================


// ============================ DP Tabulation Approach ============================
int frogJumpTabulation(int n, vector<int> &heights, vector<int> &dp){
    dp[0] = 0;
    int left, right = INT_MAX;
    for(int i=1;i<n;i++){
        left = dp[i-1] + abs(heights[i] - heights[i-1]);
        if(i>1)
            right = dp[i-2] + abs(heights[i] - heights[i-2]);
        dp[i] = min(left, right);
    }

    return dp[n-1];
}
// ============================  END  ============================


// ============================ DP Tabulation Space Optimized Approach ============================
int frogJumpTabulation1(int n, vector<int> &heights){
    int prev2 = 0, prev1 = 0;
    int left, right = INT_MAX;
    for(int i=1;i<n;i++){
        left = prev1 + abs(heights[i] - heights[i-1]);
        if(i>1)
            right = prev2 + abs(heights[i] - heights[i-2]);

        prev2 = prev1;
        prev1 = min(left, right);
    }
    return prev1;
}
// ============================  END  ============================


int main(){
    int n;
    cin>>n;

    vector<int> heights(n);

    for(int i=0;i<n;i++){
        cin>>heights[i];
    }

    cout<<"Recursive :"<<frogJumpRecursive(n, heights)<<"\n";

    vector<int> dp(n+1, -1);
    cout<<"DP: "<<frogJumpDP(n, heights, dp)<<"\n";
    
    vector<int> dp1(n, 0);
    cout<<"Tabulation: "<<frogJumpTabulation(n, heights, dp1)<<"\n";

    cout<<"Space optimized tabulation: "<<frogJumpTabulation1(n, heights)<<"\n";
    

    return 0;
}