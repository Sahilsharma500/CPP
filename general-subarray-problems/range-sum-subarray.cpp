/*
------------------------------------------------------------
🔍 Problem: Sum of Subarray Ranges
Platform: LeetCode (Medium)
Link: https://leetcode.com/problems/sum-of-subarray-ranges/
------------------------------------------------------------

🧾 Problem Statement:
You are given an integer array `nums`. The range of a subarray of `nums` is the difference between the largest and smallest element in the subarray.
Return the sum of all subarray ranges of `nums`.

📌 Example:
Input: nums = [1,2,3]
Output: 4
Explanation: The subarrays of nums are:
[1], range = 0
[2], range = 0
[3], range = 0
[1,2], range = 1
[2,3], range = 1
[1,2,3], range = 2
→ Total sum = 0 + 0 + 0 + 1 + 1 + 2 = 4

🧠 Intuition:
For each element, calculate how many subarrays where it is:
1. The **minimum** → using monotonic stack (strictly greater to left, greater-equal to right)
2. The **maximum** → using monotonic stack (strictly smaller to left, smaller-equal to right)

Then:
- Total contribution when acting as minimum → subtract
- Total contribution when acting as maximum → add

🧮 Final Answer = sum of max contributions - sum of min contributions

⚙️ Algorithm:
1. Compute how many subarrays each element is max and min for using monotonic stacks.
2. Use formula:
   - For max: contribution = arr[i] * left * right
   - For min: contribution = arr[i] * left * right
3. Subtract total min contribution from total max contribution.

🧮 Time Complexity: O(N)
🧮 Space Complexity: O(N)

------------------------------------------------------------
*/

#include<iostream>
#include<vector>
#include<stack>
using namespace std;

class Solution {
public:
    // 🟢 Helper: Sum of Subarray Minimums
    long long sumSubarrayMins(vector<int> arr) {
        int n = arr.size();
        stack<int> st;
        vector<int> prev(n), next(n);

        // Find previous less element
        for (int i = 0; i < n; ++i) {
            while (!st.empty() && arr[st.top()] > arr[i])
                st.pop();
            prev[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        while (!st.empty()) st.pop();

        // Find next less or equal element
        for (int i = n - 1; i >= 0; --i) {
            while (!st.empty() && arr[st.top()] >= arr[i])
                st.pop();
            next[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        // Calculate total minimum contribution
        long long result = 0;
        for (int i = 0; i < n; ++i) {
            long long left = i - prev[i];
            long long right = next[i] - i;
            result += (long long)arr[i] * left * right;
        }

        return result;
    }

    // 🔴 Helper: Sum of Subarray Maximums
    long long sumSubarrayMaxs(vector<int> arr) {
        int n = arr.size();
        stack<int> st;
        vector<int> prev(n), next(n);

        // Find previous greater element
        for (int i = 0; i < n; ++i) {
            while (!st.empty() && arr[st.top()] < arr[i])
                st.pop();
            prev[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        while (!st.empty()) st.pop();

        // Find next greater or equal element
        for (int i = n - 1; i >= 0; --i) {
            while (!st.empty() && arr[st.top()] <= arr[i])
                st.pop();
            next[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        // Calculate total maximum contribution
        long long result = 0;
        for (int i = 0; i < n; ++i) {
            long long left = i - prev[i];
            long long right = next[i] - i;
            result += (long long)arr[i] * left * right;
        }

        return result;
    }

    // ✅ Final Answer
    long long subArrayRanges(vector<int>& nums) {
        long long largest = sumSubarrayMaxs(nums);
        long long smallest = sumSubarrayMins(nums);
        return largest - smallest;
    }
};
