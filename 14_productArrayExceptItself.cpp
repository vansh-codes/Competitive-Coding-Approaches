//? Given an array size n, return a array of product of all array elements except the ith index
// Ex: [1,2,3,4] -> [24, 12, 8, 6]

#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;

    int arr[n];

    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    cout<<"Array Elements: "<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    

    return 0;
}