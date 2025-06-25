#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

/*
Intuition:
-----------
This problem is about finding the **Longest Common Subsequence (LCS)** between two strings.
A subsequence is a sequence derived by deleting some or no elements without changing the order.
For example, LCS of "abcde" and "ace" is "ace" with length 3.

Approach:
----------
We use **Dynamic Programming (DP)** to solve this efficiently.
There are two approaches shown:
1. Top-down with memoization (recursive `solve` function)
2. Bottom-up tabulation (final implementation)

- `dp[i][j]` stores the LCS length between `s1[0...i-1]` and `s2[0...j-1]`
- If characters match: LCS includes that char → 1 + dp[i-1][j-1]
- If not: we skip one char from either string and take max of both options

Time Complexity: O(n * m)
Space Complexity: O(n * m)
*/

class Solution {
  public:
  
  // Recursive helper with memoization
  int solve(string& s1, string& s2, int i, int j, vector<vector<int>>& dp) {
    // Base case: if either index goes out of bounds, return 0
    if(i < 0 || j < 0) return 0;

    // Return memoized result if already computed
    if(dp[i][j] != -1) return dp[i][j];
    
    // If characters match, include it in LCS and move both indices back
    if(s1[i] == s2[j]){
        return dp[i][j] = 1 + solve(s1, s2, i-1, j-1, dp);
    } else {
        // Otherwise, try skipping a char from either string and take max
        return dp[i][j] = max(solve(s1, s2, i-1, j, dp), solve(s1, s2, i, j-1, dp));
    }
  }

  // Final LCS function using bottom-up DP
  int lcs(string &s1, string &s2) {
    int n = s1.length();
    int m = s2.length();

    // Initialize DP table with -1 for memoization (not used in tabulation)
    vector<vector<int>> dp(n+1, vector<int>(m+1, -1));

    // Base case: if any string is empty, LCS is 0
    for(int i = 0; i <= n; i++){
        dp[i][0] = 0;
    }
    for(int i = 0; i <= m; i++){
        dp[0][i] = 0;
    }

    // Build the table from smaller subproblems
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            // If current characters match, take diagonal +1
            if(s1[i-1] == s2[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
            } else {
                // Else, take max from skipping one char from either string
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }

    // Final answer is the LCS length of full strings
    return dp[n][m];
  }
};
