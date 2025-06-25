#include <iostream>
#include <vector>
#include <string>
using namespace std;

/*
Intuition:
------------
This problem asks how many regions are formed by slashes ('/' and '\\') in a grid.
A slash divides a cell into separate triangular parts. To make things easier,
we upscale each grid cell to a 3x3 mini-grid.

Approach:
------------
1. Expand the original `n x n` grid into a `3n x 3n` grid.
   - Each slash '/' or '\\' is mapped to certain positions within a 3x3 block.
2. After marking the slashes, we treat the grid as a graph.
   - Regions are formed by connected empty (0) areas in the expanded grid.
3. Perform DFS to count how many disconnected regions of 0s exist.

Time Complexity: O(n^2)
Space Complexity: O(n^2)
*/

class Solution {
public:
    int n;  // original grid size
    vector<vector<int>> expanded;  // expanded 3n x 3n grid

    // DFS to mark all reachable cells from (i, j)
    void dfs(int i, int j) {
        // Base case: out of bounds or already visited
        if (i < 0 || i >= 3 * n || j < 0 || j >= 3 * n || expanded[i][j] != 0)
            return;

        // Mark current cell as visited
        expanded[i][j] = 1;

        // Visit all 4 directions
        dfs(i - 1, j);
        dfs(i + 1, j);
        dfs(i, j - 1);
        dfs(i, j + 1);
    }

    int regionsBySlashes(vector<string>& grid) {
        n = grid.size();
        // Step 1: Expand to a 3n x 3n grid initialized with 0s
        expanded = vector<vector<int>>(n * 3, vector<int>(n * 3, 0));

        // Step 2: Fill slashes in the expanded grid
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                char c = grid[i][j];

                // For '/', mark the three diagonal positions
                if (c == '/') {
                    expanded[i * 3 + 0][j * 3 + 2] = 1;
                    expanded[i * 3 + 1][j * 3 + 1] = 1;
                    expanded[i * 3 + 2][j * 3 + 0] = 1;
                }
                // For '\', mark the other diagonal
                else if (c == '\\') {
                    expanded[i * 3 + 0][j * 3 + 0] = 1;
                    expanded[i * 3 + 1][j * 3 + 1] = 1;
                    expanded[i * 3 + 2][j * 3 + 2] = 1;
                }
            }
        }

        // Step 3: Count number of connected regions using DFS
        int regions = 0;
        for (int i = 0; i < 3 * n; i++) {
            for (int j = 0; j < 3 * n; j++) {
                if (expanded[i][j] == 0) {
                    regions++;      // found a new region
                    dfs(i, j);      // mark the entire region
                }
            }
        }

        return regions;
    }
};
