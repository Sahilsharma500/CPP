#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
// #include <bits/stdc++.h>
using namespace std;

class Solution {

  public:
  //this is the memoization code
//   bool solve(int ind, int target, vector<int>& arr, vector<vector<int>>& dp) {
//     if (target == 0) return true;
//     if (ind == 0) return arr[0] == target;
//     if (dp[ind][target] != -1) return dp[ind][target];

//     bool notTake = solve(ind - 1, target, arr, dp);
//     bool take = false;
//     if (arr[ind] <= target)
//         take = solve(ind - 1, target - arr[ind], arr, dp);

//     return dp[ind][target] = take || notTake;
// }

// int minDifference(vector<int>& arr) {
//     int n = arr.size();
//     int totalSum = accumulate(arr.begin(), arr.end(), 0);

//     vector<vector<int>> dp(n, vector<int>(totalSum + 1, -1));

//     int minDiff = INT_MAX;

//     // Try all possible subset sums up to totalSum/2
//     for (int s1 = 0; s1 <= totalSum / 2; ++s1) {
//         if (solve(n - 1, s1, arr, dp)) {
//             int s2 = totalSum - s1;
//             minDiff = min(minDiff, abs(s1 - s2));
//         }
//     }

//     return minDiff;
// }
//  this is the tabulation code
    int minDifference(vector<int>& arr) {
        // Your code goes here
        int n = arr.size();
        int sum = accumulate(arr.begin(), arr.end(), 0);
        vector<vector<int>> dp(n+1, vector<int>(sum+1, -1));
        // return solve(arr, n - 1, sum, dp);
        for(int i = 0;i<=n;i++){
            dp[i][0] = 1;
        }
        for(int i = 1;i<=sum;i++){
            dp[0][i] = 0;
        }
        
        for(int ind = 1;ind<=n;ind++){
            for(int j = 1;j<=sum;j++){
                bool take = false;
                if(arr[ind-1] <= j){
                    take = dp[ind-1][j-arr[ind-1]];
                }
                bool nottake = dp[ind-1][j];
                dp[ind][j] = take || nottake;
            }
        }
        
        int ans = INT_MAX;
        for(int i = 0;i<=sum/2;i++){
            if(dp[n][i]){
                ans = min(ans, sum-2*i);
            }
        }
        return ans;
    }
};