class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int>ans;
        int n=nums.size();
        deque<int>q;
        for(int i=0;i<k;i++){
            while(!q.empty() && nums[i]>nums[q.back()]){
                q.pop_back();
            }
            q.push_back(i);
        }
        ans.push_back(nums[q.front()]);
        for(int i=k;i<n;i++){
            if(q.size()>0 && q.front()==i-k){
                q.pop_front();
            }
            while(!q.empty() && nums[i]>nums[q.back()]){
                q.pop_back();
            }
            q.push_back(i);
            ans.push_back(nums[q.front()]);
        }
        return ans;
    }
};