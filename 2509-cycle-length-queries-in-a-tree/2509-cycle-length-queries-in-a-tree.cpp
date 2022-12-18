class Solution {
public:
    vector<int> cycleLengthQueries(int n, vector<vector<int>>& queries) {
        vector<int>an;
        for(int i=0;i<queries.size();i++){
            int s=queries[i][0];
            int g=queries[i][1];
            if(s>g){
                int tmp=g;
                g=s;
                s=tmp;
            }
            unordered_map<int,int>c;
            int ans=0;
            int ds=s;
            int dg=g;
            int p;
            while(ds!=0){
                c[ds]++;
                ds=ds/2;
                
            }
            while(c[dg]==0){
                dg=dg/2;
                p=dg;
            }
           // cout<<p<<endl;
            while(s!=p){
                ans++;
                s/=2;
            }
            while(g!=p){
                ans++;
                g/=2;
            }
            
            
            an.push_back(ans+1);
            
        }
        return an;
        
        
    }
};