class Solution {
    public int numberOfBeams(String[] bank) {
        int ans=0;
        int prev=-1;
        for(int i=0;i<bank.length;i++){
            String a=bank[i];
            int cnt=0;
            for(int j=0;j<a.length();j++){
                if(a.charAt(j)=='1'){
                    cnt++;
                }
            }
            if(cnt==0){
                continue;
            }
            if(prev==-1){
                prev=cnt;
            }
            else{
                ans+=cnt*prev;
                prev=cnt;
            }
            
        }
        return ans;
        
    }
}