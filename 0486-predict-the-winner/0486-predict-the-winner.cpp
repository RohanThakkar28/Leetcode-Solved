class Solution {
public:
    int sol(int i,int j,int ch,vector<int>& nums){
        if(i>j){
            return 0;
        }
        if(ch==0){
            int a=nums[i]+sol(i+1,j,1-ch,nums);
            int b=nums[j]+sol(i,j-1,1-ch,nums);
            return max({a,b});
        }
        
        int a=sol(i+1,j,1-ch,nums);
        int b=sol(i,j-1,1-ch,nums);
        return min({a,b});
    }
    bool PredictTheWinner(vector<int>& nums) {
        int n=nums.size();
        int ans=sol(0,n-1,0,nums);
        int sum=0;
        for(auto i:nums){
            sum+=i;
        }
        //cout<<ans<<endl;
        if(ans>=sum-ans){
            return true;
        }
        return false;
        
    }
};