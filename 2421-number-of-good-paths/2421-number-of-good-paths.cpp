class Solution {
public:
    
    int find_par(int i,vector<int>&par){
        if(par[i]!=i){
            return find_par(par[i],par);
        }
        return i;
    }
    void join(int u,int v,vector<int>&par){
        int pu=find_par(u,par);
        int pv=find_par(v,par);
        if(pu<pv){
            par[pv]=pu;
        }
        else{
            par[pu]=pv;
        }
    }
    
    int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
        int n=vals.size();
        vector<vector<int>>g(n);
        for(int i=0;i<edges.size();i++){
            g[edges[i][0]].push_back(edges[i][1]);
            g[edges[i][1]].push_back(edges[i][0]);
        }
        map<int,vector<int>>v;
        for(int i=0;i<vals.size();i++){
            v[vals[i]].push_back(i);
        }
        vector<int>par(n);
        int miny=1e9;
        int node=0;
        for(int i=0;i<vals.size();i++){
            if(miny<vals[i]){
                miny=vals[i];
                node=i;
            }
        }
        for(int i=0;i<n;i++){
            par[i]=i;
        }
        int ans=0;
        for(auto i:v){
            vector<int>a=i.second;
           /// cout<<a.size()<<endl;
            for(int j=0;j<a.size();j++){
            //    cout<<a[j]<<endl;
                for(int k=0;k<g[a[j]].size();k++){
                    if(vals[a[j]]>=vals[g[a[j]][k]]){
                       // cout<<a[j]<<" "<<g[a[j]][k]<<endl;
                        join(a[j],g[a[j]][k],par);
                    }
                    
                }
            //    cout<<endl;
            }
            map<int,int>pp;
            for(int j=0;j<a.size();j++){
                pp[find_par(a[j],par)]++;
            }
            for(auto j:pp){
                ans+=(((j.second)*(j.second-1))/2);
            }
        }
        return n+ans;
        
    }
};