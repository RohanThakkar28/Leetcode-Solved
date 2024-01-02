class Solution {
    public List<List<Integer>> findMatrix(int[] nums) {
        List<List<Integer>>ans=new ArrayList<>();
        int n=nums.length;
        int []a=new int[n+1];
        for(int i=0;i<n+1;i++){
            a[i]=0;
        }
        for(int i=0;i<n;i++){
            a[nums[i]]++;
        }
        int cnt=n;
        while(cnt>0){
            List<Integer>tmp=new ArrayList<>();
            for(int i=1;i<=n;i++){
                if(a[i]>0){
                    tmp.add(i);
                    a[i]--;
                    
                    cnt--;
                }
            }
            ans.add(tmp);
        }
        return ans;
        
        
    }
}