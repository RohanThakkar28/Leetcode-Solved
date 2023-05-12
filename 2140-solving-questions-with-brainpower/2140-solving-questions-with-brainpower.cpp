#define ll long long int
class Solution {
public:
    ll sol(int i,vector<vector<int>>& questions,vector<ll>&dp){
        int n=questions.size();
        if(i>=n){
            return 0;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        ll a=questions[i][0]+sol(i+questions[i][1]+1,questions,dp);
        ll b=sol(i+1,questions,dp);
        return dp[i]=max({a,b});
    }
    long long mostPoints(vector<vector<int>>& questions) {
        vector<ll>dp(questions.size(),-1);
        ll ans=sol(0,questions,dp);
        return ans;
        
    }
};