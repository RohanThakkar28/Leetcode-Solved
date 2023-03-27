class Solution {
public:
    int ans=-1;
    void sol(int i,vector<vector<int>>&g,map<int,int>&c,vector<bool>&vis,int id){
       // cout<<i<<endl;
        if(vis[i]){
            if(c.find(i)!=c.end()){
              //  cout<<"hi"<<endl;
                ans=max(ans,id-c[i]);
            //    cout<<ans<<endl;
                
            }
            
            return;
        }
        vis[i]=true;
        c[i]=id;
        
        for(auto j:g[i]){
            sol(j,g,c,vis,id+1);
        }
       
        
        
    }
    int longestCycle(vector<int>& edges) {
        int n=edges.size();
        vector<vector<int>>g(n);
        for(int i=0;i<n;i++){
            if(edges[i]==-1){
                continue;
            }
            g[i].push_back(edges[i]);
        }
        
        vector<bool>vis(n,false);
        for(int i=0;i<n;i++){
            if(vis[i]){
                 continue;
            }
            map<int,int>c;
            sol(i,g,c,vis,0);
            
        }
        return ans;
        
        
    }
};