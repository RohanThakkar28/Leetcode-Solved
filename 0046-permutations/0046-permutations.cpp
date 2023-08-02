class Solution {
public:
    vector<vector<int>>ans;
    void perm(int i,int n,vector<int>&temp,vector<int>& nums){
        if(i==n){
            ans.push_back(temp);
            return;
        }
        map<int,int>c;
        for(int j=0;j<temp.size();j++){
            c[temp[j]]++;
        }
        for(int j=0;j<nums.size();j++){
            if(c[nums[j]]==0){
                temp.push_back(nums[j]);
                perm(i+1,n,temp,nums);
                temp.pop_back();
            }
        }
        
    }
    vector<vector<int>> permute(vector<int>& nums) {
        int n=nums.size();
        vector<int>temp;
        perm(0,n,temp,nums);
        return ans;
        
    }
};