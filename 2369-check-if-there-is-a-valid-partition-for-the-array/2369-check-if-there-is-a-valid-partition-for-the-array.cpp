class Solution {
public:
    bool ye=false;
    bool sol(int i,vector<int>& nums,vector<bool>&arr,vector<bool>&vis){
        int n=nums.size();
        if(i==n){
            ye=true;
            
        }
        if(i>n){
            return false;
        }
        if(arr[i]==true){
            return true;
        }
        if(vis[i]==true){
            return false;
        }
        vis[i]=true;
        if(i+1<n){
            if(nums[i]==nums[i+1]){
                arr[i]=(false || sol(i+2,nums,arr,vis));
            }
        }
        if(i+2<n){
            if(nums[i]==nums[i+1] && nums[i]==nums[i+2]){
                arr[i]=(false || sol(i+3,nums,arr,vis));
            }
            if(nums[i+2]-nums[i+1]==1 && nums[i+1]-nums[i]==1){
                arr[i]=(false || sol(i+3,nums,arr,vis));
            }
        }
        return arr[i];
    }
    bool validPartition(vector<int>& nums) {
        vector<bool>arr(nums.size(),false);
        vector<bool>vis(nums.size(),false);
        bool ch=sol(0,nums,arr,vis);
        return ye;
    }
};