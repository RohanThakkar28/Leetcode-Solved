#define ll long long int
class Solution {
public:
    ll sol(int gain,int mask,vector<int>&p,vector<vector<ll>>&dp){
       
        int n=p.size();
         if((mask)==(1<<n)-1){
            return 0;
        }
        if(dp[mask][gain]!=-1){
            return dp[mask][gain];
        }
        ll ans=1e18;
        for(int i=0;i<n;i++){
            if(((1<<i)&(mask))==0){
                int m=p[i]/gain;
                if(p[i]%gain!=0){
                    m++;
                }
                ll c=m+sol(gain+1,((mask)|(1<<i)),p,dp);
                ans=min(ans,c);
                
            }
        }
        return dp[mask][gain]=ans;
    }
    long long minimumTime(vector<int>& power) {
        int n=power.size();
        vector<vector<ll>>dp(1<<n,vector<ll>(n+1,-1));
        ll ans=sol(1,0,power,dp);
        return ans;
        
    }
};