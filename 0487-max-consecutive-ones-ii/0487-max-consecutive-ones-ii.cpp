class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        vector<pair<int,int>>vec;
        int n=nums.size();
        int i=0;
        while(i<n){
            if(nums[i]==1){
                int l=i;
                int r;
                while(i<n && nums[i]==1){
                    i++;
                }
                r=i-1;
                vec.push_back({l,r});
            }
            i++;
        }
        int ans=1;
        if(vec.size()==0){
            return 1;
        }
        if(vec.size()==1){
            int l=vec[0].first;
            int r=vec[0].second;
            ans=r-l+1;
            if(l>0 || r<n-1){
                ans++;
            }
            return ans;
        }
        for(int i=0;i<vec.size()-1;i++){
            int len1=vec[i].second-vec[i].first+1;
            int len2=vec[i+1].second-vec[i+1].first+1;
            ans=max({ans,len1+1,len2+1});
            if(vec[i+1].first-vec[i].second==2){
                ans=max(ans,len1+len2+1);
            }
            
        }
        return ans;
    }
};