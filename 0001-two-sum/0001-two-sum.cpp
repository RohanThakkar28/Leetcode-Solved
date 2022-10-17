class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int>count;
        int n=nums.size();
        map<int,int>id;
        vector<int>ans;
        if(target%2==0){
            int req=target/2;
            int c=0;
            for(int i=0;i<n;i++){
                if(nums[i]==req){
                    ans.push_back(i);
                    c++;
                }
                if(c==2){
                    break;
                }
            }
            if(ans.size()==2){
                return ans;
            }
            
        }
        ans.clear();
        for(int i=0;i<n;i++){
            if(count[nums[i]]==0){
                count[nums[i]]++;

                id[nums[i]]=i;
            }
        }
        
        for(int i=0;i<n;i++){
            if(count[target-nums[i]]>=1 && (id[target-nums[i]]!=i) ){
                ans.push_back(id[nums[i]]);
                ans.push_back(id[target-nums[i]]);
                break;
            }
        }
        
        return ans;
        
        
    }
};