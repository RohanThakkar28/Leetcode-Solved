class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        int n=nums.size();
        unordered_map<int,int>c;
        for(int i=0;i<n;i++){
            nums[i]%=value;
            nums[i]=(nums[i]+value)%value;
            c[nums[i]]++;
        }
        int l=0;
        int r=n+1;
        int ans=0;
        while(l<=r){
            int m=l+(r-l)/2;
            unordered_map<int,int>tmp=c;
            bool ye=true;
            for(int i=0;i<m;i++){
                if(tmp[i%value]==0){
                    ye=false;
                    break;
                }
                else{
                    tmp[i%value]--;
                }
            }
            if(ye){
                ans=m;
                l=m+1;
                
            }
            else{
                r=m-1;
            }
        }
        return ans;
        
        
    }
};