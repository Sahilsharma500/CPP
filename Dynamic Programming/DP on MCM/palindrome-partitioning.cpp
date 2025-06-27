#include <iostream>
#include <vector>
#include <string>
using namespace std;

/*
───────────────────────────────────────────────────────────────
🔷 Palindrome Partitioning – Optimized Version
───────────────────────────────────────────────────────────────

📌 Problem:
Given a string `s`, partition it into the minimum number of cuts such that every substring is a palindrome.

🧠 Optimized Intuition:
We use two levels of memoization:
1. `dp[i][j]` to store minimum cuts needed from index i to j.
2. `palMemo[i][j]` to remember if the substring s[i..j] is a palindrome.

This avoids rechecking the same palindrome substrings repeatedly.

🧮 Time Complexity: O(n³)
🧮 Space Complexity: O(n²)
*/

// ✅ Check if s[i..j] is a palindrome using memoization
bool checkPalindrome(string &s, int i, int j, vector<vector<int>> &palMemo) {
    if (i >= j) return true;
    if (palMemo[i][j] != -1) return palMemo[i][j];

    if (s[i] == s[j])
        return palMemo[i][j] = checkPalindrome(s, i + 1, j - 1, palMemo);

    return palMemo[i][j] = 0;
}

// ✅ Recursive function to find min cuts using DP and palindrome memo
int solve(string &s, int i, int j, vector<vector<int>> &dp, vector<vector<int>> &palMemo) {
    if (i >= j) return 0;
    if (checkPalindrome(s, i, j, palMemo)) return 0;

    if (dp[i][j] != -1) return dp[i][j];

    int ans = 1e9;
    for (int k = i; k < j; k++) {
        // Only cut if left part is a palindrome
        if (checkPalindrome(s, i, k, palMemo)) {
            int right = solve(s, k + 1, j, dp, palMemo);
            ans = min(ans, 1 + right);
        }
    }

    return dp[i][j] = ans;
}

// 🔧 Main function to initiate everything
int palPartition(string &s) {
    int n = s.length();
    vector<vector<int>> dp(n, vector<int>(n, -1));        // DP for min cuts
    vector<vector<int>> palMemo(n, vector<int>(n, -1));   // Palindrome memo table
    return solve(s, 0, n - 1, dp, palMemo);
}

/* Optional main for testing
int main() {
    string s = "aab";
    cout << "Minimum Palindrome Cuts: " << palPartition(s) << endl;
    return 0;
}
*/
