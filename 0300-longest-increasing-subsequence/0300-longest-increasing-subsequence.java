class Solution {
    public int lengthOfLIS(int[] nums) {
        int n=nums.length;
        int[] dp=new int[n];
        dp[0]=nums[0];
        int j=1;
        for(int i=1;i<n;i++){
            if(nums[i]>dp[j-1]){
                dp[j]=nums[i];
                j++;
            }
            else{
                int s=0;
                int e=j-1;
                int p=-1;
                while(s<=e){
                    int m=s+(e-s)/2;
                    if(dp[m]>=nums[i]){
                        p=m;
                        e=m-1;
                    }
                    else{
                        s=m+1;
                    }
                }
                dp[p]=nums[i];
            }
        }
        return j;
     
    }
}