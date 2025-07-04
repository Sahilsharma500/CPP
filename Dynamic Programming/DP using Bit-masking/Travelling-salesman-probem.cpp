// Problem: Traveling Salesman Problem using Bitmask DP
// Source: Typical DP Interview Question / GFG
// Approach: Bitmasking + Memoized Recursion (O(n*2^n))
// Description:
//   Given a cost matrix, find the minimum cost to visit all cities starting from city 0 and return back.

#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    // Recursive helper with memoization
    int rec(int ind, vector<vector<int>> &cost, int mask, vector<vector<int>> &dp) {
        int n = cost.size();
        mask = mask ^ (1 << ind);  // Unmark this city from the bitmask

        if (mask == 0)
            return cost[ind][0];  // Return to starting city

        if (dp[ind][mask] != -1)
            return dp[ind][mask];

        int ans = INT_MAX;

        for (int j = 0; j < n; j++) {
            if (mask & (1 << j)) {
                int temp = cost[ind][j] + rec(j, cost, mask, dp);
                ans = min(ans, temp);
            }
        }

        return dp[ind][mask] = ans;
    }

    int tsp(vector<vector<int>> cost) {
        int n = cost.size();
        int mask = (1 << n) - 1;
        vector<vector<int>> dp(n, vector<int>(mask + 1, -1));

        return rec(0, cost, mask, dp);
    }
};
