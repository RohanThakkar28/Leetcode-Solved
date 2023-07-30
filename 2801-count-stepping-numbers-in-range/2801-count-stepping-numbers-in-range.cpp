#define ll long long
class Solution {
public:
    int mod=1e9+7;
    ll sol(int i,string &s,int limit,int prev,vector<vector<vector<vector<ll>>>>&dp,int ini){
        int n=s.size();
        if(i==n){
            if(ini==0){
                return 0;
            }
            return 1;
        }
        if(dp[i][prev][limit][ini]!=-1){
            return dp[i][prev][limit][ini];
        }
        
        ll ans=0;
        if(ini==1){
            if(limit==1){
                if(prev+1<(s[i]-'0')){
                    ans+=(ll)sol(i+1,s,0,prev+1,dp,1)%mod;

                    ans%=mod;
                    
                }
                if(prev+1==(s[i]-'0')){
                    ans+=(ll)sol(i+1,s,1,prev+1,dp,1)%mod;
                    ans%=mod;
                    
                }
                if(prev-1>=0 && prev-1<(s[i]-'0')){
                    ans+=(ll)sol(i+1,s,0,prev-1,dp,1)%mod;
                    ans%=mod;
                    
                }
                if(prev-1>=0 && prev-1==(s[i]-'0')){
                    ans+=(ll)sol(i+1,s,1,prev-1,dp,1)%mod;
                    ans%=mod;
                    
                }
                ans%=mod;
            }
            else{
                if(prev+1<=9){
                    ans+=(ll)sol(i+1,s,0,prev+1,dp,1)%mod;
                    ans%=mod;
                    
                }
                if(prev-1>=0){
                    ans+=(ll)sol(i+1,s,0,prev-1,dp,1)%mod;
                    ans%=mod;
                }
                ans%=mod;
            }
            
            
            
        }
        else{
            if(i==0){
                
                for(int j=1;j<=(s[i]-'0');j++){
                    if(j==s[i]-'0'){
                        ans+=(ll)sol(i+1,s,1,j,dp,1);
                        ans%=mod;
                        continue;
                    }
                    ans+=(ll)sol(i+1,s,0,j,dp,1);
                    ans%=mod;
                }
                ans+=(ll)sol(i+1,s,0,0,dp,0);
                ans%=mod;
                
            }
            else{
                 for(int j=1;j<=9;j++){
                    ans+=(ll)sol(i+1,s,0,j,dp,1)%mod;
                     ans%=mod;
                }
                ans+=(ll)sol(i+1,s,0,0,dp,0)%mod;
                ans%=mod;
                
            }
          
            
        }
        
        return dp[i][prev][limit][ini]=ans%mod;
        
        
    }
    int countSteppingNumbers(string low, string high) {
        int ans1=0;
        int ans2=0;
        vector<vector<vector<vector<ll>>>>dp1(low.size(),vector<vector<vector<ll>>>(10,vector<vector<ll>>(2,vector<ll>(2,-1))));
        vector<vector<vector<vector<ll>>>>dp2(high.size(),vector<vector<vector<ll>>>(10,vector<vector<ll>>(2,vector<ll>(2,-1))));   
        
        ans1=sol(0,low,0,0,dp1,0);
        
        ans2=sol(0,high,0,0,dp2,0);
        bool ye=true;
        for(int i=1;i<low.size();i++){
            if((abs((low[i]-'0')-(low[i-1]-'0'))!=1)){
                ye=false;
            }
        }
        if(ye){

            return ans2-ans1+1;
        }
        return (ans2-ans1+mod)%mod;
        
        
    }
};