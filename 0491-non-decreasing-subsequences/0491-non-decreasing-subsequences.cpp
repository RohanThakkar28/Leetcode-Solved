class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>tmp;
        for(int i=0;i<nums.size();i++){
            int len=tmp.size();
            for(int j=0;j<len;j++){
                if(tmp[j][tmp[j].size()-1]<=nums[i]){
                    auto vec=tmp[j];
                    vec.push_back(nums[i]);
                    tmp.push_back(vec);
                    
                }
            }
            vector<int>tt;
            tt.push_back(nums[i]);
            tmp.push_back(tt);
        }
        set<vector<int>>an;
        for(auto v:tmp){
            if(v.size()>=2){
                an.insert(v);
            }
        }
        vector<vector<int>>ans;
        auto it=an.begin();
        while(it!=an.end()){
            ans.push_back(*it);
            it++;
        }
        return ans;
        
    }
};