/*
    ✅ Problem: Number of Longest Increasing Subsequences (Leetcode #673)

    🔍 Intuition:
    We want to count how many distinct subsequences exist in the array that have the longest increasing subsequence (LIS) length.

    🧠 Approach:
    - Use two arrays:
        1. `dp[i]`: length of LIS ending at index i
        2. `count[i]`: number of LIS ending at index i
    - For each pair (j, i), where j < i:
        - If nums[i] > nums[j], we can extend the LIS ending at j to i.
            - If dp[j] + 1 > dp[i], we update dp[i] and reset count[i] = count[j]
            - If dp[j] + 1 == dp[i], it means another LIS path reached i, so we add count[j] to count[i]
    - After building dp and count arrays, sum all count[i] where dp[i] is the maximum length found.

    🛠️ Time Complexity: O(n^2)
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;

        vector<int> dp(n, 1);     // dp[i] = length of LIS ending at i
        vector<int> count(n, 1);  // count[i] = number of LIS ending at i
        int maxLen = 1;

        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j]) {
                    if (dp[j] + 1 > dp[i]) {
                        dp[i] = dp[j] + 1;
                        count[i] = count[j]; // new longer LIS
                    } else if (dp[j] + 1 == dp[i]) {
                        count[i] += count[j]; // another path to same length LIS
                    }
                }
            }
            maxLen = max(maxLen, dp[i]); // track max LIS length
        }

        int total = 0;
        for (int i = 0; i < n; i++) {
            if (dp[i] == maxLen)
                total += count[i]; // add all counts that have LIS of max length
        }

        return total;
    }
};
