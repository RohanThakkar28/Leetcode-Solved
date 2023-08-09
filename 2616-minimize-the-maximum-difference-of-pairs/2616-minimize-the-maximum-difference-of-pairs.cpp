class Solution {
public:
    
    int minimizeMax(vector<int>& nums, int p) {
        vector<pair<int,pair<int,int>>>v;
        sort(nums.begin(),nums.end());
        int l=0;
        int r=1e9;
        int ans=r;
        int n=nums.size();
        while(l<=r){
            
            int m=l+(r-l)/2;
            int c=0;
            int i=0;
            while(i<n-1){
                if(nums[i+1]-nums[i]<=m){
                    c++;
                    i++;
                }
                i++;
            }
           // cout<<c<<" "<<m<<endl;
            if(c>=p){
                ans=m;
                r=m-1;
            }
            else{
                l=m+1;
            }
            
           
                
            
            
            
        }
        return ans;
        
        
    }
};
/*
1 2 2 2 3 3 4
*/