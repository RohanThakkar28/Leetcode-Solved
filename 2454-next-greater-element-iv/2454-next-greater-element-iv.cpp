class Solution {
public:
    vector<int> secondGreaterElement(vector<int>& nums) {
        int n=nums.size();
        vector<int>arr(n,n);
        stack<int>s;
        for(int i=0;i<n;i++){
            while(!s.empty() && nums[i]>nums[s.top()]){
                arr[s.top()]=i;
                s.pop();
            }
            s.push(i);
        }
        vector<int>ans(n,-1);
        for(int i=0;i<n;i++){
            if(i>0 && nums[i]==nums[i-1]){
                ans[i]=ans[i-1];
                continue;
            }
            int ng=arr[i];
            
            
            ng++;
            
            while(ng<n && nums[ng]<=nums[i]){
                ng=arr[ng];
            }
            if(ng<n){
                ans[i]=nums[ng];
            }
        }
        return ans;
        
        
    }
};