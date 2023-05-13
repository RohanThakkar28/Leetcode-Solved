class Solution {
public:
    const int mod=1e9+7;
    int sol(int c,int z,int o,int t1,int t2,vector<int>&dp){
        
        if(c>t2){
            return 0;
        }
        
        if(c==t2){
            return 1;
        }
        if(dp[c]!=-1){
            return dp[c];
        }
        int a=sol(c+z,z,o,t1,t2,dp)%mod;
        int b=sol(c+o,z,o,t1,t2,dp)%mod;
        if(c>=t1 && c<=t2){
            
            return dp[c]=(1+a+b)%mod;
            
        }
        else{
            return dp[c]=(a+b)%mod;
        }
    }
    int countGoodStrings(int low, int high, int zero, int one) {
        //vector<int>dp1(low+1,-1);
        vector<int>dp2(high+1,-1);
        
       // int a=sol(0,zero,one,low-1,dp1);
        int ans=0;
        int b=sol(0,zero,one,low,high,dp2);
        
       // cout<<b<<" "<<a<<endl;
        return b;
        
        
    }
};