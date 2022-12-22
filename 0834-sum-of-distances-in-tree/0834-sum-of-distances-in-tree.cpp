class Solution {
public:
    int sol(int i,vector<vector<int>>&g,vector<bool>&vis,vector<int>&dp,int p){
        if(vis[i]){
            return 0;
        }
        
        vis[i]=true;
        for(auto j:g[i]){
            if(j==p){
                continue;
            }
            dp[i]+=sol(j,g,vis,dp,i);
            
        }
        return dp[i];
        
    }
    void sol_imp(int i,vector<vector<int>>&g,vector<int>&dp,int p,vector<int>&ans){
        if(p==-1){
            for(auto j:g[i]){
                sol_imp(j,g,dp,i,ans);
            }
            return;
        }
        int n=ans.size();
      //  cout<<p<<endl;
        ans[i]=(ans[p]-dp[i])+(n-dp[i]);
        for(auto j:g[i]){
            if(j==p){
                continue;
            }
                sol_imp(j,g,dp,i,ans);
        }
        return;
        
        
    }
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>>g(n);
        for(int i=0;i<edges.size();i++){
            g[edges[i][0]].push_back(edges[i][1]);
            
            g[edges[i][1]].push_back(edges[i][0]);
        }
        vector<int>ans(n);
        vector<int>dp(n,1);
        vector<bool>vis(n,false);
        queue<int>q;
        q.push(0);
        vector<bool>v(n,false);
        v[0]=true;
        int l=0;
        while(!q.empty()){
            ans[0]+=l*(q.size());
            int len=q.size();
            
            for(int i=0;i<len;i++){
                auto h=q.front();
                q.pop();
                for(auto j:g[h]){
                    if(v[j]){
                        continue;
                    }
                    v[j]=true;
                    q.push(j);
                }
            }
            l++;
            
            
        }
        //cout<<ans[0]<<endl;
        sol(0,g,vis,dp,-1);
     /*   for(int i=0;i<n;i++){
            cout<<dp[i]<<" ";
        }*/
        cout<<endl;
        sol_imp(0,g,dp,-1,ans);
        
        return ans;
        
        
    }
};