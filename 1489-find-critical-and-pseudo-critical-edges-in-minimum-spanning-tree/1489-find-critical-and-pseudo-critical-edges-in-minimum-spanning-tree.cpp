class Solution {
public:
    static bool sortcol(const vector<int>& v1, const vector<int>& v2)
{
    return v1[2] < v2[2];
}
    
    int find_p(int i,vector<int>&par){
        while(par[i]!=i){
            return find_p(par[i],par);
        }
        return i;
    }
    void join(int i,int j,vector<int>&par){
        int pi=find_p(i,par);
        int pj=find_p(j,par);
        if(pi<pj){
            par[pj]=pi;
        }
        else{
            par[pi]=pj;
        }
    }
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        vector<int>par(n);
        for(int i=0;i<n;i++){
            par[i]=i;
        }
        map<pair<int,int>,int>eid;
        for(int i=0;i<edges.size();i++){
            eid[{edges[i][0],edges[i][1]}]=i;
                
            eid[{edges[i][1],edges[i][0]}]=i;
        }
        int mst=0;
        sort(edges.begin(),edges.end(),sortcol);
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            if(find_p(u,par)==find_p(v,par)){
                continue;
            }
            mst+=edges[i][2];
            join(u,v,par);
        }
        //cout<<mst<<endl;
        vector<vector<int>>ans;
        vector<int>c;
        vector<int>ps;
        for(int i=0;i<edges.size();i++){
            int tmp=0;
        
            for(int i=0;i<n;i++){
                par[i]=i;
            }
            for(int j=0;j<edges.size();j++){
                if(i==j){
                    continue;
                }
                int u=edges[j][0];
                int v=edges[j][1];
                if(find_p(u,par)==find_p(v,par)){
                    continue;
                }
                tmp+=edges[j][2];
                join(u,v,par);
            }
           // cout<<i<<" "<<tmp<<" "<<mst<<endl;
            bool ye=false;
            for(int j=0;j<n;j++){
                if(find_p(j,par)!=find_p(0,par)){
                    ye=true;
                }
            }
            if(tmp>mst || ye){
                c.push_back(eid[{edges[i][0],edges[i][1]}]);
            }
        }
        ans.push_back(c);
        for(int i=0;i<edges.size();i++){
            int tmp=0;
            for(int i=0;i<n;i++){
                par[i]=i;
            }
            int u=edges[i][0];
            int v=edges[i][1];
            tmp+=edges[i][2];
            join(u,v,par);
            for(int j=0;j<edges.size();j++){
                if(i==j){
                    
                    
                    continue;
                }
                int u=edges[j][0];
                int v=edges[j][1];
                if(find_p(u,par)==find_p(v,par)){
                    continue;
                }
                tmp+=edges[j][2];
                join(u,v,par);
            }
            int tmp1=0;
            for(int i=0;i<n;i++){
                par[i]=i;
            }
            
            for(int j=0;j<edges.size();j++){
                if(i==j){
                    continue;
                }
                int u=edges[j][0];
                int v=edges[j][1];
                if(find_p(u,par)==find_p(v,par)){
                    continue;
                }
                tmp1+=edges[j][2];
                join(u,v,par);
            }
            //cout<<i<<" "<<tmp<<" "<<tmp1<<endl;
            
            if(tmp==mst && tmp1==mst){
                ps.push_back(eid[{edges[i][0],edges[i][1]}]);
            }
        }
        ans.push_back(ps);

        return ans;
    }
};