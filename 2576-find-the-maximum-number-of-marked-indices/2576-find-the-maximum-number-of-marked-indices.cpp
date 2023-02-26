class Solution {
public:
    int maxNumOfMarkedIndices(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        multiset<int>s;
        int n=nums.size();
        for(int i=n/2;i<n;i++){
            s.insert(nums[i]);
        }
        int ans=0;
        for(int i=n/2-1;i>=0;i--){
           // cout<<nums[i]<<endl;
            auto id=s.lower_bound(2*nums[i]);
            if(id!=s.end()){
                ans+=2;
                s.erase(id);
            }
        }
        return ans;
        
    }
};