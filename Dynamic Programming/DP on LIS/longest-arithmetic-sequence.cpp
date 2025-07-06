/******************************************************************************
🔍 Problem: Longest Arithmetic Subsequence
Platform: LeetCode
Link: https://leetcode.com/problems/longest-arithmetic-subsequence/

🧾 Problem Statement:
Given an array `nums`, return the length of the longest subsequence of `nums` 
such that the difference between every two consecutive elements is the same.

===============================================================================
🧠 Approach 1: Tabulation (Bottom-Up DP with HashMaps)
===============================================================================
We define:
  dp[i][diff] = the length of the longest arithmetic subsequence ending at index i 
                with common difference = diff

We loop through each pair of indices (j < i), compute the difference (diff),
and update dp[i][diff] based on dp[j][diff].

This is preferred because we avoid recursion and stack overhead.

Time Complexity: O(N^2)
Space Complexity: O(N * D), where D is the number of unique differences

/******************************************************************************
🧩 Why vector<unordered_map<int, int>>?
Each index i may have multiple differences leading to it.

So for each i, we want to map diff → length.

Using a map allows us to efficiently:

Insert new differences

Extend existing sequences

If we used a 2D array like dp[i][diff], then we'd have to:

Handle negative diffs

Set up large arrays for all possible diff values (up to 2000 range)

➡️ Using unordered_map solves this cleanly and efficiently.
******************************************************************************/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        int n = nums.size();
        if(n <= 2) return n;

        // dp[i][diff] stores the length of the longest arithmetic subsequence ending at i with difference diff
        vector<unordered_map<int, int>> dp(n);
        int ans = 0;

        for(int i = 1; i < n; i++) {
            for(int j = 0; j < i; j++) {
                int diff = nums[i] - nums[j];

                // either extend the sequence from j or start a new one
                int length = dp[j].count(diff) ? dp[j][diff] + 1 : 2;

                dp[i][diff] = length;
                ans = max(ans, dp[i][diff]);
            }
        }

        return ans;
    }
};

/******************************************************************************
🧠 Approach 2: Memoization (Top-Down Recursion + Memoization)
===============================================================================
We define a recursive function:
  solve(index, diff) = max length of arithmetic subsequence ending at index with difference diff

This explores all valid pairs backward and stores results in a dp table.

Time Complexity: O(N^2)
Space Complexity: O(N * D)
******************************************************************************/

class SolutionMemo {
public:
    int solve(int index, int diff, vector<int>& nums, vector<unordered_map<int, int>>& dp) {
        if(index < 0) return 0;

        if(dp[index].count(diff)) return dp[index][diff];

        int ans = 0;
        for(int j = index - 1; j >= 0; j--) {
            if(nums[index] - nums[j] == diff) {
                ans = max(ans, 1 + solve(j, diff, nums, dp));
            }
        }

        return dp[index][diff] = ans;
    }

    int longestArithSeqLength(vector<int>& nums) {
        int n = nums.size();
        if(n <= 2) return n;

        vector<unordered_map<int, int>> dp(n);
        int ans = 0;

        for(int i = 1; i < n; i++) {
            for(int j = 0; j < i; j++) {
                int diff = nums[i] - nums[j];
                int currLength = 2 + solve(j, diff, nums, dp);
                ans = max(ans, currLength);
            }
        }

        return ans;
    }
};
