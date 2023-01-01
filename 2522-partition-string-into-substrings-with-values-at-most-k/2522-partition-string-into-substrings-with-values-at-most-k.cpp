#define ll long long int
class Solution {
public:
    int sol(int i,int j,string &s,int k,vector<vector<int>>&dp){
        
        
        int ans=1e9;
        int n=s.size();
      //  cout<<i<<endl;
        if(i==n){
            return 0;
        }
        string tmp="";
        for(int k1=i;k1<i+j;k1++){
            tmp+=s[k1];
        }
        ll ch=stoll(tmp);
        if(ch>1e9){
            return 1e8;
        }
        if(i+j==n){
            
            
            int kk=stoi(tmp);
            if(kk<=k){
                return 1;
            }
        
            
            return 1e8;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
       
        
        int kk=stoi(tmp);
        if(kk<=k){

          //  cout<<tmp<<" "<<k<<endl;
            int a=sol(i,j+1,s,k,dp);
            int b=1+sol(i+j,1,s,k,dp);
            return dp[i][j]=min(a,b);
        }
        else{
            return dp[i][j]=1e8;
        }
        
    }
    int minimumPartition(string s, int k) {
        //cout<<s.size()<<endl;
        if(s.size()<=10){
            int a=stoi(s);
            if(a<=k){
                return 1;
            }
        }
        vector<vector<int>>dp(s.size(),vector<int>(11,-1));
        int ans=sol(0,1,s,k,dp);
        
        if(ans>=1e8){
            return -1;
        }
        return ans;
    }
};