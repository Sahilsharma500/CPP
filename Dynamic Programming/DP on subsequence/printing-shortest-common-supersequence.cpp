#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

/*
───────────────────────────────────────────────────────────────
🔷 Shortest Common Supersequence (SCS) - Actual String
───────────────────────────────────────────────────────────────

📌 Problem:
Given two strings `s1` and `s2`, return the actual string which is
the **shortest common supersequence (SCS)** of the two.

A supersequence of two strings is a string that contains both as subsequences.

🧠 Intuition:
- We first compute the Longest Common Subsequence (LCS) using dynamic programming.
- Then we backtrack through the DP table to **build the SCS string**:
  - If characters match, include once and move diagonally.
  - If not, include the character from the string that gave the larger LCS value and move accordingly.
  - After one string is exhausted, append the remaining characters of the other.

🧮 Time Complexity: O(n * m)
🧮 Space Complexity: O(n * m)

*/

string shortestCommonSupersequence(string s1, string s2) {
    int n = s1.size();
    int m = s2.size();

    // Step 1: Build LCS DP table
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (s1[i - 1] == s2[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    // Step 2: Backtrack to build the SCS string
    int i = n, j = m;
    string ans = "";

    while (i > 0 && j > 0) {
        if (s1[i - 1] == s2[j - 1]) {
            ans += s1[i - 1]; // Common character, add once
            i--, j--;
        } else if (dp[i - 1][j] > dp[i][j - 1]) {
            ans += s1[i - 1]; // Take from s1
            i--;
        } else {
            ans += s2[j - 1]; // Take from s2
            j--;
        }
    }

    // Add remaining characters (if any)
    while (i > 0) {
        ans += s1[i - 1];
        i--;
    }
    while (j > 0) {
        ans += s2[j - 1];
        j--;
    }

    // Reverse the result because we built it backwards
    reverse(ans.begin(), ans.end());
    return ans;
}

/* Optional main for testing
int main() {
    string s1 = "abac";
    string s2 = "cab";
    string scs = shortestCommonSupersequence(s1, s2);
    cout << "Shortest Common Supersequence: " << scs << endl;
    return 0;
}
*/
