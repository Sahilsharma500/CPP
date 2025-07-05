/*
------------------------------------------------------------
🔍 Problem: Longest Increasing Subsequence (LIS)
Platform: LeetCode (Medium)
------------------------------------------------------------

📄 Problem Statement:
Given an integer array `nums`, return the length of the longest strictly 
increasing subsequence.

🧠 Intuition:
We aim to find the length of the longest subsequence where each element 
is strictly greater than the previous one. A brute-force approach using 
recursion or DP has O(n^2) time complexity.

This optimized version uses **Patience Sorting** technique with a greedy approach 
and binary search to achieve **O(n log n)** time.

⚙️ Approach:
- Create a temporary array `temp` which will store the smallest possible 
  tail element for all increasing subsequences of different lengths.
- For each element in `nums`:
    - If it's greater than the last element of `temp`, we can extend the 
      LIS by one.
    - Otherwise, we replace the **first element in `temp` which is ≥ current element** 
      using `lower_bound` (to maintain optimal subsequence candidates).

*Note:* The `temp` array **does not store the actual LIS**, but its length 
will equal the length of the LIS.

🧮 Time Complexity: O(n log n)
🧮 Space Complexity: O(n)

------------------------------------------------------------
*/

#include <vector>
#include <algorithm>
using namespace std;

int lengthOfLIS(vector<int>& nums) {
    int n = nums.size();
    if (n == 0) return 0;

    vector<int> temp;
    temp.push_back(nums[0]);

    for (int i = 1; i < n; i++) {
        if (nums[i] > temp.back()) {
            // If current element is bigger, extend the increasing sequence
            temp.push_back(nums[i]);
        } else {
            // Replace the lower_bound with current element to maintain minimal value
            int ind = lower_bound(temp.begin(), temp.end(), nums[i]) - temp.begin();
            temp[ind] = nums[i];
        }
    }

    // Length of temp is the length of the LIS
    return temp.size();
}
