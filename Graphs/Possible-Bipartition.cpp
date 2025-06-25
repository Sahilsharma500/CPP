#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

/*
Intuition:
-----------
This problem is about checking if it's possible to divide `n` people into two groups such that
no pair in the `dislikes` list belongs to the same group. This is the classic **bipartite graph** check.

Approach:
----------
- Represent the people and dislikes as a graph.
- Use BFS (or DFS) to try coloring the graph with two colors.
- If at any point two adjacent nodes (people who dislike each other) have the same color, 
  then it's not bipartite — return false.
- If all connected components are two-colorable, return true.

This is also called **graph bipartitioning**, and the "color" vector represents the group of each person.

Time Complexity: O(N + E), where E is the number of dislikes
Space Complexity: O(N + E)
*/

class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        // Initialize color vector, -1 means unvisited/uncolored
        vector<int> color(n + 1, -1);

        // Build adjacency list from dislikes pairs
        unordered_map<int, vector<int>> adj;
        for (auto& d : dislikes) {
            adj[d[0]].push_back(d[1]);
            adj[d[1]].push_back(d[0]);
        }

        // Check each node (some may be disconnected components)
        for (int i = 1; i <= n; i++) {
            if (color[i] == -1) {
                // Start BFS from unvisited node
                queue<int> q;
                q.push(i);
                color[i] = 0; // Assign first color

                while (!q.empty()) {
                    int node = q.front();
                    q.pop();

                    // Traverse all neighbors
                    for (auto neighbor : adj[node]) {
                        // If not colored, assign opposite color
                        if (color[neighbor] == -1) {
                            color[neighbor] = 1 - color[node];
                            q.push(neighbor);
                        }
                        // If neighbor has same color → not bipartite
                        else if (color[neighbor] == color[node]) {
                            return false;
                        }
                    }
                }
            }
        }

        // If all components are bipartite
        return true;
    }
};
