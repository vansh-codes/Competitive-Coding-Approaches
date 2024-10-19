#include<bits/stdc++.h>
using namespace std;

bool isPowerOfTwo(int n){
    if(n<=0) return false;
    if(n%2!=0) return false;
    if(n/2==1) return true;
    return isPowerOfTwo(n/2);
}

int main(){
    int n;
    cin>>n;

    cout<<isPowerOfTwo(n)<<"\n";

    return 0;
}

// same for power of 3, 4, etc.