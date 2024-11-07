#include<bits/stdc++.h>
using namespace std;

// Testcase:
// 3
// 1 2 5
// 13
// Output: 4

//* Greedy Algo
/* int main() {
    int n;  // number of coin denominations
    cin >> n;

    vector<int> coins(n);
    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }

    int rup; cin >> rup; // rupees to make out of these coins

    sort(coins.rbegin(), coins.rend()); // sort in descending order
    int minimumCoins = 0;

    for (int i = 0; i < n; i++) {
        while (rup >= coins[i]) {
            rup -= coins[i];
            minimumCoins++;
            // cout << "coin: " << coins[i] << "\n";
        }
    }

    if (rup == 0) {
        cout << "Min coins: " << minimumCoins << "\n";
    } else {
        cout << "Not possible\n";
    }

    return 0;
} */

//* DP Algo
/* int main() {
    int n;  // number of coin denominations
    cin >> n;

    vector<int> coins(n);
    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }

    int rup; cin >> rup; // rupees to make out of these coins

    vector<int> dp(rup + 1, INT_MAX);
    dp[0] = 0;

    for (int i = 1; i <= rup; i++) {
        for (int j = 0; j < n; j++) {
            if (coins[j] <= i) {
                int sub_res = dp[i - coins[j]];
                if (sub_res != INT_MAX) {
                    dp[i] = min(dp[i], sub_res + 1);
                }
            }
        }
    }

    if (dp[rup] == INT_MAX) {
        cout << "Not possible\n";
    } else {
        cout << "Min coins: " << dp[rup] << "\n";
    }

    return 0;
} */

//* DP Algo with 2D array
int main() {
    int n;  // number of coin denominations
    cin >> n;

    vector<int> coins(n);
    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }

    int rup; cin >> rup; // rupees to make out of these coins

    vector<vector<int>> dp(n + 1, vector<int>(rup + 1, INT_MAX));
    for (int i = 0; i <= n; i++) {
        dp[i][0] = 0;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= rup; j++) {
            if (coins[i - 1] <= j) {
                dp[i][j] = min(dp[i - 1][j], dp[i][j - coins[i - 1]] + 1);
            } else {
                dp[i][j] = dp[i - 1][j];
            }   
        }
    }

    if (dp[n][rup] == INT_MAX) {
        cout << "Not possible\n";
    } else {
        cout << "Min coins: " << dp[n][rup] << "\n";
    }

    return 0;
}