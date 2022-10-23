#define ll long long int
class Solution {
public:
    long long makeSimilar(vector<int>& nums, vector<int>& tar) {
        vector<int>odd1;
        vector<int>odd2;
        vector<int>even1;
        vector<int>even2;
        sort(nums.begin(),nums.end());
        
        sort(tar.begin(),tar.end());
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]%2==0){
                even1.push_back(nums[i]);
            }
            else{
                odd1.push_back(nums[i]);
            }
            if(tar[i]%2==0){
                even2.push_back(tar[i]);
            }
            else{
                odd2.push_back(tar[i]);
            }
        }
        vector<int>diff;
        for(int i=0;i<even1.size();i++){
            if(even1[i]-even2[i]!=0){
                diff.push_back(even1[i]-even2[i]);
            
            }
        }
        for(int i=0;i<odd1.size();i++){
            
            if(odd1[i]-odd2[i]!=0){
                diff.push_back(odd1[i]-odd2[i]);
            }
            
        }
        sort(diff.begin(),diff.end());
        ll ans=0;
        for(int i=0;i<diff.size();i++){
            if(diff[i]>0){
                ans+=(ll)diff[i];
            }
        }
        return ans/2;
        
        
        
        
    }
};

/*
6 8 12

-4 2 2

1 2 5
1 4 3





*/