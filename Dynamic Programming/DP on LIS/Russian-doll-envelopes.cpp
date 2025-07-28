/******************************************************************************
🔍 Problem: Russian Doll Envelopes (LeetCode 354)
Link: https://leetcode.com/problems/russian-doll-envelopes/

🧾 Problem Statement:
You are given a 2D array of envelopes where envelopes[i] = [wi, hi] represents
the width and the height of an envelope. One envelope can fit into another 
if and only if both the width and height of one envelope is greater than the other.

Return the maximum number of envelopes you can Russian doll (i.e., put one inside the other).

===============================================================================
🧠 Intuition:
This is a variation of the Longest Increasing Subsequence (LIS) problem in 2D.

===============================================================================
🧠 Approach:
1. **Sort envelopes**:
   - Ascending by width.
   - If widths are equal, descending by height (to avoid counting duplicates).

2. **Apply LIS on heights**:
   - After sorting, the widths are in increasing order.
   - For the LIS, use the heights and find the length of the longest increasing subsequence.

⚠️ Sorting heights in descending order when widths are equal is *critical* to avoid invalid nesting like:
   Input: [[5,4],[5,5],[5,6]] → only one envelope can be used if widths are equal.

===============================================================================
⌛ Time Complexity:
- O(N log N) for sorting and LIS

📦 Space Complexity:
- O(N) for LIS array
******************************************************************************/

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int n = envelopes.size();
        if (n == 0) return 0;

        // Sort by width ASC and height DESC for equal widths
        sort(envelopes.begin(), envelopes.end(), [](const vector<int>& a, const vector<int>& b) {
            if (a[0] == b[0]) return a[1] > b[1];  // descending height for same width
            return a[0] < b[0];                    // ascending width
        });

        // Extract only heights to apply LIS
        vector<int> heights;
        for (auto& env : envelopes) {
            heights.push_back(env[1]);
        }

        // Apply LIS on heights
        vector<int> lis;
        for (int h : heights) {
            auto it = lower_bound(lis.begin(), lis.end(), h);
            if (it == lis.end()) {
                lis.push_back(h);
            } else {
                *it = h;
            }
        }

        return lis.size();  // length of LIS = max number of envelopes
    }
};
