//? https://leetcode.com/problems/pascals-triangle-ii/

#include<bits/stdc++.h>
using namespace std;

vector<int> getRow(int rowIndex) {
        if (rowIndex == 0)
            return {1};
        vector<vector<int>> dp(rowIndex + 1);
        for (int i = 0; i <= rowIndex; i++) {
            dp[i].assign(i+1, 1);
            for (int j = 1; j < i; j++) {
                dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
            }
        }

        vector<int> ans(rowIndex + 1);
        for (int i = 0; i <= rowIndex; i++) {
            ans[i] = dp[rowIndex][i];
        }

        return ans;
    }

int main(){
    
    int n;
    cin>>n;
    vector<int> ans = getRow(n);
    for(auto i: ans){
        cout<<i<<" ";
    }
    cout<<endl;

    return 0;
}