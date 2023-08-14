class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int,vector<int>>q;
        int n=nums.size();
        for(int i=0;i<n;i++){
            q.push( nums[i]);
            
        }
        int i=1;
        while(i<k){
            q.pop();
            i++;
            
        }
        return q.top();
        
    }
};