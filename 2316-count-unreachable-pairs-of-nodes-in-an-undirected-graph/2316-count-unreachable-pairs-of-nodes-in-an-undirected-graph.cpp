class Solution {
public:
    
    int dfs(int node,vector<vector<int>>& graph,vector<bool>& visited){
        if(visited[node]){
            return 0;
        }
        visited[node]=true;
        int num=1;
        for(int i=0;i<graph[node].size();i++){
            num+=dfs(graph[node][i],graph,visited);
        }
        return num;
    }
    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<int>ans;
        long long int sum=0;
        //graph.resize(n);
        vector<vector<int>>graph(n);
        for(int i=0;i<edges.size();i++){
            graph[edges[i][0]].push_back(edges[i][1]);
            
            graph[edges[i][1]].push_back(edges[i][0]);
        }
        vector<bool>visited(n,false);
        for(int i=0;i<n;i++){
            if(!visited[i]){
                ans.push_back(dfs(i,graph,visited));
            }
        }
        sort(ans.begin(),ans.end());
        vector<long long int>dp(ans.size());
        for(int i=0;i<ans.size();i++){
            if(i-1>=0 && ans[i]==ans[i-1]){
                sum+=(long long int)dp[i-1]-(long long int)ans[i]*ans[i];
                dp[i]=dp[i-1]-(long long int)ans[i]*ans[i];
                continue;
            }
            long long int temp=0;
            for(int j=i+1;j<ans.size();j++){
                sum+=(long long int)ans[i]*ans[j];
                temp+=(long long int)ans[i]*ans[j];
                
            }
            dp[i]=temp;
        }
        return sum;
    }
};