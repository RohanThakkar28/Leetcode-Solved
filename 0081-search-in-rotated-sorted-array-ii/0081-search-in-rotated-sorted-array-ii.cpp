class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n=nums.size();
        if(nums[0]==target || nums[nums.size()-1]==target){
            return true;
        }
        
        int l=0;
        int r=n-1;
        while(l+1<n && nums[0]==nums[l]){
            l++;
        }
        while(r>=0 && nums[r]==nums[0]){
            r--;
        }
        int s=l;
        int e=r;
        
        int id=-1;
        cout<<l<<" "<<r<<endl;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(nums[mid]<=nums[n-1]){
                if(mid+1<n && nums[mid+1]<nums[mid]){
                    l=mid+1;
                    continue;
                }
                if(mid-1>=0 && nums[mid-1]>nums[mid]){
                    id=mid;
                    break;
                }
                id=mid;
                r=mid-1;
            }
            else{
              
                l=mid+1;
            }
        }
        cout<<id<<endl;
        if(id==-1){
            l=s;
            r=e;
        }
        else{
            if(target>=nums[id] && target<=nums[n-1]){
            l=id;
            r=n-1;
            
            }
            else{
                l=0;
                r=id-1;
            }
        }
        
        
        while(l<=r){
            int mid=l+(r-l)/2;
            if(nums[mid]==target){
                return true;
            }
            else if(nums[mid]>target){
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return false;
        
    }
};