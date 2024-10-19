#include<bits/stdc++.h>
using namespace std;

bool isLucky(int n, int counter = 2){
    if(counter>n){
        return true;
    }
    cout<<n<<"% "<<counter<<" = "<<n%counter<<"\n";
    if(n%counter==0){
        return false;
    }
    int next = n - n/counter;
    return isLucky(next, counter+1);
}

int main(){
    int n;
    cin>>n;

    isLucky(n) ? cout<<"Lucky Number\n" : cout<<"Not a Lucky Number\n";

    return 0;
}