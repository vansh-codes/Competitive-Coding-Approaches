#include<bits/stdc++.h>
using namespace std;


/* 
Time Complexity: O(n)
Space Complexity: O(n) 
*/
int main(){
    int n;
    cin>>n;     // no. of childrens

    vector<int> ratings(n);
    for(int i=0;i<n;i++){
        cin>>ratings[i];   // rating of that children
    }

    vector<int> candies(n,1);   // each children gets atleast 1 candy

    // left pass
    for(int i=1;i<n;i++){
        if(ratings[i]>ratings[i-1]){
            candies[i]=candies[i-1]+1;
        }
    }

    // right pass
    for(int i=n-2;i>=0;i--){
        if(ratings[i]>ratings[i+1]){
            if(candies[i]>candies[i+1]){
                continue;
            }
            candies[i]=candies[i+1]+1;
        }
    }

    // print the candies
    cout << "Candies: ";
    for(int i=0;i<n;i++){
        cout<<candies[i]<<" ";
    }
    cout<<"\n";

    // print the total candies
    int totalCandies=0;
    for(int i=0;i<n;i++){
        totalCandies+=candies[i];
    }
    cout<<"Minimum total candies :"<<totalCandies<<"\n";

    return 0;
}