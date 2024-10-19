#include <bits/stdc++.h>
using namespace std;

// GFG - https://www.geeksforgeeks.org/problems/edit-distance3702/1

int editDistance(string &str1, string &str2)
{
    int m = str1.size();
    int n = str2.size();
    int dp[m + 1][n + 1];
    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (i == 0) // for insertion operation as first string is empty so we need to insert all characters of second string so cost will be j operations as we need to insert j characters of second string to first string to make them equal so cost will be j operations so dp[i][j] = j for all j from 0 to n (second string length) so dp[0][j] = j for all j from 0 to n (second string length) so dp[0][j] = j for all j from 0 to n (second string length) 
            {
                dp[i][j] = j;
            }
            else if (j == 0) // for deletion 
            {
                dp[i][j] = i;
            }
            else if (str1[i - 1] == str2[j - 1])    // if characters are same then no operation required so copy the diagonal element value
            {
                dp[i][j] = dp[i - 1][j - 1];
            }
            else    // if characters are different then take minimum of insertion, deletion and replacement and add 1 to it as we are performing one operation so add 1 to it
            {
                dp[i][j] = min(dp[i - 1][j - 1], min(dp[i][j - 1], dp[i - 1][j])) + 1;
            }
        }
    }
    return dp[m][n];
}

int main()
{
    string str1, str2;
    cin >> str1 >> str2;

    cout << editDistance(str1, str2) << "\n";
    return 0;
}

// Testcase:
/*
1. geek gesek -> output: 1
2. gfg gfg -> output: 0
3. cat cut -> output: 1
4. saturday sunday -> output: 3
 */