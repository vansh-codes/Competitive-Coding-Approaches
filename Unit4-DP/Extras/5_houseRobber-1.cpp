//? https://leetcode.com/problems/house-robber/
// testcase: 
// n = 4
// nums = [1 2 3 1]
// output: 4


#include<bits/stdc++.h>
using namespace std;

int maxProfit_memoization(int ind, vector<int> &nums, vector<int> &dp){
    if(ind==0) return nums[ind];
    if(ind<0) return 0;
    if(dp[ind] != -1) return dp[ind];

    int pick = nums[ind] + maxProfit_memoization(ind-2, nums, dp);
    int notPick = maxProfit_memoization(ind-1, nums, dp);
    return dp[ind] = max(pick, notPick);
}

// using tabulation
int maxProfit_tabulation(int n, vector<int> &nums){
    vector<int> dp(n, -1);
    dp[0] = nums[0];
    int pick, notPick;
    for(int i=1; i<n; i++){
        pick = nums[i];
        if(i>1) pick += dp[i-2];
        notPick = dp[i-1];
        dp[i] = max(pick, notPick);
    }

    return dp[n-1];
}

// using tabulation -> space optimized
int maxProfit_tabulation2(int n, vector<int> &nums){
    int prev2 = 0, prev1 = nums[0], pick, notPick;
    for(int i=1;i<n;i++){
        pick = nums[i];
        if(i>1) pick += prev2;
        notPick = prev1;
        int curr = max(pick, notPick);
        prev2 = prev1;
        prev1 = curr;
    }
    return prev1;
}


int main(){
    int n;
    cin>>n;

    vector<int> nums(n);
    for(int i=0; i<n; i++){
        cin>>nums[i];
    }

    vector<int> dp(n, -1);
    cout<<"Memoization: "<<maxProfit_memoization(n-1,nums,dp)<<"\n";
    cout<<"Tabulation-1: "<<maxProfit_tabulation(n, nums)<<"\n";
    cout<<"Tabulation-2: "<<maxProfit_tabulation2(n, nums)<<"\n";

    return 0;
}