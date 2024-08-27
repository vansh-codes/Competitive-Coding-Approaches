// ? Given n, find sum of all prime numbers till n(inclusive)
// example: n=5, sum would be 10 => 2+3+5 = 10

// * Approach: Sieve of Eratosthenes
#include<bits/stdc++.h>
using namespace std;

long long int primeSum(int n){
    // Code here
    if(n==1) return 0;
    vector<long long> arr(n+1, 1);
    long long primeSum = 0;
    for(long long i=2;i<=n+1;i++){
        if(arr[i]==1){
            for(long long j=i*i; j<=n;j+=i){
                arr[j]=0;
            }
            // cout<<i<<" "<<arr[i]<<"\n";
            primeSum += i;
        }
    }
    
    return primeSum;
}

int main(){
    int n;
    cout<<"Enter the upper limit of range: ";
    cin>>n;

    cout<<"Sum: "<<primeSum(n)<<"\n";

    return 0;
}

// Time Complexity: O(n*log(log(n)))

// GFG LINK: https://practice.geeksforgeeks.org/problems/sum-of-all-prime-numbers-between-1-and-n4404/1