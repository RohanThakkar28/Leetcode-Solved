const int mod=1e9+7;
class Solution {
public:
    int numWays(int n, int k) {
        vector<vector<int>>dp(n,vector<int>(2,0));
        dp[0][0]=0;
        dp[0][1]=k;
        for(int i=1;i<n;i++){
            dp[i][0]=dp[i-1][1];
            dp[i][1]=(dp[i-1][0]+dp[i-1][1])*(k-1);
        }
        return (dp[n-1][0]+dp[n-1][1]);
        
    }
};