#include<bits/stdc++.h>
using namespace std;

// *APPROACH 1
int main(){
    string s;
    cout<<"Enter string: ";
    cin>>s;

    int arr[26] = {0};
    int arrInd;
    for(int i=0;i<s.size();i++){
        arrInd = tolower(s[i]) - 'a';
        if(isalpha(s[i]))
            arr[arrInd] = 1;
    }

    for(int i=0;i<26;i++){
        if(arr[i]==0){
            cout<<char(i+'a');
        }
    }

    return 0;
}