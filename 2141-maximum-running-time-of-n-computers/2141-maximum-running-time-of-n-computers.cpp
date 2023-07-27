#define ll long long int
class Solution {
public:
    long long maxRunTime(int n, vector<int>& batteries) {
        sort(batteries.begin(),batteries.end());
        ll sum=0;
        int k=batteries.size();
        for(int i=0;i<k-n;i++){
            sum+=(ll)batteries[i];
        }
        ll l=1;
        ll r=1e18;
        ll ans=1;
        while(l<=r){
            ll m=l+(r-l)/2;
            bool ye=true;
            ll ext=sum;
            for(int i=k-n;i<k;i++){
                if(batteries[i]<m && ext<m-batteries[i]){
                    ye=false;
                    break;
                }
                if(batteries[i]<m){
                    ext-=(m-batteries[i]);
                }
                
            }
            if(ye){
                ans=m;
                l=m+1;
            }
            else{
                r=m-1;
            }
            
        }
        return ans;
        
        
    }
};