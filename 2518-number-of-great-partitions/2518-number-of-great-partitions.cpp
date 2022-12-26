#define ll long long int
class Solution {
public:
    const int mod=1e9+7;
    

    int countPartitions(vector<int>& nums, int k) {
        int n=nums.size();
        ll sum=0;
        for(int i=0;i<n;i++){
            sum+=(ll)nums[i];
            
        }
        if(n==1){
            return 0;
        }
        if((ll)(2*k)>sum){
            return 0;
        }
        sort(nums.begin(),nums.end());
        vector<vector<int>>dp(n+1,vector<int>(k+1,0));
       
        for(int i=0;i<n;i++){
            dp[i][0]++;
            
        }
        if(nums[0]<=k){

            dp[0][nums[0]]++;
            
        }
        for(int i=1;i<n;i++){
           // cout<<i<<endl;
            for(int j=0;j<=k;j++){
                if(j-nums[i]>=0){
                    dp[i][j]=dp[i-1][j-nums[i]]+dp[i-1][j];
                    dp[i][j]%=mod;
                }
                else{
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
        int nott=0;
        for(int j=1;j<=k-1;j++){
            nott+=dp[n-1][j];
            nott%=mod;
        }
        int ans=1;
        for(int i=0;i<n;i++){
            ans*=2;
            ans%=mod;
        }
        ans-=2;
        ans-=2*nott;
        ans=(ans+mod)%mod;
        return ans;
        return 0;
        
        
        
    }
};