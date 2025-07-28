/*
 * LeetCode 968: Binary Tree Cameras
 * ----------------------------------
 * A binary tree node is monitored if:
 * - It has a camera on itself
 * - It is covered by its parent or one of its children
 *
 * You can place a camera on any node. Each camera at a node can monitor:
 * - Its parent
 * - Itself
 * - Its immediate children
 *
 * Return the minimum number of cameras needed to monitor all nodes in the tree.
 *
 * ------------------------------------------------------
 * ✅ Intuition & Approach:
 * - We do a post-order DFS traversal (process children before parent).
 * - For each node, we determine:
 *   1. If it needs a camera → return -1
 *   2. If it is covered → return 1
 *   3. If it has a camera → return 0
 * - If any child needs a camera, place a camera at current node.
 * - If any child has a camera, current node is covered.
 * - If both children are covered, current node needs a camera (marked to ask parent to place it).
 *
 * States:
 * - -1 → Needs camera
 * - 0 → Has camera
 * - 1 → Covered
 */

#include <iostream>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    // Helper function that returns:
    // -1: node needs a camera
    //  0: node has a camera
    //  1: node is covered
    int solve(TreeNode* root, int& cameraCount) {
        if (root == NULL) return 1;  // NULL nodes are covered

        int left = solve(root->left, cameraCount);
        int right = solve(root->right, cameraCount);

        // If any child needs a camera, place camera here
        if (left == -1 || right == -1) {
            cameraCount++;
            return 0;  // Place camera
        }

        // If any child has a camera, current node is covered
        if (left == 0 || right == 0) {
            return 1;  // Covered
        }

        // Else, current node needs camera
        return -1;
    }

    int minCameraCover(TreeNode* root) {
        int cameraCount = 0;
        if (solve(root, cameraCount) == -1) {
            cameraCount++;  // Root still needs a camera
        }
        return cameraCount;
    }
};
