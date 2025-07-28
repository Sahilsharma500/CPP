/*
 * Problem: LeetCode 95 – Unique Binary Search Trees II
 *
 * Description:
 * Given an integer n, return all structurally unique BSTs (binary search trees)
 * that store values 1 to n.
 *
 * ---------------------------------------------------------------
 * ✅ Intuition:
 * - Choose each number from 1 to n as the root.
 * - Recursively generate all possible left subtrees using numbers < root.
 * - Recursively generate all possible right subtrees using numbers > root.
 * - Combine each left and right subtree with the current root.
 * - Use memoization to avoid recomputing subtrees for the same (start, end) range.
 *
 * ---------------------------------------------------------------
 * 📦 Time Complexity:
 * - Exponential due to the number of BSTs = Catalan(n)
 *
 * 🧠 Space Complexity:
 * - O(Catalan(n)) for storing all BSTs + memoization map.
 *
 * ---------------------------------------------------------------
 * Example: n = 3
 * Total trees = 5
 * Possible structures:
 *    1        1         2        3        3
 *     \        \       / \      /        /
 *      2        3     1   3    1        2
 *       \      /                  \    /
 *        3    2                    2  1
 */

#include <iostream>
#include <vector>
#include <map>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *l, TreeNode *r) : val(x), left(l), right(r) {}
};

class Solution {
public:
    // Memoization: dp[start][end] stores all trees for range [start, end]
    map<int, map<int, vector<TreeNode*>>> dp;

    vector<TreeNode*> solve(int start, int end) {
        if (start > end) return {nullptr};  // Base case: return null for empty tree

        if (dp[start].count(end)) return dp[start][end];  // Return memoized result

        vector<TreeNode*> trees;

        for (int rootVal = start; rootVal <= end; ++rootVal) {
            // Generate all left and right subtrees recursively
            vector<TreeNode*> leftSubtrees = solve(start, rootVal - 1);
            vector<TreeNode*> rightSubtrees = solve(rootVal + 1, end);

            // Combine each pair of left and right subtree with root
            for (TreeNode* left : leftSubtrees) {
                for (TreeNode* right : rightSubtrees) {
                    TreeNode* root = new TreeNode(rootVal, left, right);
                    trees.push_back(root);
                }
            }
        }

        return dp[start][end] = trees;  // Save and return result
    }

    vector<TreeNode*> generateTrees(int n) {
        if (n == 0) return {};
        return solve(1, n);
    }
};
