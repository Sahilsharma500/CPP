/*
    ✅ Problem: Longest Increasing Subsequence (LIS) — Return the actual subsequence
    🔍 Intuition:
    We want to find the longest strictly increasing subsequence in a given array.
    This solution builds `dp[]` where dp[i] stores the LIS length ending at index i,
    and `hash[]` to reconstruct the actual sequence.

    🧠 Approach:
    - Initialize dp[i] = 1 for all i (every element is a subsequence of length 1).
    - For each index i, iterate over all previous indices j < i and check:
        if arr[j] < arr[i], update dp[i] = max(dp[i], 1 + dp[j]).
    - Maintain a `hash[]` to backtrack and reconstruct the path.
    - At the end, find the index with the maximum dp value and use hash[] to build the LIS.

    🛠️ Time Complexity: O(n^2)
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
  public:
    vector<int> longestIncreasingSubsequence(int n, vector<int>& arr) {
        vector<int> dp(n, 1);  // dp[i] = length of LIS ending at index i
        vector<int> hash(n);   // hash[i] = previous index used to reach i in LIS
        
        for(int i = 0; i < n; i++) {
            hash[i] = i;  // initialize hash to point to itself
            for(int prev = 0; prev < i; prev++) {
                if(arr[prev] < arr[i] && dp[prev] + 1 > dp[i]) {
                    dp[i] = dp[prev] + 1;
                    hash[i] = prev;  // update path
                }
            }
        }

        // Find the index of the last element of the LIS
        int maxLen = -1;
        int lastIndex = -1;
        for(int i = 0; i < n; i++) {
            if(dp[i] > maxLen) {
                maxLen = dp[i];
                lastIndex = i;
            }
        }

        // Reconstruct LIS using hash[]
        vector<int> lis;
        lis.push_back(arr[lastIndex]);
        while(hash[lastIndex] != lastIndex) {
            lastIndex = hash[lastIndex];
            lis.push_back(arr[lastIndex]);
        }

        reverse(lis.begin(), lis.end());  // reverse to get correct order
        return lis;
    }
};
