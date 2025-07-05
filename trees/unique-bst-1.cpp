/*
------------------------------------------------------------
🔍 Problem: Unique Binary Search Trees (Catalan Number)
Platform: LeetCode (Medium)
Link: https://leetcode.com/problems/unique-binary-search-trees/
------------------------------------------------------------

📄 Problem Statement:
Given an integer `n`, return the number of structurally unique BSTs (binary search trees) 
which has exactly `n` nodes of unique values from 1 to n.

🧠 Intuition:
This is a classic **Catalan Number** problem. The number of unique BSTs that can be formed 
using `n` nodes is given by:

    C(n) = Σ (i = 1 to n) [C(i - 1) * C(n - i)]

Where:
- `i` is the root,
- `C(i-1)` is the number of unique left subtrees (with nodes less than i),
- `C(n-i)` is the number of unique right subtrees (with nodes greater than i).

We solve this using **Top-Down DP (Memoization)** to avoid recomputation of overlapping subproblems.

⚙️ Approach:
- Define a recursive function `solve(n)` which returns the number of unique BSTs for `n` nodes.
- Use a `dp` array of size `n+1` initialized with `-1` to store already computed values.
- For each number `i` from 1 to `n`, recursively compute number of left and right subtrees.
- The base case is: 
  - `solve(0)` and `solve(1)` return 1 because there's only one structure possible.

🧮 Time Complexity: O(n^2)
🧮 Space Complexity: O(n)  [for memoization array]

------------------------------------------------------------
*/

#include <vector>
using namespace std;

class Solution {
public:
    int solve(int n, vector<int>& dp){
        if(n == 0 || n == 1) return 1;  // Base case: one unique BST

        if(dp[n] != -1) return dp[n];  // Return memoized result

        int ans = 0;
        for(int i = 1; i <= n; i++){
            // i-1 nodes go to the left subtree, n-i go to right
            ans += solve(i-1, dp) * solve(n-i, dp);
        }

        return dp[n] = ans;  // Memoize and return
    }

    int numTrees(int n) {
        vector<int> dp(n+1, -1);  // Initialize memoization array
        return solve(n, dp);
    }
};
