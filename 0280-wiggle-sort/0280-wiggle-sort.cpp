class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans(n);
        sort(nums.begin(),nums.end());
        int k=0;
        for(int i=0;i<(n+1)/2;i++){
            ans[k]=nums[i];
            k+=2;
            
            
        }
        k=1;
        for(int i=(n+1)/2;i<n;i++){
            ans[k]=nums[i];
            k+=2;
        }
        nums=ans;
    }
};