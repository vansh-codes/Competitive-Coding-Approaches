#include<bits/stdc++.h>
using namespace std;

// *Check if two strings are anagram or not
bool checkAnagram(string s1, string s2){
    if(s1.size() != s2.size()) return false;

    int counter[26] = {0};
    for(int i=0;i<s1.size();i++){
        counter[s1[i]-'a']++;
    }

    for(int i=0;i<26;i++){
        cout<<counter[i]<<" ";
    }
    cout<<"\n";

    for(int i=0;i<s2.size();i++){
        counter[s2[i]-'a']--;
    }

    for(int i=0;i<26;i++){
        cout<<counter[i]<<" ";
    }
    cout<<"\n";

    int minDeletions = 0;
    for(int i=0;i<26;i++){
        if(counter[i]!=0){
            minDeletions+=abs(counter[i]);
        }
    }
    if(minDeletions!=0){
        cout<<"Minimum number of deletions to make strings anagram are: "<<minDeletions<<endl;
        return false;
    }

    return true;
}

int main(){
    string s1,s2;
    cout<<"Enter s1: "; cin>>s1;
    cout<<"Enter s2: "; cin>>s2;

    cout<<checkAnagram(s1,s2)<<endl;

    return 0;
}