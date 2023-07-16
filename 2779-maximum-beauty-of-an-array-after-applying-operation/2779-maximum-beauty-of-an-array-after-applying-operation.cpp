class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        int ans=1;
        int n=nums.size();

        int l=1;
        int r=n;
        sort(nums.begin(),nums.end());
        while(l<=r){
            int m=l+(r-l)/2;
            bool ye=false;
            for(int i=0;i<=n-m;i++){
                if(nums[i]+k>=nums[m+i-1]-k){
                    ye=true;
                    break;
                }
                
                
            }
            if(ye){
                ans=m;
                l=m+1;
            }
            else{
                r=m-1;
            }
            
        }
        return ans;
        
    }
};