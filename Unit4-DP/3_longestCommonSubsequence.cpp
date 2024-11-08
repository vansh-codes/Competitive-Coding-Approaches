/* Find longest common subsequence
? str1 = "abcdaf" 
? str2 = "acbcf"
-> O/P: 4
 */

#include<bits/stdc++.h>
using namespace std;

int main(){
    string str1, str2;
    cin>>str1>>str2;
    int m = str1.size();
    int n = str2.size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (str1[i - 1] == str2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    cout << dp[m][n] << endl;

    return 0;
}

/* 
*EXPLANATION:

# INITIALIZATION
vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
- dp is a 2D vector (matrix) used for dynamic programming. It has dimensions (m+1) x (n+1), where m is the length of str1 and n is the length of str2.
- Each element dp[i][j] represents the length of the LCS of the substrings str1[0..i-1] and str2[0..j-1].
- The matrix is initialized with zeros.

# Filling the DP Table
for (int i = 1; i <= m; ++i) {
    for (int j = 1; j <= n; ++j) {
        if (str1[i - 1] == str2[j - 1]) {
            dp[i][j] = dp[i - 1][j - 1] + 1;
        } else {
            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
}
- The outer loop iterates over each character of str1 (from 1 to m).
- The inner loop iterates over each character of str2 (from 1 to n).

# Matching Characters
if (str1[i - 1] == str2[j - 1]) {
    dp[i][j] = dp[i - 1][j - 1] + 1;
}

- If the characters str1[i-1] and str2[j-1] match, it means the LCS can be extended by this matching character.
- Therefore, dp[i][j] is set to dp[i-1][j-1] + 1, indicating that the LCS length has increased by 1.

# Non-matching Characters
else {
    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
}

- If the characters do not match, the LCS length is the maximum of either:
    - The LCS length without the current character of str1 (dp[i-1][j]).
    - The LCS length without the current character of str2 (dp[i][j-1]).

# Output the result
cout << dp[m][n] << endl;

- Finally, the length of the LCS of str1 and str2 is stored in dp[m][n], which is printed out.

# Example:
Consider str1 = "abcde" and str2 = "ace". The DP table (dp) will be filled as follows:
    a c e
  0 0 0 0
a 0 1 1 1
b 0 1 1 1
c 0 1 2 2
d 0 1 2 2
e 0 1 2 3

- The LCS is "ace" with length 3, which is stored in dp[5][3].

# Summary
- The 2D DP table helps in storing intermediate results to avoid redundant calculations.
- The nested loops fill the table based on character matches and previous LCS lengths.
- The final LCS length is found at dp[m][n].
- This approach ensures an efficient solution with a time complexity of O(m * n).
 */