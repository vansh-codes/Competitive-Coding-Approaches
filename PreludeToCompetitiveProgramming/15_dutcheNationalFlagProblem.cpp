//? Given an array of 0s,1s and 2s sort it

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

    int left=0;         // for zeroes means they should be in the left section
    int mid = 0;        // for one's because they should be in the middle section
    int right = n-1;    // for two's because they should be in the right section

    // mid is the pointer which traverses through each element
    while(mid<right){       // *NOT DONE*
        if(arr[mid]==0){
            swap(arr[left], arr[mid]);
            left++; mid++;
        } else if(arr[mid] == 1){
            // swap(arr[left], arr[mid]);
            mid++;
        } else if(arr[mid]==2){
            swap(arr[mid], arr[right]);
            if(arr[mid]!=2){ 
                mid++;
                right--;
            }
        }
    }

    cout<<"Sorted Array Elements: "<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    

    return 0;
}