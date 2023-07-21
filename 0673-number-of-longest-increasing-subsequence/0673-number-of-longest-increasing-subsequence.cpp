class Solution {
public:
    
    int findNumberOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,1);
        int maxy=1;
        for(int i=0;i<n;i++){
            for(int j=i-1;j>=0;j--){
                if(nums[i]>nums[j]){
                    dp[i]=max(dp[i],1+dp[j]);
                    maxy=max(maxy,dp[i]);
                }
            }
        }
       // int ans=0;
        //cout<<maxy<<endl;

        vector<int>ans(n,1);
        for(int i=0;i<n;i++){
            if(dp[i]>1){
                int cnt=0;
                for(int j=i-1;j>=0;j--){
                    if(dp[j]==dp[i]-1 && nums[i]>nums[j]){
                        cnt+=ans[j];
                    }
                    
                }
                if(cnt>0){
                    ans[i]*=cnt;
                    
                }
                
            }
        }
        int cnt=0;
        for(int i=0;i<n;i++){
            if(dp[i]==maxy){
                cnt+=ans[i];
            }
        }
        return cnt;
       
        
        
        
    }
};