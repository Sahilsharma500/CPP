#include <iostream>
#include <vector>
#include <string>
using namespace std;

/*
─────────────────────────────────────────────────────────────────────
🔷 Shortest Common Supersequence Length (SCS)
─────────────────────────────────────────────────────────────────────

📌 Problem:
Given two strings `s1` and `s2`, find the length of their **shortest common supersequence** (SCS).
A supersequence of two strings contains both `s1` and `s2` as subsequences.

🧠 Intuition:
We use the formula:
    Length of SCS = Length of s1 + Length of s2 - Length of LCS(s1, s2)

Why?
- LCS represents the common part that we don't need to repeat.
- So, we can merge s1 and s2 by just appending their non-LCS parts to the LCS.

🧮 Time Complexity: O(n * m)
🧮 Space Complexity: O(n * m)
*/

class Solution {
  public:
    // Function to find length of shortest common supersequence of two strings.
    int shortestCommonSupersequence(string &s1, string &s2) {
        int n = s1.length();
        int m = s2.length();

        // Step 1: Compute LCS length
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (s1[i - 1] == s2[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        // Step 2: Use formula to find SCS length
        int lcsLength = dp[n][m];
        return n + m - lcsLength;
    }
};

/* Optional main function for testing
int main() {
    Solution sol;
    string s1 = "abac";
    string s2 = "cab";

    int scsLength = sol.shortestCommonSupersequence(s1, s2);
    cout << "Length of Shortest Common Supersequence: " << scsLength << endl;

    return 0;
}
*/
