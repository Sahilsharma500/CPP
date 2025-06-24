#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

using namespace std;

/*
Intuition:
This problem models a graph, where each variable is a node and each equation represents a directed weighted edge.
For example, "a / b = 2.0" means there's an edge from a to b with weight 2.0, and from b to a with weight 1/2.0.
To solve a query like "a / c", we need to find a path from a to c and multiply the edge weights along the way.

Approach:
1. Assign each variable a unique integer ID for efficient lookup.
2. Build an adjacency list graph where each node stores neighbors and the division value.
3. For each query, run DFS from the source node to the destination while accumulating the product.
4. If a path exists, return the product; otherwise return -1.0.

Time Complexity:
- Building the graph: O(E), where E is the number of equations.
- Answering each query: O(V + E) in the worst case per query (DFS traversal).
*/

class Solution {
public:
    // Graph: variable -> list of (neighbor, weight)
    unordered_map<string, vector<pair<string, double>>> mp;

    // Mapping variable names to integer IDs
    unordered_map<string, int> strToId;
    int id = 0;

    // DFS to find path from src to dest
    bool dfs(string src, string dest, vector<bool>& visited, double& result, double currVal) {
        if (src == dest) {
            result = currVal;
            return true;
        }

        // Mark current node as visited
        visited[strToId[src]] = true;

        // Explore neighbors
        for (auto& neighbor : mp[src]) {
            string next = neighbor.first;
            double val = neighbor.second;

            // Recurse if not visited
            if (!visited[strToId[next]]) {
                if (dfs(next, dest, visited, result, currVal * val))
                    return true;
            }
        }

        return false;
    }

    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        // Step 1: Build graph and assign unique IDs to each variable
        for (int i = 0; i < equations.size(); i++) {
            string u = equations[i][0];
            string v = equations[i][1];
            double val = values[i];

            // Assign IDs if not already assigned
            if (strToId.find(u) == strToId.end()) strToId[u] = id++;
            if (strToId.find(v) == strToId.end()) strToId[v] = id++;

            // Add directed edges with corresponding weights
            mp[u].push_back({v, val});
            mp[v].push_back({u, 1.0 / val});
        }

        vector<double> ans;

        // Step 2: Resolve each query using DFS
        for (int i = 0; i < queries.size(); i++) {
            string u = queries[i][0];
            string v = queries[i][1];

            // If either variable is not in the graph, answer is -1
            if (mp.find(u) == mp.end() || mp.find(v) == mp.end()) {
                ans.push_back(-1.0);
            }
            // If both variables are the same, answer is 1
            else if (u == v) {
                ans.push_back(1.0);
            }
            else {
                // Reset visited array for each query
                vector<bool> visited(id, false);
                double result = -1.0;

                // Run DFS to find path and compute result
                if (dfs(u, v, visited, result, 1.0)) {
                    ans.push_back(result);
                } else {
                    ans.push_back(-1.0);
                }
            }
        }

        return ans;
    }
};
