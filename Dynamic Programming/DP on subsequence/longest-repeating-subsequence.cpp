#include <iostream>
#include <vector>
#include <string>
using namespace std;

/*
──────────────────────────────────────────────────────────────
🔷 Longest Repeating Subsequence (LRS)
─────────────────────────────────────────────────────────────

📌 Problem:
Given a string `s`, return the length of the longest subsequence that appears **at least twice** in the string
but at **different positions** (i.e., no overlapping indices).

🧠 Intuition:
This is a classic variation of the Longest Common Subsequence (LCS) problem:
- You compare the string `s` with itself.
- But while matching characters, you ensure that **indices are not the same** (i ≠ j).
  This ensures you're not matching a character with itself.

🧮 Time Complexity: O(n²)
🧮 Space Complexity: O(n²)
*/

int LongestRepeatingSubsequence(string &s) {
    string t = s;
    int n = s.length();
    int m = t.length();

    // Create a 2D DP table
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    // Fill the DP table using LCS-like logic with i ≠ j
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (s[i - 1] == t[j - 1] && i != j) {
                // Match only if characters are same and indices are different
                dp[i][j] = 1 + dp[i - 1][j - 1];
            } else {
                // Take max from left or top
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    // The value at dp[n][m] contains the length of the longest repeating subsequence
    return dp[n][m];
}

/* Optional main for testing
int main() {
    string str = "aab";
    cout << "Length of Longest Repeating Subsequence: " << LongestRepeatingSubsequence(str) << endl;
    return 0;
}
*/
