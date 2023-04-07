class Solution {
public:
        void sol(int i,int j,vector<vector<bool>>&vis,vector<vector<int>>&grid,bool &z,int & c){
        int n=grid.size();
        int m=grid[0].size();
        if(i==n || j==m || i==-1 ||j==-1){
            return;
        }
        if(vis[i][j]){
            return;
        }
        vis[i][j]=true;
        
        if(grid[i][j]==0){
            return;
        }
        if(i+1==n || j+1==m || i==0 || j==0){
            z=true;
        }
        c++;
        sol(i+1,j,vis,grid,z,c);
        
        sol(i-1,j,vis,grid,z,c);
        sol(i,j+1,vis,grid,z,c);
        sol(i,j-1,vis,grid,z,c);
        
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<bool>>vis(n,vector<bool>(m,false));
        int f=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    int ans=0;
                    bool ye=false;
                    sol(i,j,vis,grid,ye,ans);
                    if(!ye){
                        f+=ans;
                        
                    }
                }
                
            }
        }
        return f;
        
    }
};