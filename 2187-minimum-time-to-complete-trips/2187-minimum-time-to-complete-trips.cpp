#define ll long long int
class Solution {
public:
    long long minimumTime(vector<int>& time, int tot) {
        ll l=1;
        ll r=1e18;
        ll ans=r;
        while(l<=r){
            ll m=(l+r)/2;
            ll c=0;
            for(int i=0;i<time.size();i++){
                if(m/time[i]>=tot){
                    c=tot;
                    break;
                }
                c+=(m/time[i]);
                
            }
            if(c>=tot){
                ans=m;
                r=m-1;
            }
            else{
                l=m+1;
            }
        }
        return ans;
        
    }
};