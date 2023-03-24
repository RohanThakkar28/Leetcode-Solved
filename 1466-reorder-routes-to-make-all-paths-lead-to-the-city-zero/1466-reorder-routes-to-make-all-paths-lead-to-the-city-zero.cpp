class Solution {
public:
    int ans=0;
    void sol(int i,vector<vector<int>>&in,vector<vector<int>>&out,int prev,vector<bool>&vis){
        if(vis[i]){
            return;
        }
        vis[i]=true;
        //cout<<i<<endl;
        
        for(auto j:in[i]){
            
            
           
            sol(j,in,out,i,vis);
            
        }
        for(auto j:out[i]){
            if(vis[j]){
                continue;
            }
            ans++;
            //cout<<j<<" c"<<endl;
            sol(j,in,out,i,vis);
        }
        
    }
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<int>>in(n);
        vector<vector<int>>out(n);
        for(auto v:connections){
            in[v[1]].push_back(v[0]);
            out[v[0]].push_back(v[1]);
        }
        vector<bool>vis(n,false);
        sol(0,in,out,-1,vis);
        return ans;
        
        
        
    }
};