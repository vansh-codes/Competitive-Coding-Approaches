#include<bits/stdc++.h>
using namespace std;

// Time Complexity: O(n*capacity), Auxiliary Space: O(n*capacity) 
int main(){
    int n;
    cin>>n;

    vector<int> weight(n), values(n);
    cout<<"Enter weight, value: \n";
    for(int i=0;i<n;i++){
        cin>>weight[i]>>values[i];
    }

    int capacity;
    cin>>capacity;

    vector<vector<int>>dp(n+1, vector<int> (capacity+1, 0));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=capacity;j++){
            if(weight[i-1] <= j){
                dp[i][j] = max(values[i-1] + dp[i-1][j-weight[i-1]], dp[i-1][j]); 
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    cout<<"Maximum value we can obtain = "<<dp[n][capacity];

    return 0;
}