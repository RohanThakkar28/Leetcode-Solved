class Solution {
public:
    void sol(int i,vector<vector<int>>&g,vector<bool>&vis,vector<int>&v){
        if(vis[i]){
            return;
        }
        vis[i]=true;
        v.push_back(i);
        for(auto u:g[i]){
            sol(u,g,vis,v);
        }
        
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>>g(n);
        vector<vector<bool>>c(n,vector<bool>(n,false));
        for(auto e:edges){
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
            c[e[0]][e[1]]=true;
            c[e[1]][e[0]]=true;
        }
        vector<bool>vis(n,false);
        int ans=0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                vector<int>v;
                sol(i,g,vis,v);
                bool ye=true;
                for(int j=0;j<v.size();j++){
                    for(int k=j+1;k<v.size();k++){
                        if(c[v[j]][v[k]]==false){
                            ye=false;
                        }
                        
                    }
                }
                if(ye){
                    ans++;
                }
                
                
            }
        }
        return ans;
    }
};