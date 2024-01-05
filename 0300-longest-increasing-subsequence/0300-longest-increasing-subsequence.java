class Solution {
    public int lengthOfLIS(int[] nums) {
        int n=nums.length;
        int[] dp=new int[n];
        for(int i=0;i<n;i++){
            dp[i]=1;
        }
        int ans=1;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(nums[j]>nums[i]){
                    dp[j]=Math.max(dp[j],1+dp[i]);
                    ans=Math.max(ans,dp[j]);
                }
            }
        }
        return ans;
    }
}