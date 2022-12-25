class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        sort(nums.begin(),nums.end());
        vector<int>ans;
        for(auto i:queries){
            int sum=0;
            int c=0;
            
            for(int j=0;j<nums.size();j++){
                if(sum+nums[j]<=i){
                    c++;
                    sum+=nums[j];
                }
                
                
            }
            ans.push_back(c);
        }
        return ans;
        
    }
};