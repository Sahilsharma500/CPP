#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/*
───────────────────────────────────────────────────────────────
🔷 Max Distance from Land (LeetCode 1162)
───────────────────────────────────────────────────────────────

📌 Problem:
You are given an n x n grid containing only 0s (water) and 1s (land).
Return the maximum distance from a water cell to the nearest land cell.
If all cells are land or all are water, return -1.

🧠 Intuition:
This is a multi-source BFS problem:
- All land cells act as starting points.
- Perform BFS to expand into water cells layer by layer.
- The last layer processed gives us the farthest distance from land.

🧮 Time Complexity: O(n²)
🧮 Space Complexity: O(n²)

*/

class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size();
        queue<pair<int, int>> q;

        // Step 1: Add all land cells (1s) to the queue
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1)
                    q.push({i, j});
            }
        }

        // Edge case: if all cells are water or all are land
        if (q.empty() || q.size() == n * n)
            return -1;

        // Directions for 4-neighbor movement (up, down, left, right)
        int dirs[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        int distance = -1;

        // Step 2: Multi-source BFS
        while (!q.empty()) {
            int size = q.size();
            distance++;  // Increase level (distance)

            for (int i = 0; i < size; ++i) {
                auto [r, c] = q.front(); q.pop();

                for (auto& d : dirs) {
                    int nr = r + d[0];
                    int nc = c + d[1];

                    // Check if neighbor is within bounds and is water
                    if (nr >= 0 && nc >= 0 && nr < n && nc < n && grid[nr][nc] == 0) {
                        grid[nr][nc] = 1;  // Mark visited by turning into land
                        q.push({nr, nc});
                    }
                }
            }
        }

        return distance;  // Final level is the max distance from any land
    }
};

/* Optional main for testing
int main() {
    Solution sol;
    vector<vector<int>> grid = {{0,0,1}, {0,0,0}, {1,0,0}};
    cout << "Max Distance from Land: " << sol.maxDistance(grid) << endl;
    return 0;
}
*/
