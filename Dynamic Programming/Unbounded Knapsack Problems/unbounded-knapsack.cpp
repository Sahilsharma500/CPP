// Unbounded Knapsack Problem (Memoization + Tabulation)
// ------------------------------------------------------
// You are given weights and values of 'n' items and a knapsack of capacity 'W'.
// You can choose an item **as many times as you want** (unbounded).
//
// Goal: Maximize the total value without exceeding the knapsack capacity.
//
// Approaches:
// 1. Memoization (Top-Down DP)
//    - Use recursion with memo table.
//    - For every item, try taking it again (stay at the same index) or skip it.
//    - State: dp[ind][capacity]
// 2. Tabulation (Bottom-Up DP)
//    - Build the solution iteratively using a dp table.
//    - Use the same logic as memoization, but iteratively.
//
// Time Complexity: O(n * capacity)
// Space Complexity: O(n * capacity) for both approaches

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // ---------- Memoization (Top-Down DP) ----------
    int solveMemo(int ind, int capacity, vector<int>& val, vector<int>& wt, vector<vector<int>>& dp) {
        if (capacity == 0) return 0;
        if (ind < 0) return 0;

        if (dp[ind][capacity] != -1) return dp[ind][capacity];

        // Option 1: Don't take current item
        int notTake = solveMemo(ind - 1, capacity, val, wt, dp);

        // Option 2: Take current item (if it fits)
        int take = 0;
        if (wt[ind] <= capacity) {
            take = val[ind] + solveMemo(ind, capacity - wt[ind], val, wt, dp);
        }

        return dp[ind][capacity] = max(take, notTake);
    }

    int knapSackMemo(int capacity, vector<int>& val, vector<int>& wt) {
        int n = wt.size();
        vector<vector<int>> dp(n, vector<int>(capacity + 1, -1));
        return solveMemo(n - 1, capacity, val, wt, dp);
    }

    // ---------- Tabulation (Bottom-Up DP) ----------
    int knapSackTab(int capacity, vector<int>& val, vector<int>& wt) {
        int n = wt.size();
        vector<vector<int>> dp(n + 1, vector<int>(capacity + 1, 0));

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= capacity; j++) {
                int notTake = dp[i - 1][j];
                int take = 0;
                if (wt[i - 1] <= j) {
                    take = val[i - 1] + dp[i][j - wt[i - 1]];
                }
                dp[i][j] = max(take, notTake);
            }
        }

        return dp[n][capacity];
    }
};

// ---------- Sample Usage ----------
int main() {
    Solution sol;
    vector<int> val = {10, 40, 50, 70};
    vector<int> wt = {1, 3, 4, 5};
    int capacity = 8;

    cout << "Memoization Result: " << sol.knapSackMemo(capacity, val, wt) << endl;
    cout << "Tabulation Result: " << sol.knapSackTab(capacity, val, wt) << endl;

    return 0;
}
