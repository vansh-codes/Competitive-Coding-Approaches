#include <bits/stdc++.h>
using namespace std;
//? 1: https://leetcode.com/problems/longest-palindromic-subsequence/
//? 2: https://www.geeksforgeeks.org/problems/longest-palindromic-subsequence-1612327878/1

// Testcases: bbbab -> 4, cbbd -> 2, bbabcbcab -> 7
int longestPalindromeSubsequence(string &s)
{
    vector<vector<int>> dp(s.size(), vector<int>(s.size()));
    for (int i = s.size() - 1; i >= 0; i--)
    {
        dp[i][i] = 1; // fill diagonal value with 1
        for (int j = i + 1; j < s.size(); j++)
        {
            if (s[i] == s[j])
            {
                dp[i][j] = dp[i + 1][j - 1] + 2;
            }
            else
            {
                dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp[0][s.size() - 1];
}

int main()
{
    string s;
    cin >> s;

    cout << longestPalindromeSubsequence(s) << endl;

    return 0;
}