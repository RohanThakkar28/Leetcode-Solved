class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int l=0;
        int n=nums.size();
        int r=n-1;
        while(l<r){
            int mid=l+(r-l)/2;
            if(nums[mid]==target){
                return mid;
            }
            else if(nums[mid]>target){
                r=mid-1;
            }
            else{
                l=mid+1;
            }
          //  cout<<l<<" "<<r<<endl;
        }
        if(target>nums[l]){
            return l+1;
        }
        else{
            return l;
        }
    }
};