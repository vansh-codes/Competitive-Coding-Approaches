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

    cout<<"Diagonal Traversal: \n";
    int dir = 0, index=0;
    int res[m*n];
    // dir = 0 -> upward, dir = 1 -> downward
    while(index < m*n){
        res[index++] = arr[row][col];
        if(dir==0){
            if(col == n-1){
                dir = 1;
                row++;
            }
            else if(row == 0){
                dir = 1;
                col++;
            }
            else{
                row--;
                col++;
            }
        }
        else{
            if(row == m-1){
                dir = 0;
                col++;
            }
            else if(col == 0){
                dir = 0;
                row++;
            }
            else{
                row++;
                col--;
            }
        }
    }
    cout<<"\n";
     

    return 0;
}