class Solution {
public:
    int sol(int i,int j,vector<vector<int>>&dp,vector<vector<int>>& grid){
        int n=grid.size();
        int m=grid[0].size();
        if(i<0 || j<0 || i==n || j==m){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int a=0;
        int b=0;
        int c=0;
        if(i-1>=0 && j+1<m && grid[i-1][j+1]>grid[i][j]){
            a=1+sol(i-1,j+1,dp,grid);
        }
        if(j+1<m && grid[i][j+1]>grid[i][j]){
            b=1+sol(i,j+1,dp,grid);
            
            
        }
        if(i+1<n && j+1<m && grid[i+1][j+1]>grid[i][j]){
            c=1+sol(i+1,j+1,dp,grid);
        }
        
        return dp[i][j]=max({a,b,c});
        
    }
    int maxMoves(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        int ans=0;
        for(int i=0;i<n;i++){
            
            ans=max(ans,sol(i,0,dp,grid));
            //cout<<sol(0,j,dp,grid)<<endl;
            
        }
        return ans;
    }
};