#include<bits/stdc++.h>
using namespace std;

// sliding window technique
int main(){
    string s;
    cin>>s;

    int n = s.size();
    int lps[n];
    lps[0] = 0;

    int j = 0, i = 1;
    while(i<n){
        if(s[i] == s[j]){   // characters match
            j++;
            lps[i] = j;
            i++;
        }else{              // characters don't match
            if(j!=0){       // if j is not at the start
                j = lps[j-1];
            }else{          // if j is at the start
                lps[i] = 0;
                i++;
            }
        }
    }

    for(int i=0; i<n; i++){
        cout<<lps[i]<<" ";
    }

    return 0;
}

/* 
Testcases:
Input: bcbc
Output: 0 0 1 2

Input: aaabcdaa
Output: 0 1 2 0 0 0 1 2

Input: abacabad
Output: 0 0 1 0 1 2 3 0
 */