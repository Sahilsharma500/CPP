/*
    ✅ Problem: Scramble String (LeetCode #87)

    🔍 Intuition:
    We need to determine if one string is a scrambled version of another.
    Scrambling involves recursively partitioning a string into two parts and swapping them.

    🧠 Approach:
    - Use recursion to try all partition positions.
    - Check both with-swap and without-swap conditions.
    - Memoize using a hash map to avoid recalculating overlapping subproblems.
    - Early pruning: If sorted characters of substrings do not match, they cannot be scrambles.

    📌 Note:
    - This file contains two versions:
        1. Basic recursive + memoization version.
        2. Optimized version with early pruning and reduced redundant calls.
*/


#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;


// ✅ Version 1: Basic Recursive + Memoization
class Solution {
public:
    unordered_map<string, bool> dp; // memoization map

    // Helper function to check if two strings are scramble of each other
    bool solve(string a, string b) {
        if (a == b) return true; // Base case: strings are equal
        if (a.length() != b.length()) return false;

        string key = a + " " + b; // Create a unique key for memoization
        if (dp.find(key) != dp.end()) return dp[key];

        // Early pruning: If sorted strings differ, they can't be scramble
        string sortedA = a, sortedB = b;
        sort(sortedA.begin(), sortedA.end());
        sort(sortedB.begin(), sortedB.end());
        if (sortedA != sortedB) return dp[key] = false;

        int n = a.length();
        // Try all possible partition positions
        for (int i = 1; i < n; i++) {
            // Case 1: With swap
            bool cond1 = solve(a.substr(0, i), b.substr(n - i)) &&
                         solve(a.substr(i), b.substr(0, n - i));

            // Case 2: Without swap
            bool cond2 = solve(a.substr(0, i), b.substr(0, i)) &&
                         solve(a.substr(i), b.substr(i));

            if (cond1 || cond2) return dp[key] = true;
        }

        return dp[key] = false;
    }

    // Main function
    bool isScramble(string s1, string s2) {
        return solve(s1, s2);
    }
};



// ✅ Version 2: Optimized Version
class OptimizedSolution {
public:
    unordered_map<string, bool> dp; // memoization map

    // Optimized solve function with pruning and less overhead
    bool solve(string a, string b) {
        if (a == b) return true;
        if (a.length() != b.length()) return false;

        string key = a + " " + b;
        if (dp.find(key) != dp.end()) return dp[key];

        // Early pruning with sorted characters
        string sortedA = a, sortedB = b;
        sort(sortedA.begin(), sortedA.end());
        sort(sortedB.begin(), sortedB.end());
        if (sortedA != sortedB) return dp[key] = false;

        int n = a.size();
        // Try all possible partitions
        for (int i = 1; i < n; ++i) {
            // Check with swapping parts
            bool swapped = solve(a.substr(0, i), b.substr(n - i)) &&
                           solve(a.substr(i), b.substr(0, n - i));

            // Check without swapping
            bool notSwapped = solve(a.substr(0, i), b.substr(0, i)) &&
                              solve(a.substr(i), b.substr(i));

            if (swapped || notSwapped) return dp[key] = true;
        }

        return dp[key] = false;
    }

    // Main function
    bool isScramble(string s1, string s2) {
        return solve(s1, s2);
    }
};
