/*
 * LeetCode 834: Sum of Distances in Tree
 * ---------------------------------------
 * Given a tree with `n` nodes (0 to n-1) and an array of edges, 
 * return an array `result` where `result[i]` is the sum of distances 
 * between node `i` and all other nodes in the tree.
 *
 * --------------------------------------------------
 * ✅ Intuition:
 * - Use **Tree DP** with two traversals:
 *   1. **Post-order DFS** to calculate:
 *      - The total distance from root (node 0) to all nodes.
 *      - The count of nodes in each subtree.
 *   2. **Pre-order DFS** to calculate the result for every other node 
 *      using its parent’s result and count values.
 *
 * Let:
 * - `result[node]` be the sum of distances from `node` to all others.
 * - `count[node]` be the number of nodes in the subtree rooted at `node`.
 *
 * Transition for pre-order DFS:
 * - `result[child] = result[parent] - count[child] + (n - count[child])`
 * 
 * Why?
 * - We remove `count[child]` nodes that are 1 closer to parent than child.
 * - Add `(n - count[child])` nodes that are 1 farther from child.
 */

#include <vector>
using namespace std;

class Solution {
public:
    // First DFS: Post-order to compute count[] and result[0]
    int dfs(vector<vector<int>>& adj, int node, int sum, int parent, vector<int>& count) {
        int ans = sum;

        for (auto neighbor : adj[node]) {
            if (neighbor != parent) {
                ans += dfs(adj, neighbor, sum + 1, node, count);
                count[node] += count[neighbor]; // accumulate subtree sizes
            }
        }

        count[node] += 1; // include self
        return ans;
    }

    // Second DFS: Pre-order to propagate result from parent to children
    void getres(vector<vector<int>>& adj, int node, int parent, vector<int>& count, vector<int>& result) {
        for (auto neighbor : adj[node]) {
            if (neighbor != parent) {
                // Transition formula
                result[neighbor] = result[node] - count[neighbor] + (adj.size() - count[neighbor]);
                getres(adj, neighbor, node, count, result);
            }
        }
    }

    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for (auto& edge : edges) {
            int u = edge[0], v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> result(n);
        vector<int> count(n, 0);

        result[0] = dfs(adj, 0, 0, -1, count);  // Rooted at node 0
        getres(adj, 0, -1, count, result);      // Propagate results

        return result;
    }
};
