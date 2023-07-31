class Solution {
public:
    int sol(int i,int j,string &s1, string &s2,vector<vector<int>>&dp){
        int n=s1.size();
        int m=s2.size();
        if(i==n || j==m){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int ans=0;
        if(s1[i]==s2[j]){
            ans+=2*(97+(s1[i]-'a'))+sol(i+1,j+1,s1,s2,dp);
        }
        else{
            int a=sol(i+1,j,s1,s2,dp);
            int b=sol(i,j+1,s1,s2,dp);
            int c=sol(i+1,j+1,s1,s2,dp);
            ans=max({a,b,c});
        }
        return dp[i][j]=ans;
        
    }
    int minimumDeleteSum(string s1, string s2) {
        int n=s1.size();
        int a1=0;
        int m=s2.size();
        int a2=0;
        for(int i=0;i<n;i++){
            a1+=97+(s1[i]-'a');
        }
        for(int i=0;i<m;i++){
            a2+=97+(s2[i]-'a');
        }
        vector<vector<int>>dp(n,vector<int>(m,-1));
        int ans=sol(0,0,s1,s2,dp);
        ans=a1+a2-ans;
        return ans;
        
        
    }
};