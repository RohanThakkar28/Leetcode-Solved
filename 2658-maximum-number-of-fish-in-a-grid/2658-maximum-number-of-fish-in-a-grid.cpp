class Solution {
public:
    int sol(int i,int j,vector<vector<int>>&grid,vector<vector<bool>>&vis){
        int n=grid.size();
        int m=grid[0].size();
        if(i<0 || j<0 || i==n || j==m){
            return 0;
        }
        if(grid[i][j]==0){
            return 0;
        }
        if(vis[i][j]){
            return 0;
        }
        vis[i][j]=true;
        int a=sol(i-1,j,grid,vis);
        
        int b=sol(i+1,j,grid,vis);
        int c=sol(i,j-1,grid,vis);
        int d=sol(i,j+1,grid,vis);
        return a+b+c+d+grid[i][j];
    }
    int findMaxFish(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<bool>>vis(n,vector<bool>(m,false));
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vis[i][j]){
                    continue;
                }
                ans=max(ans,sol(i,j,grid,vis));
            }
        }
        return ans;
        
        
        
    }
};