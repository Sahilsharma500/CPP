/*
------------------------------------------------------------
🔍 Problem: Minimum ASCII Delete Sum for Two Strings
Platform: LeetCode (Medium)
------------------------------------------------------------

📄 Problem Statement:
Given two strings `s1` and `s2`, return the minimum sum of ASCII values of characters 
that need to be deleted to make the two strings equal.

🧠 Intuition:
The goal is to transform both strings into the same string by deleting characters 
from either `s1` or `s2`, and we want to minimize the total ASCII value of the 
deleted characters.

This is similar to the **Edit Distance** problem, but we only allow deletions, 
and the cost of deletion is the ASCII value of the character.

⚙️ Approach:
We use **Top-Down Dynamic Programming (Memoization)**.
Let `dp[i][j]` represent the minimum ASCII delete sum required to make `s1[i:]` 
and `s2[j:]` equal.

- If characters match, no deletion is needed: 
    `dp[i][j] = dp[i+1][j+1]`
- If they don't match, we either delete from `s1` or `s2`:
    `dp[i][j] = min(s1[i] + dp[i+1][j], s2[j] + dp[i][j+1])`

Base cases:
- If `i == s1.length()`, delete all remaining characters in `s2`
- If `j == s2.length()`, delete all remaining characters in `s1`

🧮 Time Complexity: O(n * m)
🧮 Space Complexity: O(n * m)

------------------------------------------------------------
*/

#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    // Recursive helper function with memoization
    int solve(string& s1, string& s2, int i, int j, vector<vector<int>>& dp) {
        if (i >= s1.length() && j >= s2.length()) return 0;

        if (dp[i][j] != -1) return dp[i][j];

        if (i >= s1.length()) return s2[j] + solve(s1, s2, i, j + 1, dp);
        if (j >= s2.length()) return s1[i] + solve(s1, s2, i + 1, j, dp);

        if (s1[i] == s2[j]) {
            return dp[i][j] = solve(s1, s2, i + 1, j + 1, dp);
        } else {
            int delFromS1 = s1[i] + solve(s1, s2, i + 1, j, dp);
            int delFromS2 = s2[j] + solve(s1, s2, i, j + 1, dp);
            return dp[i][j] = min(delFromS1, delFromS2);
        }
    }

    // Main function to compute minimum delete sum
    int minimumDeleteSum(string s1, string s2) {
        int n = s1.length();
        int m = s2.length();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));

        return solve(s1, s2, 0, 0, dp);
    }
};
