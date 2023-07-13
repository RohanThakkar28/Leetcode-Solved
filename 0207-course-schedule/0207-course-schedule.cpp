class Solution {
public:
    bool ans=true;
    void sol(int i,vector<vector<int>>&g,vector<bool>&vis,map<int,int>&c){
        
        
        
        if(c[i]>0){
            ans=false;
            return;
        }
        if(vis[i]==true){
            return;
        }
        vis[i]=true;
        c[i]=1;
        for(auto j:g[i]){
            sol(j,g,vis,c);
        }
        c[i]=0;
        
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>g(numCourses);
        for(auto v:prerequisites){
            g[v[0]].push_back(v[1]);
        }
        vector<bool>vis(numCourses,false);
        for(int i=0;i<numCourses;i++){
            map<int,int>c;
            sol(i,g,vis,c);
            
        }
        return ans;
    }
};