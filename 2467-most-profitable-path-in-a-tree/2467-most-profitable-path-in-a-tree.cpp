class Solution {
public:
    void par(int i,int pa,vector<vector<int>>&g,map<int,int>&p){
        p[i]=pa;
        for(auto j:g[i]){
            if(j==pa){
                continue;
            }
            par(j,i,g,p);
        }
        
    }
    int sol(int i,int bob,vector<vector<int>>&g,vector<int>&a,int pa,map<int,int>&p){
        int r;
        if(i==bob){
            r=a[i]/2;
        }
        else{
            r=a[i];
        }
        int tmp=a[bob];
        a[bob]=0;
      //  cout<<i<<" "<<bob<<endl;
        int ans=-1e9;
        int c=0;
        int cbob=bob;
        bob=p[bob];
    
        for(auto j:g[i]){
            if(j==pa){
                continue;
            }
            c++;
            int a1=r+sol(j,bob,g,a,i,p);
            ans=max(ans,a1);
            
        }
        
        bob=cbob;
        a[bob]=tmp;
        if(c==0){
            return r;
        }
    
        return ans;
        
        
    }
    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        map<int,int>p;
    
        int n=amount.size();
        vector<vector<int>>g(n);
        for(int i=0;i<edges.size();i++){
            g[edges[i][0]].push_back(edges[i][1]);
            g[edges[i][1]].push_back(edges[i][0]);
        }
        par(0,0,g,p);
        
        int ans=sol(0,bob,g,amount,0,p);
        return ans;
        
    }
};