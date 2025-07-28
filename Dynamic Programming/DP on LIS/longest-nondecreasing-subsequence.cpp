// Problem: Longest Obstacle Course at Each Position
// Platform: LeetCode
// Difficulty: Hard
// Constraints: 
// - 1 <= obstacles.length <= 1e5
// - 1 <= obstacles[i] <= 1e7
//
// 🧠 Intuition:
// For each obstacle[i], we want to know the length of the **longest non-decreasing subsequence** ending at that index.
// This is similar to the Longest Increasing Subsequence (LIS) problem, but with a twist — we need the result **at each index**, not just the global maximum.
//
// ❗ Since brute force O(n^2) would TLE (10^10 operations), we use a modified patience sorting approach with binary search.
// Instead of lower_bound (used for strictly increasing subsequences), we use upper_bound to allow equal elements — since it's non-decreasing.
//
// 📈 Time Complexity: O(n log n)
// 📦 Space Complexity: O(n)

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
        vector<int> result;  // stores length of longest non-decreasing subsequence ending at each index
        vector<int> lis;     // patience sorting style array storing minimal possible tails for each length

        for (int obstacle : obstacles) {
            // upper_bound to find first element > obstacle
            // because we want to keep non-decreasing order (not strictly increasing)
            int idx = upper_bound(lis.begin(), lis.end(), obstacle) - lis.begin();

            // if no such element found, extend the LIS
            if (idx == lis.size()) {
                lis.push_back(obstacle);
            } else {
                // replace the element to keep subsequence optimal
                lis[idx] = obstacle;
            }

            // idx + 1 gives the length of the sequence ending at current position
            result.push_back(idx + 1);
        }

        return result;
    }
};
