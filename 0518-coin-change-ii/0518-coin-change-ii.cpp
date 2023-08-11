class Solution {
public:
    int sol(int i,int amt,vector<int>& coins,vector<vector<int>>&dp){
        
        if(amt==0){
            return 1;
        }
        int n=coins.size();
        if(i==n || amt<0){
            return 0;
        }
        if(dp[i][amt]!=-1){
            return dp[i][amt];
        }
        int a=sol(i,amt-coins[i],coins,dp);
        int b=sol(i+1,amt,coins,dp);
        return dp[i][amt]=a+b;
    }
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        int ans=sol(0,amount,coins,dp);
        return ans;
        
        
    }
};