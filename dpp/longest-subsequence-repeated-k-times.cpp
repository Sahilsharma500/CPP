#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <algorithm>
using namespace std;

/*
───────────────────────────────────────────────────────────────
🔷 Problem: Longest Subsequence Repeated K Times
───────────────────────────────────────────────────────────────

📌 Task:
Given a string `s` and an integer `k`, find the **longest possible string `x`** such that:
- `x` repeated `k` times is a subsequence of `s`
- Among all such strings, return the lexicographically largest one.

───────────────────────────────────────────────────────────────
🧠 Approach (Version 1 - Basic DFS + Frequency Pruning):

1. Count frequency of each character in `s`
2. Only consider characters whose count is at least `k`
3. Try all possible combinations of those characters using DFS (brute-force)
4. For each built string `curr`, check if `curr` repeated `k` times is a subsequence of `s`
5. Use a global `result` to track the best string found

🚫 Drawback:
- This version does **not use memoization**, so repeated states may be recomputed
- It also does not prune based on lexicographical order, which can be costly

───────────────────────────────────────────────────────────────
*/

class Solution_V1 {
public:
    string result = "";

    bool isSubsequence(string s, string curr, int k) {
        int L = curr.length();
        int n = s.length();
        int i = 0, j = 0;
        while (i < n && j < L * k) {
            if (s[i] == curr[j % L]) j++;
            i++;
        }
        return j == L * k;
    }

    void solve(string s, vector<bool>& canUse, vector<int>& mainfreq, int k, string curr) {
        if (curr.length() > s.length() / k) return;

        if ((curr.length() > result.length() || (curr.length() == result.length() && curr > result)) &&
            isSubsequence(s, curr, k)) {
            result = curr;
        }

        for (int i = 0; i < 26; i++) {
            if (!canUse[i] || mainfreq[i] == 0) continue;

            char c = i + 'a';
            curr.push_back(c);
            mainfreq[i]--;

            solve(s, canUse, mainfreq, k, curr);

            curr.pop_back();
            mainfreq[i]++;
        }
    }

    string longestSubsequenceRepeatedK(string s, int k) {
        int n = s.length();
        vector<int> freq(26, 0);
        for (char c : s) freq[c - 'a']++;

        vector<bool> canUse(26, false);
        vector<int> mainfreq(26, 0);
        for (int i = 0; i < 26; i++) {
            if (freq[i] >= k) {
                canUse[i] = true;
                mainfreq[i] = freq[i] / k;
            }
        }

        solve(s, canUse, mainfreq, k, "");
        return result;
    }
};

/*
───────────────────────────────────────────────────────────────
🧠 Approach (Version 2 - Optimized DFS + Lexicographical & Memo Pruning):

✅ Improvements over Version 1:
1. 🔁 **Memoization** using a `unordered_set<string>` to avoid recomputing the same `curr` string
2. 🅰️ **Lexicographical ordering**: tries characters from `'z'` to `'a'` to prioritize larger strings
3. 🧠 More pruning via `visited` set => fewer DFS calls

🔁 Result: Faster and cleaner traversal with the same correctness
───────────────────────────────────────────────────────────────
*/

class Solution_V2 {
public:
    string result = "";

    bool isSubsequence(string &s, string &curr, int k) {
        int L = curr.length(), n = s.length();
        int i = 0, j = 0;
        while (i < n && j < L * k) {
            if (s[i] == curr[j % L]) j++;
            i++;
        }
        return j == L * k;
    }

    void solve(string &s, vector<bool> &canUse, vector<int> &mainfreq, int k, string &curr, unordered_set<string> &visited) {
        if (visited.count(curr)) return;
        visited.insert(curr);

        if (curr.length() > s.length() / k) return;

        if ((curr.length() > result.length() ||
             (curr.length() == result.length() && curr > result)) &&
            isSubsequence(s, curr, k)) {
            result = curr;
        }

        for (int i = 25; i >= 0; --i) {
            if (!canUse[i] || mainfreq[i] == 0) continue;

            char c = 'a' + i;
            curr.push_back(c);
            mainfreq[i]--;

            solve(s, canUse, mainfreq, k, curr, visited);

            curr.pop_back();
            mainfreq[i]++;
        }
    }

    string longestSubsequenceRepeatedK(string s, int k) {
        int n = s.length();
        vector<int> freq(26, 0);
        for (char c : s) freq[c - 'a']++;

        vector<bool> canUse(26, false);
        vector<int> mainfreq(26, 0);
        for (int i = 0; i < 26; i++) {
            if (freq[i] >= k) {
                canUse[i] = true;
                mainfreq[i] = freq[i] / k;
            }
        }

        unordered_set<string> visited;
        string curr = "";
        solve(s, canUse, mainfreq, k, curr, visited);
        return result;
    }
};

/* Optional main to test both versions
int main() {
    Solution_V1 sol1;
    Solution_V2 sol2;
    string s = "letsleetcode";
    int k = 2;

    cout << "Version 1: " << sol1.longestSubsequenceRepeatedK(s, k) << endl;
    cout << "Version 2 (Optimized): " << sol2.longestSubsequenceRepeatedK(s, k) << endl;

    return 0;
}
*/
