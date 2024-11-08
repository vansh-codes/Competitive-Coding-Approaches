#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, W;
    cin>>n>>W;
    vector<int> wt(n), val(n);
    for(int i = 0; i < n; i++){
        cin>>wt[i]>>val[i];
    }

    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));
    

    return 0;
}