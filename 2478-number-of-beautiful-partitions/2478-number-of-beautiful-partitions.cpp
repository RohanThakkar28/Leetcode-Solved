class Solution {
public:
    map<int,int>p;
    map<int,int>np;
    set<int>st;
    const int mod=1e9+7;
    int sol(int i,int k1,int k,string & s,int m,vector<vector<int>>&dp){
        //cout<<i<<endl;
        int n=s.size();
        
        
        if(i<=n && k-1==k1){
           // cout<<i<<endl;
            return 1;
        }
        
        if(i>=n){
            return 0;
        }
        if(dp[i][k1]!=-1){
            return dp[i][k1];
        }
        int ans=0;
        if(p[i]>0 && np[i-1]>0){
            //cout<<i<<endl;
            
            ans=(sol(i+m,k1+1,k,s,m,dp)%mod+sol(i+1,k1,k,s,m,dp)%mod)%mod;
            
        }
        else{
            ans=sol(i+1,k1,k,s,m,dp)%mod;
            
        }
        return dp[i][k1]=ans%mod;
    }
    int beautifulPartitions(string s, int k, int minLength) {
        int n=s.size();
        if(n==1){
            return 0;
        }
        for(int i=0;i<n;i++){
            char c=s[i];
            if(c=='2' || c=='3' || c=='5' || c=='7'){
                
                p[i]++;
            }
            else{
                np[i]++;
            }
        }
        
        if(k==1 && p[0]>0 && np[n-1]>0){
            return 1;
        }
        else if(k==1){
            return 0;
        }
        vector<vector<int>>dp(n,vector<int>(k+1,-1));
        int ans=sol(minLength,0,k,s,minLength,dp);
        return ans;
        
    }
};