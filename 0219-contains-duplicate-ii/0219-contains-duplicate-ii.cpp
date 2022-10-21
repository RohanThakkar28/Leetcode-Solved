class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        map<int,int>c;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(i>k){
                c[nums[i-k-1]]--;
            }
            if(c[nums[i]]>0){
                return true;
            }
            c[nums[i]]++;
        }
        return false;
    }
};