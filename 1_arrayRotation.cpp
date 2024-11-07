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
    
    int k; 
    cout<<"Enter k: \n";
    cin>>k;
    k = k%n;

    reverse(arr, arr+n);
    reverse(arr, arr+k);
    reverse(arr+k, arr+n);

    cout<<"Rotated Array Elements: "<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    return 0;
}