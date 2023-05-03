class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        set<int>c1;
        set<int>c2;
        for(auto i:nums1){
            c1.insert(i);
        }
        for(auto i:nums2){
            c2.insert(i);
        }
        sort(nums1.begin(),nums1.end());
        
        sort(nums2.begin(),nums2.end());
        
        vector<int>v1;
        vector<int>v2;
        vector<vector<int>>v;
        for(int i=0;i<nums1.size();i++){
            if(i!=0 && nums1[i]==nums1[i-1]){
                continue;
            }
            if(c2.find(nums1[i])==c2.end()){
                v1.push_back(nums1[i]);
            }
        }
        for(int i=0;i<nums2.size();i++){
            if(i!=0 && nums2[i]==nums2[i-1]){
                continue;
            }
            if(c1.find(nums2[i])==c1.end()){
                v2.push_back(nums2[i]);
            }
        }
        v.push_back(v1);
        v.push_back(v2);
        return v;
        
        
    }
};