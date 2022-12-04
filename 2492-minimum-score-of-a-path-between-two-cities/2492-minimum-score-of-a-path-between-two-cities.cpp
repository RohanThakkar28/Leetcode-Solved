class Solution {
public:
    int ans=1e9;
    void sol(int i,vector<bool>&vis,vector<vector<pair<int,int>>>&g){
        if(vis[i]){
            return;
        }
        vis[i]=true;
        for(auto it:g[i]){
            ans=min(it.second,ans);
            sol(it.first,vis,g);
        }
    }
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>>g(n+1);
        for(int i=0;i<roads.size();i++){
            int v=roads[i][0];
            int u=roads[i][1];
            int w=roads[i][2];
            g[u].push_back({v,w});
            
            g[v].push_back({u,w});
        }
        vector<bool>vis(n+1,false);
        sol(1,vis,g);
        return ans;
        
    }
};