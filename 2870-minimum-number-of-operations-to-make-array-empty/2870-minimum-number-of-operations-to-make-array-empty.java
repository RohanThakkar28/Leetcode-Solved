class Solution {
    public int minOperations(int[] nums) {
        int n=nums.length;
        int maxy=0;
        for(int i=0;i<n;i++){
            maxy=Math.max(nums[i],maxy);
        }
        int[] a=new int[maxy+1];
        for(int i=0;i<=maxy;i++){
            a[i]=0;
        }
        for(int i=0;i<n;i++){
            a[nums[i]]++;
        }
        int ans=0;
        for(int i=1;i<=maxy;i++){
            int cnt=a[i];
            if(cnt==1){
                return -1;
            }
            int miny=100000;
            if(cnt%3==0){
                ans+=cnt/3;
            }
            else if((cnt-2)>=0 && (cnt-2)%3==0){
                ans+=1+(cnt-2)/3;
            }
            else if((cnt-4)>=0 && (cnt-4)%3==0){
                ans+=2+(cnt-4)/3;
            }
            
        }
        return ans;
        
    }
}