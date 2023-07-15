class Solution {
public:
    int sol(int i,int k,vector<vector<int>>& events,vector<vector<int>>&dp){
        if(k==0){
            return 0;
        }
        int n=events.size();
        if(i==n){
            return 0;
        }
        if(dp[i][k]!=-1){
            return dp[i][k];
        }
        int id=i+1;
        while(id<n && events[id][0]<=events[i][1]){
            id++;
        }
        int a=events[i][2]+sol(id,k-1,events,dp);
        int b=sol(i+1,k,events,dp);
        return dp[i][k]=max({a,b});
    }
    int maxValue(vector<vector<int>>& events, int k) {
        int n=events.size();
        vector<vector<int>>dp(n,vector<int>(k+1,-1));
        sort(events.begin(),events.end());
        int ans=sol(0,k,events,dp);
        return ans;
        
        
    }
};