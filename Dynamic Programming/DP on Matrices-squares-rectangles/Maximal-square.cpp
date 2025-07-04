/*
    ✅ Problem: Maximal Square (Leetcode #221)

    🔍 Intuition:
    Given a binary matrix, we want to find the largest square consisting only of 1's and return its area.
    The square must be contiguous, and its sides must be aligned with the grid.

    🧠 Approach (Top-Down DP with Memoization):
    - Define a recursive function `solve(i, j)` which returns the size of the largest square starting at cell (i, j).
    - For each cell (i, j):
        - If it contains '1', it can be the top-left of a square.
        - The size of the square will depend on the right, bottom, and diagonal values.
        - Recurrence: `1 + min(right, down, diagonal)`
    - We use memoization with `dp[i][j]` to store already computed results.
    - Update `maxi` with the maximum square size found during recursion.

    🛠️ Time Complexity: O(n * m)
    🧮 Space Complexity: O(n * m) for dp table + recursion stack
*/

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    // Recursive helper to compute largest square from position (i, j)
    int solve(vector<vector<char>>& matrix, int i, int j, vector<vector<int>>& dp, int& maxi) {
        // Base case: out of bounds
        if (i >= matrix.size() || j >= matrix[0].size()) return 0;

        // Return cached result
        if (dp[i][j] != -1) return dp[i][j];

        // Recursive calls for right, down, and diagonal cells
        int right = solve(matrix, i, j + 1, dp, maxi);
        int down = solve(matrix, i + 1, j, dp, maxi);
        int diag = solve(matrix, i + 1, j + 1, dp, maxi);

        int ans = 0;
        // If current cell is '1', compute square size
        if (matrix[i][j] == '1') {
            ans = 1 + min({right, down, diag}); // take min of 3 directions
            maxi = max(maxi, ans);              // update global maximum
        }

        return dp[i][j] = ans; // memoize and return
    }

    // Main function to compute the area of the largest square
    int maximalSquare(vector<vector<char>>& matrix) {
        int n = matrix.size();     // number of rows
        int m = matrix[0].size();  // number of columns
        vector<vector<int>> dp(n, vector<int>(m, -1)); // DP table
        int maxi = 0; // to track largest square size

        solve(matrix, 0, 0, dp, maxi); // initiate recursion from top-left
        return maxi * maxi; // return area (size squared)
    }
};
