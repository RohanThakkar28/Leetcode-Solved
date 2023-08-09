class Solution {
public:
    bool ans=false;
    void bfs(int i,int j,vector<vector<char>>& grid,vector<vector<bool>>&vis){
        int n=grid.size();
        int m=grid[0].size();
         
        queue<pair<pair<int,int>,pair<int,int>>>q;
        q.push({{i,j},{-1,-1}});
        char c=grid[i][j];
        while(q.size()>0){
            int x=q.front().first.first;
            int y=q.front().first.second;
            int px=q.front().second.first;
            int py=q.front().second.second;
           
            q.pop();
            if(x>=n || y>=m || x<0 || y<0){
                continue;
            }
            if(grid[x][y]!=c){
                continue;
            }
            // cout<<x<<" "<<y<<" "<<px<<" "<<py<<" "<<c<<endl;
            if(vis[x][y]){
                //cout<<x<<" "<<y<<" "<<c<<endl;
                ans=true;
                break;
            }
            
            vis[x][y]=true;
            if((x+1)!=px ||  y!=py){
                q.push({{x+1,y},{x,y}});
            }
            if((x-1)!=px ||  y!=py){
                q.push({{x-1,y},{x,y}});
            }
            if(x!=px ||  (y+1)!=py){
                q.push({{x,y+1},{x,y}});
            }
            if(x!=px ||  (y-1)!=py){
                q.push({{x,y-1},{x,y}});
            }
            
        }
        return;
    }
    bool containsCycle(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<bool>>vis(n,vector<bool>(m,false));
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vis[i][j]==false){
              //     cout<<i<<" "<<j<<endl;
                    bfs(i,j,grid,vis);
                }
            }
        }
        return ans;
        
    }
};