#define ll long long int
class Solution {
public:
    vector<int> successfulPairs(vector<int>& s, vector<int>& p, long long succ) {
        int n=s.size();
        int m=p.size();
        
        sort(p.begin(),p.end());
        vector<int>ans;
        for(int i=0;i<n;i++){
            ll l=0;
            ll r=m-1;
            ll id=m;
            while(l<=r){
                ll m1=l+(r-l)/2;
                ll pro=(ll)((ll)(p[m1])*(ll)s[i]);
                if(pro>=succ){
                    id=m1;
                    r=m1-1;
                    
                    
                }
                else{
                    l=m1+1;
                }
            }
            ans.push_back(m-id);
            
        }
        return ans;
        
        
    }
};