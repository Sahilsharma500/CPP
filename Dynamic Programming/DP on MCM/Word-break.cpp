/*
------------------------------------------------------------
🔍 Problem: Word Break
Platform: LeetCode (Medium)
------------------------------------------------------------

📄 Problem Statement:
Given a string `s` and a dictionary of strings `wordDict`, 
determine if `s` can be segmented into a space-separated 
sequence of one or more dictionary words.

🧠 Intuition:
We can treat this problem as a recursive partitioning problem:
At each index, we try to break the string into two parts and 
check whether both parts can be formed using words from the dictionary.
This naturally leads to recursion.

⚙️ Approach:
- Use recursion with memoization (Top-Down DP) to avoid recomputation.
- We use a helper function `solve(s, i, j)` that checks if the substring 
  `s[i..j]` can be broken down into valid words.
- We also keep a hash set (`unordered_set`) for O(1) dictionary lookup.

🧮 Time Complexity: O(n^3)
- O(n^2) substrings and each substring operation takes O(n) in worst case.

🧮 Space Complexity: O(n^2) for DP + O(n) recursion stack

📌 Edge Case:
We directly check if the whole string is in the dictionary — if yes, return true.

------------------------------------------------------------
*/

#include <vector>
#include <string>
#include <unordered_set>
using namespace std;

class Solution {
public:
    // Recursive helper function to check if s[i..j] can be segmented
    bool solve(string& s, int i, int j, unordered_set<string>& st, vector<vector<int>>& dp) {
        if (i > j) return true;

        if (dp[i][j] != -1) return dp[i][j];

        string temp = s.substr(i, j - i + 1);
        if (st.find(temp) != st.end()) return dp[i][j] = true;

        for (int k = i + 1; k <= j; k++) {
            if (solve(s, i, k - 1, st, dp) && solve(s, k, j, st, dp)) {
                return dp[i][j] = true;
            }
        }

        return dp[i][j] = false;
    }

    // Main function to check if the word can be segmented
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.length();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        unordered_set<string> st(wordDict.begin(), wordDict.end());

        if (st.find(s) != st.end()) return true;

        return solve(s, 0, n - 1, st, dp);
    }
};
