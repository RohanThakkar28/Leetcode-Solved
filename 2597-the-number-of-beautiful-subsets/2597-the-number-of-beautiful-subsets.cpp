class Solution {
public:
    int sol(int i,vector<int>& nums, int k,unordered_map<int,int>&c){
        int n=nums.size();
        if(i==n){
            return 1;
        }
        if(c[(nums[i]-k)]>0){
            int a=sol(i+1,nums,k,c);
            return a;
            
            
        }
        else{
            c[nums[i]]++;
            int a=sol(i+1,nums,k,c);
            c[nums[i]]--;
            int b=sol(i+1,nums,k,c);
            
            return a+b;
        }
    }
    int beautifulSubsets(vector<int>& nums, int k) {
        unordered_map<int,int>c;
        sort(nums.begin(),nums.end());
        return sol(0,nums,k,c)-1;
        
        
    }
};