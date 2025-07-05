/*
------------------------------------------------------------
🔍 Problem: Sum of Subarray Minimums
Platform: LeetCode (Hard)
Link: https://leetcode.com/problems/sum-of-subarray-minimums/
------------------------------------------------------------

🧾 Problem Statement:
Given an array of integers `arr`, return the sum of minimum values of all possible subarrays of `arr`.
As the answer may be large, return it modulo 1e9 + 7.

📌 Example:
Input: arr = [3,1,2,4]
Output: 17
Explanation:
Subarrays are: 
[3], [1], [2], [4], [3,1], [1,2], [2,4], [3,1,2], [1,2,4], [3,1,2,4]
Their minimums are: 3, 1, 2, 4, 1, 1, 2, 1, 1, 1 → Sum = 17

🧠 Intuition:
Each element `arr[i]` will be the minimum for several subarrays.
We want to count:
- How many subarrays have `arr[i]` as the minimum?
Let:
- `prev[i]` = index of **previous smaller** element (strictly smaller)
- `next[i]` = index of **next smaller or equal** element

Then, `arr[i]` is the minimum in `(i - prev[i]) * (next[i] - i)` subarrays.
So, the contribution of `arr[i]` to the answer is:
`arr[i] * (i - prev[i]) * (next[i] - i)`

⚙️ Algorithm:
1. Use monotonic stack to compute `prev[i]` and `next[i]`
2. For each index `i`, calculate the number of subarrays where `arr[i]` is minimum
3. Multiply that count by `arr[i]` and sum it up

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
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        stack<int> st;
        vector<int> prev(n), next(n);

        // Calculate Previous Less Element (PLE)
        for (int i = 0; i < n; ++i) {
            while (!st.empty() && arr[st.top()] > arr[i]) st.pop();
            prev[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        // Clear stack for reuse
        while (!st.empty()) st.pop();

        // Calculate Next Less or Equal Element (NLE)
        for (int i = n - 1; i >= 0; --i) {
            while (!st.empty() && arr[st.top()] >= arr[i]) st.pop();
            next[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        // Calculate the total contribution
        long long result = 0;
        int mod = 1e9 + 7;
        for (int i = 0; i < n; ++i) {
            long long left = i - prev[i];
            long long right = next[i] - i;
            result = (result + (arr[i] * left % mod) * right % mod) % mod;
        }

        return (int)result;
    }
};
