#include<bits/stdc++.h>
using namespace std;
//? https://www.geeksforgeeks.org/problems/factors-sum2016/1


long long factorSum(int n)
    {
        long long sum=0;
        for(int i=1;i*i<=n;i++){
            if(n%i==0){
                sum += i;
                if(n/i != i){
                    sum += n/i;
                }
            }
        }
        return sum;
    }

int main(){
    int n;
    cin>>n;
    cout<<factorSum(n)<<"\n";

    return 0;
}