class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        int ans=0;
        
        vector<int>rank(n,0);
        
        set<pair<int,int>>s;
        for(int i=0;i<roads.size();i++){
            rank[roads[i][0]]++;
            rank[roads[i][1]]++;
            s.insert({roads[i][0],roads[i][1]});
            s.insert({roads[i][1],roads[i][0]});
        }
        for(int i=0;i<n;i++){
            
            for(int j=i+1;j<n;j++){
               auto it=s.find({i,j});
                if(it==s.end()){
                    ans=max(ans,rank[i]+rank[j]);
                }
                else{
                    ans=max(ans,rank[i]+rank[j]-1);
                    
                }
               
            }
            
        }
        return ans;
        
    }
};