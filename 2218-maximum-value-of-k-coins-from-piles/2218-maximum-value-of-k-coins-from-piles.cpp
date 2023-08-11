class Solution {
public:
    int sol(int i,int rem,vector<vector<int>>&piles,vector<vector<int>>&dp){
        int n=piles.size();
        if(rem==0){
            return 0;
        }
        if(i==n){
            return -1e9;
        }
        if(dp[i][rem]!=-1){
            return dp[i][rem];
        }
        int maxy=-1e9;
        for(int j=0;j<min((int)piles[i].size(),rem);j++){
            int tmp=piles[i][j]+sol(i+1,rem-j-1,piles,dp);
            maxy=max(maxy,tmp);
        }
        int tmp=sol(i+1,rem,piles,dp);
        maxy=max(maxy,tmp);
        return dp[i][rem]=maxy;
    }
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        for(int i=0;i<piles.size();i++){
            for(int j=1;j<piles[i].size();j++){
                piles[i][j]+=piles[i][j-1];
            }
            // for(int j=0;j<piles[i].size();j++){
            //     cout<<piles[i][j]<<" ";
            // }
            // cout<<endl;
        }
        int n=piles.size();
        vector<vector<int>>dp(n,vector<int>(k+1,-1));
        int ans=sol(0,k,piles,dp);
        return ans;
    }
};