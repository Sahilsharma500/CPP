#include <vector>
using namespace std;

class NumMatrix {
public:
    // 2D prefix sum matrix
    vector<vector<int>> prefix;

    // Constructor: Build the prefix sum matrix
    NumMatrix(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        // We use (n+1) x (m+1) matrix to simplify 1-based indexing.
        // prefix[i][j] represents sum of rectangle from (0,0) to (i-1,j-1)
        prefix = vector<vector<int>>(n + 1, vector<int>(m + 1, 0));

        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                // Build prefix[i][j] using inclusion-exclusion
                prefix[i][j] = matrix[i - 1][j - 1]                // current cell
                             + prefix[i - 1][j]                    // top
                             + prefix[i][j - 1]                    // left
                             - prefix[i - 1][j - 1];               // overlap (top-left)
            }
        }
    }

    // sumRegion returns the sum of all elements inside the rectangle
    // from (row1, col1) to (row2, col2) inclusive
    int sumRegion(int row1, int col1, int row2, int col2) {
        // Shift all indices by +1 because our prefix sum uses 1-based indexing

        /*
        📊 Visualization:
        Let's say we want to find the sum of submatrix from (row1, col1) to (row2, col2)

        A = total sum from (0,0) to (row2, col2)
        B = sum above submatrix = from (0,0) to (row1-1, col2)
        C = sum left  of submatrix = from (0,0) to (row2, col1-1)
        D = overlap region (counted twice) = from (0,0) to (row1-1, col1-1)

        So the sum is:
            A - B - C + D

        Which translates to:
            prefix[row2+1][col2+1]
          - prefix[row1][col2+1]
          - prefix[row2+1][col1]
          + prefix[row1][col1]
        */

        return prefix[row2 + 1][col2 + 1]
             - prefix[row1][col2 + 1]
             - prefix[row2 + 1][col1]
             + prefix[row1][col1];
    }
};
