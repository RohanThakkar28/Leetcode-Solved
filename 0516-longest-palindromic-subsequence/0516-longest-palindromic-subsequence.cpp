class Solution {
public:
    int sol(int i,int j,string &s,vector<vector<int>>&dp){
        if(i==j){
            return 1;
        }
        if(i>j){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        if(s[i]==s[j]){
            int a=2+sol(i+1,j-1,s,dp);
            int b=sol(i+1,j,s,dp);
            int c=sol(i,j-1,s,dp);
            return dp[i][j]=max({a,b,c});
        }
        else{
            int b=sol(i+1,j,s,dp);
            int c=sol(i,j-1,s,dp);
            return dp[i][j]=max({b,c});
            
        }
        return 0;
    }
    int longestPalindromeSubseq(string s) {
        int n=s.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        return sol(0,n-1,s,dp);
    }
};