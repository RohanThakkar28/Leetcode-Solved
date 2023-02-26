class Solution {
public:
    int sol(int i,int j,string & word1, string & word2,vector<vector<int>>&dp){
        int n=word1.size();
        int m=word2.size();
        if(i==n){
            return m-j;
        }
        else if(j==m){
            return n-i;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int ans=0;
        if(word1[i]==word2[j]){
            ans=sol(i+1,j+1,word1,word2,dp);
        }
        else{
            int a=1+sol(i,j+1,word1,word2,dp);
            int b=1+sol(i+1,j,word1,word2,dp);
            int c=1+sol(i+1,j+1,word1,word2,dp);
            ans=min({a,b,c});
            
        }
        return dp[i][j]=ans;
    }
    int minDistance(string word1, string word2) {
        int n=word1.size();
        int m=word2.size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        int ans=sol(0,0,word1,word2,dp);
        return ans;
    }
};

