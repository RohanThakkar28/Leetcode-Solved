class Solution {
public:
    int removeAlmostEqualCharacters(string word) {
        int n=word.size();
        vector<vector<int>>dp(n,vector<int>(2,1e9));
        dp[0][0]=0;
        dp[0][1]=1;
        for(int i=1;i<n;i++){
            
                if(abs((word[i]-'a')-(word[i-1]-'a'))<=1){
                    dp[i][0]=dp[i-1][1];
                    dp[i][1]=1+dp[i-1][0];
                }
                else{
                    dp[i][0]=min(dp[i-1][0],dp[i-1][1]);
                    dp[i][1]=1+min(dp[i-1][0],dp[i-1][1]);
                }
            
                
            
        }
        return min(dp[n-1][0],dp[n-1][1]);
        
    }
};