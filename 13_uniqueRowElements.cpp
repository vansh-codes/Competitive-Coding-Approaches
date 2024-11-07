//? Given a matrix, print al elements which are present in each row
//it contains non-unique elements

#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    cin>>n>>m;

    int arr[n][m];

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++)
            cin>>arr[i][j];
    }

    cout<<"Array Elements: "<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++)
            cout<<arr[i][j]<<" ";
        cout<<"\n";
    }
    cout<<endl;

    // BruteForce: TC O(m*n^2), SC O(n)
    /* vector<int> res;
    for(int i=0;i<n;i++){
        int el = arr[0][i], count=0;
        for(int j=1;j<m;j++){
            bool flag = false;
            for(int k=0;k<n;k++){
                if(arr[j][k]==el){
                    count++; flag = true;  arr[j][k]=INT_MAX; break;
                }
            }
            if(flag==false){
                break;
            }
        }
        if(count == m-1){
            res.push_back(el);
        }
    }

    cout<<"Repeating Elements: "<<endl;
    for(int i=0;i<res.size();i++){
        cout<<res[i]<<" ";
    }
    cout<<endl; */

    // Method2: Hashmap/UnorderedMap
    

    return 0;
}