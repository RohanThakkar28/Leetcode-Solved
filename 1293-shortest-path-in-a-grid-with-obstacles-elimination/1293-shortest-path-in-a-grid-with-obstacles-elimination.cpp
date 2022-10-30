class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        queue<pair<pair<int,int>,pair<int,int>>>q;
        q.push({{0,0},{k,0}});
        int n=grid.size();
        int m=grid[0].size();
        
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(m,vector<int>(k+1,1e9)));
        
        
        int ans=0;
        while(!q.empty()){
            
            
                auto it=q.front();
                q.pop();
                int x=it.first.first;
                int y=it.first.second;
                int k1=it.second.first;
                int c=it.second.second;
               // int py=it.second.second.second;
               /// cout<<x<<" "<<y<<endl;
                if(x<0 || y<0 || x>=n || y>=m){
                    continue;
                }
                if(grid[x][y]==1){
                    k1--;
                }
                if(k1<0){
                    continue;
                }
                if(dp[x][y][k1]>c){
                    dp[x][y][k1]=c;
                    q.push({{x+1,y},{k1,c+1}});
                
                    q.push({{x-1,y},{k1,c+1}});

                    q.push({{x,y+1},{k1,c+1}});

                    q.push({{x,y-1},{k1,c+1}});

                }
                
                
            
            
        }
        int ans1=1e9;
        for(int i=0;i<=k;i++){
            ans1=min(ans1,dp[n-1][m-1][i]);
        }
        if(ans1==1e9){
            return -1;
        }
        return ans1;
        
        
    }
};