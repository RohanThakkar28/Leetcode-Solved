class Solution {
public:
    void sol(int i,int j,vector<vector<bool>>&vis,vector<vector<int>>&grid,bool &z){
        int n=grid.size();
        int m=grid[0].size();
        if(i==n || j==m || i==-1 ||j==-1){
            return;
        }
        if(vis[i][j]){
            return;
        }
        vis[i][j]=true;
        
        if(grid[i][j]==1){
            return;
        }
        if(i+1==n || j+1==m || i==0 || j==0){
            z=true;
        }
        
        sol(i+1,j,vis,grid,z);
        
        sol(i-1,j,vis,grid,z);
        sol(i,j+1,vis,grid,z);
        sol(i,j-1,vis,grid,z);
        
    }
    int closedIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int ans=0;
        vector<vector<bool>>vis(n,vector<bool>(m,false));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==0 && vis[i][j]==false){
                    bool z=false;
                    sol(i,j,vis,grid,z);
                    if(z==false){
                        ans++;
                    }
                    
                }
            }
        }
        return ans;
        
    }
};