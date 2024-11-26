#include<bits/stdc++.h>
using namespace std;

// sliding window technique for lps
// TC: O(n+m) SC: O(m) where n is size of s1 and m is size of s2
int main(){
    string s1,s2;
    cin>>s1>>s2;

    int n = s2.size();
    int lps[n];
    lps[0] = 0;

    int j = 0, i = 1;
    while(i<n){                 // create LPS array
        if(s2[i] == s2[j]){   // characters match
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

    i = 0, j = 0;
    while(i<s1.size()){
        if(s1[i] == s2[j]){     // characters match
            i++;
            j++;
        }
        if(j == n){             // pattern found
            cout<<i-j<<" ";
            j = lps[j-1];
        }else if(i<s1.size() && s1[i] != s2[j]){  // characters don't match
            if(j!=0){       // if j is not at the start
                j = lps[j-1];
            }else{          // if j is at the start
                i++;
            }
        }
    }

    return 0;
}

/* 
Testcases:
Input: abcab ab
Output: 0 3

Input: aabaacaadaabaaba aaba
Output: 0 9 12

Input: aaaaaabcdaaazzzz aaabcdaa
Output: 0 0 1 0 1 2 3 0
 */