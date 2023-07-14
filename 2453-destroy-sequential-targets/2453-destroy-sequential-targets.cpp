class Solution {
public:
    int destroyTargets(vector<int>& nums, int space) {
        sort(nums.begin(),nums.end());
        map<int,int>c;
        int maxy=0;
        int n=nums.size();
        int idx;
        for(auto i:nums){
            c[(i%space)]++;
            if(c[(i%space)]>maxy){
                maxy=c[i%space];
                
            }
        }
        int ans=1e9;
        for(int i=0;i<n;i++){
            if(c[nums[i]%space]==maxy){
                ans=min(ans,nums[i]);
            }
        }
        return ans;
        
        
    }
};