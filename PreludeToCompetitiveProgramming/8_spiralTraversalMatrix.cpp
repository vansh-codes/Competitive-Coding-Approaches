#include<bits/stdc++.h>
using namespace std;

int main(){
    int row, col;
    cin>>row>>col;

    int arr[row][col];

    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++)
            cin>>arr[i][j];
    }

    cout<<"Array Elements: "<<endl;
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++)
            cout<<arr[i][j]<<" ";
        cout<<"\n";
    }
    cout<<endl;

    int left = 0, right = col-1, top = 0, bottom = row-1;
    vector<int> spiralTraversal;
    while(left<=right && top<=bottom){
        for(int i=left;i<=right;i++){
            spiralTraversal.push_back(arr[top][i]);
            cout<<"pushed 1: "<<arr[top][i]<<"\n";
        }
        top++;

        for(int i=top;i<=bottom;i++){
            spiralTraversal.push_back(arr[i][right]);
            cout<<"pushed 2: "<<arr[i][right]<<"\n";
        }
        right--;

        if(top<=bottom){
            for(int i=right;i>=left;i--){
                spiralTraversal.push_back(arr[bottom][i]);
                cout<<"pushed 3: "<<arr[bottom][i]<<"\n";
            }
            bottom--;
        }

        if(left<=right){
            for(int i=bottom;i>=top;i--){
                cout<<"pushed 4: "<<arr[i][left]<<"\n";
                spiralTraversal.push_back(arr[i][left]);
            }
            left++;
        }
    }

    cout<<"Spiral Traversal of Matrix: "<<endl;
    for(int i=0;i<spiralTraversal.size();i++){
        cout<<spiralTraversal[i]<<" ";
    }
    cout<<endl;
 

    return 0;
}