#define ll long long int
class Solution {
public:
    int mod=1e9+7;
    int sol(int i,ll n,int x,vector<vector<int>>&dp){
        //cout<<i<<" "<<n<<endl;
        
        if(n==0){
            return 1;
        }
        if(n<0){
            return 0;
        }
        if(i>n){
            return 0;
        }
        if(dp[i][n]!=-1){
            return dp[i][n];
        }
         ll red=1;
        for(int j=0;j<x;j++){
            red*=(ll)i;
        }
       
        int a=sol(i+1,n-red,x,dp)%mod;
        int b=sol(i+1,n,x,dp)%mod;
        return dp[i][n]=(a+b)%mod;
    }
    int numberOfWays(int n, int x) {
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return sol(1,n,x,dp);
        
        
        
    }
};