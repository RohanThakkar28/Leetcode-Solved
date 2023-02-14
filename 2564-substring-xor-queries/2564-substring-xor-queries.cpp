class Solution {
public:
    vector<vector<int>> substringXorQueries(string s, vector<vector<int>>& queries) {
        map<int,pair<int,int>>m;
        set<int>st;
        int n=s.size();
        for(int i=0;i<n;i++){
            int bin=0;
            
            
            for(int k=i;k<=i+30;k++){
                if(k==n){
                    break;
                }
                bin*=2;
                if(s[k]=='1'){
                    bin+=1;
                    
                }
                //cout<<i<<" "<<k<<" "<<bin<<endl;
                
                
                
    
                if(st.find(bin)==st.end()){
                    m[bin]={i,k};
                    st.insert(bin);
                }
                else{
                    int l=m[bin].first;
                    int r=m[bin].second;
                    if(r-l+1>k-i+1){
                        m[bin]={i,k};
                    }
                }
                
            }
        }
        vector<vector<int>>ans;
        for(int i=0;i<queries.size();i++){
            int xo=(queries[i][0]^queries[i][1]);
            if(m.find(xo)!=m.end()){
                vector<int>v;
                v.push_back(m[xo].first);
                
                v.push_back(m[xo].second);
                ans.push_back(v);
                
            }
            else{
                vector<int>v;
                v.push_back(-1);
                
                v.push_back(-1);
                ans.push_back(v);
            }
        }
        return ans;
        
    }
};