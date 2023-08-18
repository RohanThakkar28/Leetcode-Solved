class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        int ans=0;
        vector<vector<int>>g(n);
        for(int i=0;i<roads.size();i++){
            g[roads[i][0]].push_back(roads[i][1]);
            g[roads[i][1]].push_back(roads[i][0]);
        }
        for(int i=0;i<n;i++){
            
            for(int j=i+1;j<n;j++){
                set<pair<int,int>>s;
                for(int k=0;k<g[i].size();k++){
                    int u=g[i][k];
                    if(u<i){
                        s.insert({u,i});
                    }
                    else{
                        s.insert({i,u});
                    }
                }
                for(int k=0;k<g[j].size();k++){
                    int u=g[j][k];
                    if(u<j){
                        s.insert({u,j});
                    }
                    else{
                        s.insert({j,u});
                    }
                }
                //cout<<i<<" "<<j<<" "<<s.size()<<endl;
                ans=max(ans,(int)s.size());
                
            }
            
        }
        return ans;
        
    }
};