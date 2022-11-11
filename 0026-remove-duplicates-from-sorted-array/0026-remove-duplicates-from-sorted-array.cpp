class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        map<int,int>m;
        int n=nums.size();
        int id=0;
        for(int i=0;i<n;i++){
            if(m[nums[i]]==0){
                m[nums[i]]++;
                nums[id]=nums[i];
                id++;
            }
        }
        return id;
        
    }
};