/*
-----------------------------------------------
🔍 Problem: Longest Palindromic Substring
Platform: LeetCode (Medium)
-----------------------------------------------

🧠 Intuition:
We need to find the longest substring of the given string that is a palindrome (reads the same forward and backward). 
Brute force would involve checking all substrings, which takes O(n^3). This is too slow.

⚙️ Optimization:
Instead of checking each substring repeatedly, we use memoization (Top-Down Dynamic Programming).
We define a function `isPalindrome(i, j)` that tells us whether the substring s[i..j] is a palindrome.
We store previously computed results in a DP table to avoid recomputation.

📌 Key Observations:
- A string is a palindrome if its outer characters match and its inner substring is also a palindrome.
- For each pair (i, j), we use this rule to decide if s[i..j] is a palindrome.

🧮 Time Complexity: O(n^2)
🧮 Space Complexity: O(n^2)

👨‍💻 Implementation Notes:
- We check every substring s[i..j] and memoize whether it's a palindrome.
- We update the max length and start index whenever we find a longer valid palindrome.

-----------------------------------------------
*/

#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    // Helper function to check if s[i..j] is a palindrome using memoization
    bool isPalindrome(string& s, int i, int j, vector<vector<int>>& dp) {
        if (i >= j) return true;  // Base case: one or zero characters is always palindrome
        if (dp[i][j] != -1) return dp[i][j];  // Use memoized result
        if (s[i] == s[j])
            return dp[i][j] = isPalindrome(s, i + 1, j - 1, dp);
        return dp[i][j] = false;
    }

    // Main function to return the longest palindromic substring
    string longestPalindrome(string s) {
        int n = s.size();
        int maxLen = 0, start = 0;
        vector<vector<int>> dp(n, vector<int>(n, -1)); // DP table for memoization

        // Try all substrings from index i to j
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                // Only check if current length is longer than previously found palindrome
                if ((j - i + 1 > maxLen) && isPalindrome(s, i, j, dp)) {
                    start = i;
                    maxLen = j - i + 1;
                }
            }
        }

        return s.substr(start, maxLen);
    }
};
