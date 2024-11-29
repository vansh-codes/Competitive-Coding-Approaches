//?
// psuedo code
bool isSubsetSum(vector<int> &arr, int target)
{
    int n = arr.size();
    vector<vector<bool>> dp(n, vector<bool>(target + 1, false));
    for (int i = 0; i < n; i++)
    {
        dp[i][0] = true;
    }
    dp[0][arr[0]] = true;
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j <= target; j++)
        {
            dp[i][j] = dp[i - 1][j];
            if (j >= arr[i] && dp[i - 1][j - arr[i]])
            {
                dp[i][j] = true;
            }
        }
    }
    return dp[n - 1][target];
}