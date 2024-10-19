#include<bits/stdc++.h>
using namespace std;

int findSquareSum(int n){
    int sum=0;
    while(n){
        int rem = n%10;
        sum += rem*rem;
        n = n/10;
    }
    return sum;
}

bool isHappy(int n){
    if(n==1 || n==7){
        return true;
    }
    if(n==2 || n==3 || n==4 || n==5 || n==6 || n==8 || n==9){
        return false;
    }
    return isHappy(findSquareSum(n));
}

int nextHappy(int n){
    while(true){
        if(isHappy(++n)){
            return n;
        }
    }
}

int main(){
    int n;
    cin>>n;
    int num = nextHappy(n);
    cout<<"Next Happy Number is: "<<num<<"\n";

    return 0;
}