#define ll long long int
class Solution {
public:
    
    int numberOfWays(int n) {
        vector<ll>dp(n+1,0);
        dp[0]=1;
        int mod=1e9+7;
        for(int i=2;i<=n;i++){
            for(int j=0;j<=i-2;j++){
              //  cout<<i<<" "<<j<<endl;
                dp[i]+=(ll)((dp[j]%mod)*(dp[i-j-2]%mod));
                dp[i]%=mod;
            }
        }
        return dp[n];
        
    }
};