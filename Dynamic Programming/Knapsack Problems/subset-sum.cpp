#include<iostream>
#include<vector>
using namespace std;

class Solution {
  public:
  
  //this is memoization code
  bool solve(vector<int>& arr, int ind, int sum, vector<vector<int>>& dp){
      if(sum == 0) return true;
      if(ind < 0) return false;
      if(dp[ind][sum] != -1) return dp[ind][sum];
      bool take = false;
      if(arr[ind] <= sum){
          take = solve(arr, ind-1, sum-arr[ind], dp);
      }
      bool nottake = solve(arr, ind-1, sum, dp);
      return dp[ind][sum] = take || nottake;
  }
    bool isSubsetSum(vector<int>& arr, int sum) {
        // code here
        //this is tabulation code.
        int n = arr.size();
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
        return dp[n][sum];
        
        
    }
};