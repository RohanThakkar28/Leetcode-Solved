class Solution {
public:
    int search(vector<int>& nums, int target) {
        int piv=pivot(nums);
        // cout<<piv<<endl;
        if(target==nums[piv]){
            return piv;
        }
        else if(target<nums[0]){
            //binary search after pivot to end
            int a= bs(nums,piv+1,nums.size()-1,target);
            return a;
        }
        else{

            int a=bs(nums,0,piv-1,target);
            return a;
            //binary search from 0 to before pivot 
        }
        return 9;
        
    }
    int bs(vector<int> &nums,int l,int h,int t){
        while(h>=l){
            int m= (h+l)/2;
            if(nums[m]==t){
                return m;
            }
            else if(t>nums[m]){

                l=m+1;
            }
            else{

                h=m-1;
            }
        }
        return -1;

    }
    int pivot(vector<int>& nums){
        int n=nums.size();
        int l=0;
        int h=n-1;
        while(h>=l){
            
            int m = l + (h-l)/2;
            if(nums[m]>=nums[l] && nums[m]<=nums[h]){
                return h;
            }
            if(nums[m]>=nums[l] && nums[m]>=nums[h]){
                l=m+1;   
                if(nums[l]<nums[m]){
                    return m;
                }
            }
            if(nums[m]<=nums[l] && nums[m]<=nums[h]){
                h=m-1;
                if(nums[h]>nums[m]){
                    return m;
                }
            }
        }
        return h;
    }
};