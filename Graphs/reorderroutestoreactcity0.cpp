/*
 * LeetCode 1466: Reorder Routes to Make All Paths Lead to the City Zero
 * ----------------------------------------------------------------------
 * You are given a tree with `n` nodes (0 to n-1), rooted at node 0.
 * Each directed edge from connections[i] = [a, b] means "from a to b".
 * You can reverse any number of edges. Return the minimum number of edges 
 * you need to reverse so that **every node has a path to node 0**.
 * 
 * --------------------------------------------------
 * ✅ Intuition:
 * - Since the graph is a tree, there are exactly `n-1` edges and it's connected.
 * - Start DFS traversal from node 0.
 * - Maintain a custom adjacency list with direction info:
 *    - If the original edge is `u → v`, store:
 *         - adj[u].push_back({v, 0})   // 0 = wrong direction (outward)
 *         - adj[v].push_back({u, 1})   // 1 = correct direction (inward)
 * - If we encounter a `0` during DFS, we must **reverse it**, so increment `count`.

 * ✅ Time Complexity:
 * - O(n), since it’s a tree with n-1 edges.
 */

#include <vector>
using namespace std;

class Solution {
public:
    void dfs(vector<vector<pair<int, int>>>& adj, int node, int &count, vector<bool>& vis){
        vis[node] = true;

        for(auto [neighbor, reversal] : adj[node]){
            if(!vis[neighbor]){
                if(reversal == 0){
                    // Edge originally from node → neighbor needs reversal
                    count++;
                }
                dfs(adj, neighbor, count, vis);
            }
        }
    }

    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<pair<int, int>>> adj(n);
        
        for(auto& conn : connections){
            int u = conn[0];
            int v = conn[1];
            // 0 → 1 means: edge from u to v needs reversal to reach 0
            adj[u].push_back({v, 0}); // original direction (u -> v)
            adj[v].push_back({u, 1}); // reversed direction (v -> u)
        }

        vector<bool> vis(n, false);
        int count = 0;

        dfs(adj, 0, count, vis);  // Start DFS from root node 0
        return count;
    }
};
