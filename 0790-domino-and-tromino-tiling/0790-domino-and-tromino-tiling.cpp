
class Solution {
public:
    const int mod=1e9+7;
    int sol(int i,int n,vector<int>&dp){
        if(i>n){
            return 0;
        }
        if(i==n){
            return 1;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        int ans=0;
        for(int j=1;j<=1000;j++){
            if(j+i>n){
                break;
            }
            if(j==1 || j==2){
                ans+=sol(i+j,n,dp)%mod;
                ans%=mod;
                
            }
            else{
                ans+=2*sol(i+j,n,dp)%mod;
                ans%=mod;
                
            }
        }
        return dp[i]=ans;
    }
    int numTilings(int n) {
        vector<int>dp(n,-1);
        int ans=sol(0,n,dp)%mod;
        return ans%mod;
        
        
    }
};