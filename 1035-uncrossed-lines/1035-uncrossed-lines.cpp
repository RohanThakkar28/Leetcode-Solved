class Solution {
public:
    int sol(int i,int j,vector<int>& nums1, vector<int>& nums2,int n,int m,vector<vector<int>>&dp){
        
      //  cout<<i<<" "<<j<<endl;
        if(i==-1 || j==-1){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int a=0;
        int b=0;
        if(nums1[i]==nums2[j]){
            a=1+sol(i-1,j-1,nums1,nums2,n,m,dp);
            
        }
        b=max(sol(i-1,j,nums1,nums2,n,m,dp),sol(i,j-1,nums1,nums2,n,m,dp));
        return dp[i][j]=max({a,b});
    }
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m=nums2.size();
        
        vector<vector<int>>dp(n,vector<int>(m,-1));
        int ans=sol(n-1,m-1,nums1,nums2,n,m,dp);
        return ans;
        
    }
};