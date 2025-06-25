// Coin Change Problem (Memoization + Tabulation)
// ----------------------------------------------
// Problem: Given an array of coin denominations and a target amount,
// return the minimum number of coins needed to make the amount.
// You can use a coin **unlimited times**.
//
// If it's not possible to form the amount, return -1.
//
// Approaches:
// 1. Memoization (Top-Down DP)
//    - Try all coins from current index to reduce the amount.
//    - Either pick the coin (stay at same index) or skip it.
// 2. Tabulation (Bottom-Up DP)
//    - dp[i][j] = min coins to make amount 'j' using first 'i' coins.
//
// Time Complexity: O(n * amount)
// Space Complexity: O(n * amount)

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    // ----------- Memoization (Top-Down DP) -----------
    int solveMemo(vector<int>& coins, int ind, int amount, vector<vector<int>>& dp) {
        if (amount == 0) return 0;
        if (ind < 0) return 1e9; // Impossible case

        if (dp[ind][amount] != -1) return dp[ind][amount];

        int take = 1e9;
        if (amount >= coins[ind]) {
            take = 1 + solveMemo(coins, ind, amount - coins[ind], dp); // Take same coin
        }

        int notTake = solveMemo(coins, ind - 1, amount, dp); // Skip coin
        return dp[ind][amount] = min(take, notTake);
    }

    int coinChangeMemo(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
        int result = solveMemo(coins, n - 1, amount, dp);
        return result == 1e9 ? -1 : result;
    }

    // ----------- Tabulation (Bottom-Up DP) -----------
    int coinChangeTab(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n + 1, vector<int>(amount + 1, 1e9));

        // Base case: amount = 0 → 0 coins needed
        for (int i = 0; i <= n; i++) {
            dp[i][0] = 0;
        }

        // Build dp table
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= amount; j++) {
                int take = 1e9;
                if (j >= coins[i - 1]) {
                    take = 1 + dp[i][j - coins[i - 1]]; // Take same coin again
                }
                int notTake = dp[i - 1][j]; // Skip this coin
                dp[i][j] = min(take, notTake);
            }
        }

        return dp[n][amount] == 1e9 ? -1 : dp[n][amount];
    }
};

// ----------- Sample Usage -----------
int main() {
    Solution sol;
    vector<int> coins = {1, 2, 5};
    int amount = 11;

    cout << "Memoization Result: " << sol.coinChangeMemo(coins, amount) << endl;
    cout << "Tabulation Result: " << sol.coinChangeTab(coins, amount) << endl;

    return 0;
}
