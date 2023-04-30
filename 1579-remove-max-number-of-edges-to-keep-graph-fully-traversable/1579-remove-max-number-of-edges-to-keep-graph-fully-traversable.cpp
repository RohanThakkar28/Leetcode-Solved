class Solution {
public:
    static bool comp(vector<int>&a,vector<int>&b){
        return a[0]>b[0];
    }
    int findp(vector<int>&p,int node){
        while(p[node]!=node){
            node=p[node];
        }
        return node;
    }
    int maxNumEdgesToRemove(int n, vector<vector<int>>& e) {
        vector<int>a_p(n+1);
        vector<int>a_r(n+1,1);
        vector<int>b_p(n+1);
        vector<int>b_r(n+1,1);
        for(int i=1;i<=n;i++){
            a_p[i]=i;
            b_p[i]=i;
        }
        sort(e.begin(),e.end(),comp);
        int ans=0;
        for(int i=0;i<e.size();i++){
            if(e[i][0]==3){
                int a=e[i][1];
                int b=e[i][2];
                int pa=findp(a_p,a);
                int pb=findp(a_p,b);
                if(pa==pb){
                    ans++;
                }
                else{
                    if(a_r[pa]>a_r[pb]){
                        a_p[pb]=pa;
                        a_r[pa]+=a_r[pb];
                        b_p[pb]=pa;
                        b_r[pa]+=b_r[pb];
                    }
                    else{
                        a_p[pa]=pb;
                        a_r[pb]+=a_r[pa];
                        b_p[pa]=pb;
                        b_r[pb]+=b_r[pa];
                        
                    }
                }
            }
            else if(e[i][0]==2){
                int a=e[i][1];
                int b=e[i][2];
                int pa=findp(b_p,a);
                int pb=findp(b_p,b);
                if(pa==pb){
                    ans++;
                }
                else{
                    if(b_r[pa]>b_r[pb]){
                        
                        b_p[pb]=pa;
                        b_r[pa]+=b_r[pb];
                    }
                    else{
                        b_p[pa]=pb;
                        b_r[pb]+=b_r[pa];
                        
                    }
                }
                
            }
            else{
                int a=e[i][1];
                int b=e[i][2];
                int pa=findp(a_p,a);
                int pb=findp(a_p,b);
                if(pa==pb){
                    ans++;
                }
                else{
                    if(a_r[pa]>a_r[pb]){
                        a_p[pb]=pa;
                        a_r[pa]+=a_r[pb];
                        
                    }
                    else{
                        a_p[pa]=pb;
                        a_r[pb]+=a_r[pa];
                
                        
                    }
                }
                
            }
        }
    
        int maxy1=0;
        for(int i=1;i<=n;i++){
            maxy1=max(maxy1,a_r[i]);
            
        }
        int maxy2=0;
        for(int i=1;i<=n;i++){
            maxy2=max(maxy2,b_r[i]);
            
        }
        if(maxy1==n && maxy2==n){
            return ans;
        }
        return -1;
        
        
    }
};