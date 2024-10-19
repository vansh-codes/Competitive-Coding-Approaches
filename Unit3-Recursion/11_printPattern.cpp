// https://www.geeksforgeeks.org/problems/print-pattern3549/1
#include<bits/stdc++.h>
using namespace std;

//* print pattern -5 then +5
//* ex: n=16 gives output 16 11 6 1 -4 1 6 11 16

vector<int> printPattern(int n, int current, vector<int> &ans){
    if(current<=0){
        ans.push_back(current);
        return ans;
    }
    ans.push_back(current);
    printPattern(n, current-5, ans);
    ans.push_back(current);
    return ans;
}

int main(){
    int n;
    cin>>n;
    vector<int> pattern;
    printPattern(n, n, pattern);

    for(int p: pattern){
        cout<<p<<" ";
    }
    cout<<"\n";

    return 0;
}