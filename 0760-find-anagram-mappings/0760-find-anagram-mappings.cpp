class Solution {
public:
    vector<int> anagramMappings(vector<int>& nums1, vector<int>& nums2) {
        map<int,int>c;
        for(int i=0;i<nums2.size();i++){
            c[nums2[i]]=i;
        }
        vector<int>ans;
        for(auto i:nums1){
            ans.push_back(c[i]);
        }
        return ans;
        
    }
};