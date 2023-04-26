class Solution {
public:
    int gcd(int a, int b)
    {
        if (b == 0)
            return a;
        return gcd(b, a % b);
    } 
    int minOperations(vector<int>& nums) {
        int c=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]==1){
                c++;
            }
            
        }
        
        if(c>0){
            return n-c;
        }
        int miny=1e9;
        for(int i=0;i<n;i++){
            int num=nums[i];
            for(int j=i;j>=0;j--){
                for(int k=i;k<n;k++){
                    int g=num;
                    for(int z=j;z<=k;z++){
                        g=gcd(g,nums[z]);
                    }
                    //cout<<j<<" "<<k<<" "<<g<<endl;
                    if(g==1){
                        miny=min(miny,k-j);
                    }
                }
            }
            
        }
        if(miny==1e9){
            return -1;
        }
        return miny+n-1;
    }
};