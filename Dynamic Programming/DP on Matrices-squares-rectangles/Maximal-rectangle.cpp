/*
    ✅ Problem: Maximal Rectangle (Leetcode #85)

    🔍 Intuition:
    Convert each row of the matrix into a histogram of consecutive '1's from the top.
    Then, for each row (seen as a histogram), compute the largest rectangle using the Largest Rectangle in Histogram approach.

    🧠 Approach:
    - For each row in the matrix:
        - If current cell is '1', increase the height in the `height[]` array
        - If it’s '0', reset height to 0
    - After updating the height array for a row, treat it like a histogram
    - Apply the monotonic stack-based algorithm to calculate the **largest rectangle area in the histogram**
        - Maintain a stack to store indices
        - While the current height is smaller than the top of stack, compute area using the top
        - Do the same once more after the row ends for remaining elements in the stack

    🛠️ Time Complexity:
    - O(n * m) for iterating matrix
    - O(m) per row for histogram computation
    - Total: O(n * m)
*/

#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

class Solution {
public:
    // Function to calculate the largest rectangle in a histogram
    int findMaxi(vector<int> heights) {
        int n = heights.size();
        stack<int> st;
        int maxi = 0;

        for (int i = 0; i < n; i++) {
            int curr = heights[i];
            // While stack is not empty and current height is less than top of stack
            while (!st.empty() && heights[st.top()] > curr) {
                int height = heights[st.top()];
                st.pop();
                int prev = st.empty() ? -1 : st.top();
                int width = i - prev - 1;
                maxi = max(maxi, height * width);
            }
            st.push(i);
        }

        // Remaining bars in stack
        while (!st.empty()) {
            int height = heights[st.top()];
            st.pop();
            int prev = st.empty() ? -1 : st.top();
            int width = n - prev - 1;
            maxi = max(maxi, height * width);
        }

        return maxi;
    }

    // Main function to calculate the maximal rectangle in the binary matrix
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        if (n == 0) return 0;
        int m = matrix[0].size();
        vector<int> height(m, 0);
        int maxi = 0;

        for (int i = 0; i < n; i++) {
            // Build height array for current row
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == '1') {
                    height[j] += 1;
                } else {
                    height[j] = 0;
                }
            }

            // Calculate the maximum area in histogram for this row
            int maxArea = findMaxi(height);
            maxi = max(maxi, maxArea);
        }

        return maxi;
    }
};
