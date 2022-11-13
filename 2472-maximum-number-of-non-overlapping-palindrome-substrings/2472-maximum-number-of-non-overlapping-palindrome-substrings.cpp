class Solution {
public:
    int sol(int i,vector<vector<bool>>&dp,int len,int k,int n,vector<int>&d){
       // cout<<i<<endl;
        if(i==n){
            return 0;
        }
        if(d[i]!=-1){
            return d[i];
        }
        int a=0;
        for(int j=i+k-1;j<n;j++){
            if(dp[i][j]){
             //   cout<<j<<endl;
                int b=1+sol(j+1,dp,len,k,n,d);
                a=max(a,b);
            }
        }
        int c=sol(i+1,dp,len,k,n,d);
        return d[i]=max(a,c);
        
    }
    int maxPalindromes(string s, int k) {
        int n=s.size();
        vector<vector<bool>>dp(n,vector<bool>(n,false));
        for(int i=0;i<n;i++){
            dp[i][i]=true;
            int l=i-1;
            int r=i+1;
            while(l>=0 && r<n){
                if(s[l]==s[r]){
                    dp[l][r]=true;
                }
                else{
                    break;
                }
                l--;
                r++;
            }
        }
        for(int i=0;i<n;i++){
            int l=i;
            int r=i+1;
            while(l>=0 && r<n){
                if(s[l]==s[r]){
                    dp[l][r]=true;
                }
                else{
                    break;
                }
                l--;
                r++;
            }
            
        }
        vector<int>d(n,-1);
        int ans=sol(0,dp,0,k,n,d);
        return ans;
        
    }
};