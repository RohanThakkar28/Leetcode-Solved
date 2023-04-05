#define ll long long int
class Solution {
public:
    int minimizeArrayValue(vector<int>& nums) {
        int l=nums[0];
        int cm=-1e9;
        int n=nums.size();
        for(int i=1;i<n;i++){
            cm=max(cm,nums[i]);
        }
        int ans=nums[0];
        int r=cm;
        while(l<=r){
            int mid=l+(r-l)/2;
            bool ye=true;
            ll c=0;
            for(int i=0;i<n;i++){
                if(nums[i]>=mid){
                    if(c<(nums[i]-mid)){
                        ye=false;
                        break;
                    }
                    else{
                        c-=(ll)(nums[i]-mid);
                    }
                }
                else{
                    c+=(ll)(mid-nums[i]);
                }
            }
            if(ye){
                ans=mid;
                r=mid-1;
            }
            else{
                l=mid+1;
            }

        }
        return ans;



        
    }
};