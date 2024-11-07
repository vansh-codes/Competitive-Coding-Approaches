#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    cin>>m>>n;

    int arr[m][n];

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++)
            cin>>arr[i][j];
    }

    cout<<"Array Elements: "<<endl;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++)
            cout<<arr[i][j]<<" ";
        cout<<"\n";
    }
    cout<<endl;

    cout<<"Zigzag Traversal: \n";
    for(int i=0;i<m;i++){
        if(i%2==0){
            for(int j=0;j<n;j++){
                cout<<arr[i][j]<<" ";
            }
        }
        else{
            for(int j=n-1;j>=0;j--){
                cout<<arr[i][j]<<" ";
            }
        }
    }
    cout<<"\n";
     

    return 0;
}