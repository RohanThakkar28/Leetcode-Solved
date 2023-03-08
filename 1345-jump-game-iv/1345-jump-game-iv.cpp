class Solution {
public:
    int minJumps(vector<int>& arr) {
        unordered_map<int,vector<int>>m;
        for(int i=0;i<arr.size();i++){
            m[arr[i]].push_back(i);
        }
        queue<pair<int,int>>q;
        q.push({0,0});
        int n=arr.size();
        vector<int>dist(n,1e9);
        int ans=1e9;
        while(!q.empty()){
            auto it=q.front();
            int x=it.first;
            int d=it.second;
            q.pop();
            if(x==n-1){
                ans=d;
                break;
            }
            if(x<0){
                continue;
            }
            if(dist[x]<=(d)){
                continue;
                
            }
            dist[x]=d;
            q.push({x-1,d+1});
            q.push({x+1,d+1});
            vector<int>a=m[arr[x]];
            for(auto i:a){
                q.push({i,d+1});
            }
            m[arr[x]].clear();
           
            
        }
        return ans;
        
    }
};