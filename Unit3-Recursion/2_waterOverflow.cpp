// GFG Link: https://www.geeksforgeeks.org/problems/champagne-overflow2636/1

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:

    double waterOverflow(int K, int R, int C) {
    vector<vector<double>> dp(100, vector<double>(100,0.0));
        dp[0][0] = K;
        for (int i = 0; i < R; i++) {
            for (int j = 0; j <= i; j++) {
                if (dp[i][j] > 1.0) {
                    double excess = dp[i][j] - 1.0;
                    if (i + 1 < 100) {
                        dp[i + 1][j] += excess / 2.0;
                        dp[i + 1][j + 1] += excess / 2.0;
                    }
                }
            }
        }
        return dp[R -1][C -1] >= 1.0 ? 1.0 : dp[R -1][C -1];
    }
};

int main()
{
    int k, r, c;
    cin >> k >> r >> c;

    Solution obj;
    cout << fixed << setprecision(6) << obj.waterOverflow(k, r, c) << endl;

    return 0;
}