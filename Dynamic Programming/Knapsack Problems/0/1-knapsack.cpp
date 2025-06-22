#include<iostream>
#include<vector>
using namespace std;
class Solution {
  public:
  
  
    int ans(int ind,int W,vector<int>& val,vector<int>& wt,vector<vector<int>>& dp){
        if(ind<0){
            return 0;
        }
        if(W == 0) return 0;
        
        if(dp[ind][W]!=-1)
            return dp[ind][W];
        int nt = ans(ind-1,W,val,wt,dp);
        int t = 0;
        
        if(wt[ind]<=W)
            t = val[ind] +ans(ind-1,W-wt[ind],val,wt,dp);
        
        dp[ind][W] = max(t,nt);
        return dp[ind][W];
    }
    int knapsack(int w, vector<int> &val, vector<int> &wt) {
        // code here
        
        int n = val.size();
        
        vector<vector<int>>dp(n+1,vector<int>(w+1,-1));
        for(int i = 0; i <= n; i++) dp[i][0] = 0;
        for(int x = 0; x <= w; x++) dp[0][x] = 0;

        for(int ind = 1;ind <= n;ind++){
            for(int weight = 1;weight <= w; weight++){
                int nt = dp[ind-1][weight];
                int t = 0;
                if(wt[ind-1]<=weight)
                    t = val[ind-1] + dp[ind-1][weight-wt[ind-1]];
        
                dp[ind][weight] = max(t,nt);
            }
        }
        return dp[n][w];
        
    }
};