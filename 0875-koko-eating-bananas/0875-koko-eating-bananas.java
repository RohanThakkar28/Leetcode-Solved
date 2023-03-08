class Solution {
    public int minEatingSpeed(int[] piles, int h) {
        int l=1;
        int r=(int)1e9;
        int ans=r;
        while(l<=r){
            int m=l+(r-l)/2;
            long c=0;
            for(int i=0;i<piles.length;i++){
                if(piles[i]%m==0){
                    c+=(long)(piles[i]/m);
                }
                else{
                    c+=(long)(piles[i]/m+1);
                }
            }
            if(c<=h){
                ans=m;
                r=m-1;
            }
            else{
                l=m+1;
            }
        }
        return ans;
    }
}