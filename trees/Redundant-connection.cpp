/*
------------------------------------------------------------
🔍 Problem: Redundant Connection
Platform: LeetCode (Medium)
Link: https://leetcode.com/problems/redundant-connection/
------------------------------------------------------------

📄 Problem Statement:
In this problem, you're given a graph with `n` nodes (labeled from 1 to n) and `n` edges. 
Exactly one edge in the graph is **redundant**, meaning it can be removed while keeping 
the graph connected and acyclic (i.e., a tree). 
Return the edge that can be removed.

🧠 Intuition:
This is a classic **Union-Find (Disjoint Set Union, DSU)** problem.

- A tree with `n` nodes has exactly `n-1` edges.
- If a graph has `n` nodes and `n` edges, then **exactly one cycle exists**.
- We will use DSU to detect the cycle. The first time we try to union two nodes that already 
  have the same parent, we know that edge forms a cycle and is the redundant one.

⚙️ Approach:
- Initialize the `parent` array where each node is its own parent.
- Use **path compression** for efficient lookup of the root/representative of each set.
- Use **union by rank** to keep the tree shallow when merging sets.
- As we process each edge:
    - If the two nodes are already connected (same parent), then it forms a cycle → return the edge.
    - Otherwise, union the two sets.

🧮 Time Complexity: O(α(N)) per union/find operation (almost constant time)
🧮 Space Complexity: O(N) for parent and rank arrays

------------------------------------------------------------
*/

#include <vector>
using namespace std;

class Solution {
public:
    // Find function with path compression
    int findParent(vector<int>& parent, int node) {
        if (parent[node] != node)
            parent[node] = findParent(parent, parent[node]);
        return parent[node];
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> rank(n + 1, 0);          // Union by rank
        vector<int> parent(n + 1);           // Parent array

        // Initially, every node is its own parent
        for (int i = 1; i <= n; i++) parent[i] = i;

        for (int i = 0; i < n; i++) {
            int u = edges[i][0];
            int v = edges[i][1];

            int parentU = findParent(parent, u);
            int parentV = findParent(parent, v);

            if (parentU == parentV) {
                // They are already connected → cycle detected
                return edges[i];
            } else {
                // Union by rank
                if (rank[parentU] == rank[parentV]) {
                    parent[parentV] = parentU;
                    rank[parentU]++;
                } else if (rank[parentU] > rank[parentV]) {
                    parent[parentV] = parentU;
                } else {
                    parent[parentU] = parentV;
                }
            }
        }

        return {0, 0};  // Should not reach here if one redundant connection is guaranteed
    }
};
