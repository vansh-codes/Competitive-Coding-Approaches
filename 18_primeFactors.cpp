#include<bits/stdc++.h>
using namespace std;

//? Find out prime factors of a number

//* Approach 1: Lists all the prime factors but prints repeated as well
// Test for: 119, 17, 19, 238, 169
/* int main(){
    int n;
    cin>>n;

    while(n%2==0){
        cout<<2<<" ";
        n/=2;
    }
    for(int i=3;i*i<=n;i+=2){
        while(n%i==0){
            n/=i;
            cout<<i<<" ";
        }
    }
    if(n>1){
        cout<<n<<"\n";
    }

    return 0;
} */

//* Approach 2: Using flag variable to print prime factors only once
int main(){
    int n;
    cin>>n;
    bool evenFlag = false;
    while(n%2==0){
        if(!evenFlag)
            cout<<2<<" ";
        evenFlag = true;
        n/=2;
    }
    for(int i=3;i*i<=n;i+=2){
        bool flag = false;  
        while(n%i==0){
            n/=i;
            if(!flag)
                cout<<i<<" ";
            flag = true;
        }
    }
    if(n>1){
        cout<<n<<"\n";
    }

    return 0;
}