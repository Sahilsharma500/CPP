#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
using namespace std;

/*
────────────────────────────────────────────────────────────────────────────
🔷 FILE: All LCS Variants - Single and All Longest Common Subsequences
────────────────────────────────────────────────────────────────────────────

📌 Description:
This file contains two different implementations for finding the Longest Common Subsequence (LCS)
between two given strings `s` and `t`.

1️⃣ OneLCS:
    - Prints just one valid LCS string.
    - Uses standard DP with bottom-up reconstruction.

2️⃣ AllLCS:
    - Prints all unique LCS strings.
    - Uses DP + backtracking to explore all paths that form an LCS.

📈 Time Complexity:
    - DP Table construction: O(n * m)
    - Backtracking (in AllLCS): Can be exponential in worst case.

────────────────────────────────────────────────────────────────────────────
*/

/*─────────────────────────────────────────────────────────────
  🔸 1. Function to Print One LCS
─────────────────────────────────────────────────────────────*/
vector<string> oneLCS(string s, string t) {
    int n = s.length();
    int m = t.length();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    // Fill DP table for LCS length
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (s[i - 1] == t[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    // Backtrack to get one LCS
    int i = n, j = m;
    string ans = "";
    while (i > 0 && j > 0) {
        if (s[i - 1] == t[j - 1]) {
            ans.push_back(s[i - 1]);
            i--;
            j--;
        } else if (dp[i - 1][j] > dp[i][j - 1]) {
            i--;
        } else {
            j--;
        }
    }

    reverse(ans.begin(), ans.end());
    return {ans};  // return as vector for consistency
}

/*─────────────────────────────────────────────────────────────
  🔸 2. Function to Print All LCS
─────────────────────────────────────────────────────────────*/
void backtrack(int i, int j, string &s, string &t, vector<vector<int>> &dp, string &path, set<string> &result) {
    // Base case: either string is exhausted
    if (i == 0 || j == 0) {
        string rev = path;
        reverse(rev.begin(), rev.end());
        result.insert(rev); // add result
        return;
    }

    if (s[i - 1] == t[j - 1]) {
        // If chars match, move diagonally and append to path
        path.push_back(s[i - 1]);
        backtrack(i - 1, j - 1, s, t, dp, path, result);
        path.pop_back(); // backtrack
    } else {
        // Explore all directions that give same LCS length
        if (dp[i - 1][j] == dp[i][j])
            backtrack(i - 1, j, s, t, dp, path, result);
        if (dp[i][j - 1] == dp[i][j])
            backtrack(i, j - 1, s, t, dp, path, result);
    }
}

vector<string> allLCS(string s, string t) {
    int n = s.length();
    int m = t.length();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    // Fill DP table
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (s[i - 1] == t[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    set<string> result;
    string path = "";
    backtrack(n, m, s, t, dp, path, result);

    return vector<string>(result.begin(), result.end());
}

/*─────────────────────────────────────────────────────────────
🔸 Optional: Driver Code for Testing (Uncomment to Use)
─────────────────────────────────────────────────────────────*/
/*
int main() {
    string s = "abcabcaa";
    string t = "acbacba";

    cout << "🔹 One LCS:\n";
    vector<string> one = oneLCS(s, t);
    for (const auto &str : one) {
        cout << str << endl;
    }

    cout << "\n🔹 All LCS:\n";
    vector<string> all = allLCS(s, t);
    for (const auto &str : all) {
        cout << str << endl;
    }

    return 0;
}
*/

