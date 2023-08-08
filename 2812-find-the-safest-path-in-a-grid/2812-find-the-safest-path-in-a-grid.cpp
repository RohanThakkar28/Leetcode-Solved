class Solution {
public:
    void bfs(vector<vector<int>>& grid,vector<vector<bool>>&vis,int x){
        int n=grid.size();
        queue<pair<int,pair<int,int>>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                  //  cout<<i<<" "<<j<<endl;
                    q.push({i,{j,x}});
                }
            }
        }
        while(!q.empty()){
            int x=q.front().first;
            int y=q.front().second.first;
            int d=q.front().second.second;
            
            q.pop();
           // cout<<x<<" "<<y<<" "<<d<<endl;
            if(x>=n || y>=n || x<0 || y<0){
                continue;
            }
            if(vis[x][y]==true || d==0){
                continue;
            }
            vis[x][y]=true;
            q.push({x+1,{y,d-1}});
            q.push({x-1,{y,d-1}});
            q.push({x,{y+1,d-1}});
            q.push({x,{y-1,d-1}});
        }
        return;
    }
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n=grid.size();
      //  cout<<n<<endl;
        vector<pair<int,int>>a;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    
                    a.push_back({i,j});
                    
                }
            }
        }
        int l=0;
        int r=n;
        int ans=0;
        while(l<=r){
            
           vector<vector<bool>>vis(n,vector<bool>(n,false));
         
            
            int m=l+(r-l)/2;
            bfs(grid,vis,m);
           // cout<<m<<endl;
            queue<pair<int,int>>q;
            q.push({0,0});
            bool ye=false;
            while(q.size()>0){
                int x=q.front().first;
                int y=q.front().second;
                q.pop();
                if(x>=n || y>=n || x<0 || y<0){
                    continue;
                }
                if(vis[x][y]==true){
                    continue;
                }
                vis[x][y]=true;
                int dist=1e9;
                if(dist>=m){
                    if(x==n-1 && y==n-1){
                        ye=true;
                        break;
                    }
                    q.push({x+1,y});
                    q.push({x-1,y});
                    q.push({x,y+1});
                    q.push({x,y-1});
                }
                else{
                    continue;
                }
                
            }
            if(ye){
                ans=m;
                l=m+1;
            }
            else{
                r=m-1;
            }
            
        }
        return ans;
        
    }
};