class Solution {
public:
    vector<int> getSubarrayBeauty(vector<int>& nums, int k, int x) {
        int n=nums.size();
        vector<int>a(50,0);
        for(int i=0;i<k;i++){
            
            if(nums[i]+50<50){
                a[nums[i]+50]++;
                
            }
            
        }
        int c=0;
        vector<int>ans(n-k+1,-51);
        for(int i=0;i<50;i++){
            
            c+=a[i];
            //cout<<c<<endl;
            if(c>=x){
                ans[0]=i-50;
                break;
            }
        }
        for(int i=k;i<n;i++){
            //cout<<i<<endl;
            if(nums[i-k]+50<50){

                a[nums[i-k]+50]--;
            }
            if(nums[i]+50<50){
                a[nums[i]+50]++;
                
            }
            //cout<<"hi"<<endl;
            int c=0;
            
            for(int j=0;j<50;j++){
                c+=a[j];
                if(c>=x){
                    ans[i-k+1]=j-50;
                    break;
                }
            }
            
        }
        for(int i=0;i<n-k+1;i++){
            if(ans[i]==-51){
                ans[i]=0;
            }
        }
        return ans;
        
    }
};