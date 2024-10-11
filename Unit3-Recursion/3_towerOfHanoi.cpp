#include<bits/stdc++.h>
using namespace std;

void TOH(int n, char A, char B, char C){
    if(n==1){
        cout<<"Move disk "<<n<<" from "<<A<<" to "<<B<<"\n";
        return;
    }
    TOH(n-1, A,C,B);
    cout<<"Move disk "<<n<<" from "<<A<<" to "<<B<<"\n";
    TOH(n-1, B,C,A);
}

int main(){
    int n; cin>>n;
    TOH(n, 'A', 'B', 'C');
    return 0;
}