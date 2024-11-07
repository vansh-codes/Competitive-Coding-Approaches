#include<bits/stdc++.h>
#include<iomanip>
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

    cout<<"Upper Triangle: \n";
    for(int i=0;i<m;i++){
        for(int j=i;j<n;j++){
            // if(i<=j){
                cout<<setw(3)<<arr[i][j];
            // }
            // else{
            //     cout<<"in else\n";
            //     break;
            //     cout<<setw(3)<<" ";
            // }
        }
        cout<<"\n";
    }

    cout<<"\nLower Triangle: \n";
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(i>=j){
                cout<<setw(2)<<arr[i][j]<<" ";
            }
            else{
                cout<<setw(2)<<"";
            }
        }
        cout<<"\n";
    }
    

    return 0;
}