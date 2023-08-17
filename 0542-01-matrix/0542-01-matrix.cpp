class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        vector<vector<int>>ans(n,vector<int>(m,1e9));
        queue<pair<int,pair<int,int>>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0){
                    q.push({i,{j,0}});
                }
            }
        }
        while(q.size()>0){
            int x=q.front().first;
            int y=q.front().second.first;
            int d=q.front().second.second;
            q.pop();
            if(x==n || y==m ||x<0 ||y<0){
                continue;
            }
            if(ans[x][y]>d){
                ans[x][y]=d;
                 q.push({x+1,{y,d+1}});
                q.push({x-1,{y,d+1}});
                q.push({x,{y+1,d+1}});
                q.push({x,{y-1,d+1}});
            }
           
        }
        return ans;
        
    }
};