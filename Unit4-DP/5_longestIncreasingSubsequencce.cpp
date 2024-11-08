#include <bits/stdc++.h>
using namespace std;

//? https://leetcode.com/problems/longest-increasing-subsequence/

//Testcases: [10,9,2,5,3,7,101,18] -> 4, [0,1,0,3,2,3] -> 4, [7,7,7,7,7,7,7] -> 1
int lengthOfLIS(vector<int> &nums)
{
    vector<int> dp(nums.size(), 1);
    int maxLIS = 1;
    for (int i = 1; i < nums.size(); i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (nums[i] > nums[j])
            {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        maxLIS = max(maxLIS, dp[i]);
    }
    return maxLIS;
}

int main()
{
    int n;
    cin >> n;

    vector<int> v(n);

    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    cout << lengthOfLIS(v) << "\n";

    return 0;
}