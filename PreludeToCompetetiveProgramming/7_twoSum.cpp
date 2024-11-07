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
    
    int target;
    cout<<"Enter the target sum: ";
    cin>>target;
    int start = 0;
    int end = n-1;
    while(start<end){
        if(arr[start]+arr[end]==target){
            cout<<"Indices are: "<<start<<" "<<end<<endl;
            cout<<"Numbers are: "<<arr[start]<<" "<<arr[end]<<endl;
            break;
        }
        else if(arr[start]+arr[end]<target){
            start++;
        }
        else{
            end--;
        }
    }

    return 0;
}