#include <iostream>
#include <vector>
#include <climits>
using namespace std;

/*
───────────────────────────────────────────────────────────────
🔷 Matrix Chain Multiplication (MCM) - Minimum Cost
───────────────────────────────────────────────────────────────

📌 Problem:
Given an array `arr[]` of size `n` where the dimensions of matrices are:
Matrix 1: arr[0] x arr[1]
Matrix 2: arr[1] x arr[2]
...
Matrix n-1: arr[n-2] x arr[n-1]

We need to **find the minimum number of scalar multiplications** required to multiply the entire chain of matrices.

🧠 Intuition:
This is a classic **Dynamic Programming + Partitioning** problem (similar to Palindrome Partitioning).
- We try placing parenthesis between every valid pair and recursively compute the minimum cost.
- Cost = cost of left partition + right partition + cost of multiplying both submatrices.

📌 Why we start with `solve(arr, 1, n-1)`:
- Because `arr[i-1] * arr[k] * arr[j]` uses `arr[i-1]`, so `i` must start from 1.

🧮 Time Complexity: O(n³)
🧮 Space Complexity: O(n²)

*/

int solve(vector<int>& arr, int i, int j, vector<vector<int>> &dp){
    if(i >= j) return 0; // Base case: single matrix or invalid range needs no multiplication

    if(dp[i][j] != -1) return dp[i][j]; // Return if already solved

    int ans = INT_MAX;

    // Try every possible split point k between i and j
    for(int k = i; k < j; k++){
        // Cost of multiplying left part, right part, and their result together
        int temp = solve(arr, i, k, dp) + solve(arr, k+1, j, dp) + arr[i-1]*arr[k]*arr[j];
        ans = min(ans, temp);
    }

    return dp[i][j] = ans; // Store and return result
}

int matrixMultiplication(vector<int> &arr) {
    int n = arr.size();
    vector<vector<int>> dp(n, vector<int>(n, -1)); // Memoization table
    return solve(arr, 1, n - 1, dp);
}

/* Optional main for testing
int main() {
    vector<int> arr = {40, 20, 30, 10, 30};
    cout << "Minimum cost of matrix multiplication: " << matrixMultiplication(arr) << endl;
    return 0;
}
*/
