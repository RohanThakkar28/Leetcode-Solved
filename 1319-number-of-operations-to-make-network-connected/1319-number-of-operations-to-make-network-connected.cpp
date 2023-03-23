class Solution {
public:
    void sol(int i,vector<bool>&vis,vector<vector<int>>&g){
        if(vis[i]){
            return;
        }
        vis[i]=true;
        for(auto j:g[i]){
            sol(j,vis,g);
        }
    }
    int makeConnected(int n, vector<vector<int>>& c) {
        if(c.size()<n-1){
            return -1;
        }
        vector<bool>vis(n,false);
        vector<vector<int>>g(n);
        for(int i=0;i<c.size();i++){
            
            g[c[i][0]].push_back(c[i][1]);
            
            g[c[i][1]].push_back(c[i][0]);
            
        }
        int c1=0;
        for(int i=0;i<n;i++){
           
            if(!vis[i]){
                c1++;
                sol(i,vis,g);
            }
        }
        return c1-1;
        
    }
};