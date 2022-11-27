
#define ll long long 
class Solution {
public:
    const int mod=1e9+7;
    vector<int>a;
    ll sol(int i,int n,int l,int v1,int v2,vector<vector<vector<vector<ll>>>>&dp){
        //cout<<l<<" "<<i<<endl;
        if(l==5){
            return 1;
        }
        if(i==n){
            return 0;
        }
        if(dp[i][l][v1][v2]!=-1){
            return dp[i][l][v1][v2]%mod;
        }
        
        if(l==0){
            ll a1=sol(i+1,n,l,v1,v2,dp);
            ll a2=sol(i+1,n,l+1,a[i],v2,dp);
            return dp[i][l][v1][v2]=(a1+a2)%mod;
        }
        else if(l==1){
            
            ll a1=sol(i+1,n,l,v1,v2,dp);
            ll a2=sol(i+1,n,l+1,v1,a[i],dp);
            return dp[i][l][v1][v2]=(a1+a2)%mod;
            
        }
        else if(l==2){
            ll a1=sol(i+1,n,l,v1,v2,dp);
            ll a2=sol(i+1,n,l+1,v1,v2,dp);
            return dp[i][l][v1][v2]=(a1+a2)%mod;
            
            
        }
        else if(l==3){
            if(a[i]==v2){

                ll a1=sol(i+1,n,l,v1,v2,dp);
                ll a2=sol(i+1,n,l+1,v1,v2,dp);
                return dp[i][l][v1][v2]=(a1+a2)%mod;
                
            }
            else{

                ll a1=sol(i+1,n,l,v1,v2,dp);
                return dp[i][l][v1][v2]=a1%mod;
            }
        }
        else if(l==4){
            if(a[i]==v1){

                ll a1=sol(i+1,n,l,v1,v2,dp);
                ll a2=sol(i+1,n,l+1,v1,v2,dp);
                return dp[i][l][v1][v2]=(a1+a2)%mod;
            }
            else{

                ll a1=sol(i+1,n,l,v1,v2,dp);
                return dp[i][l][v1][v2]=a1%mod;
            }
        }
        
        return 2;
        
    }
    int countPalindromes(string s) {
        int n=s.size();
        for(int i=0;i<n;i++){
            a.push_back((s[i]-'0'));
        }
        vector<vector<vector<vector<ll>>>>dp(n,vector<vector<vector<ll>>>(5,vector<vector<ll>>(10,vector<ll>(10,-1))));
        int ans=sol(0,s.size(),0,0,0,dp);
        return ans;
    }
};