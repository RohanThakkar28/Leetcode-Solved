class Solution {
    public int maximumLength(String s) {
        int ans=-1;
        int l=1;
        int r=50;
        while(l<=r){
            int m=l+(r-l)/2;
            boolean ye=false;
            for(int i=0;i<26;i++){
                int cnt=0;
                
                for(int j=0;j<s.length();j++){
                    int st=j;
                    int c=0;
                    if(j+m-1>=s.length()){
                        break;
                    }
                    for(int k=j;k<=j+m-1;k++){
                        if((s.charAt(k)-'a')==i){
                            c++;
                        }
                    }
                   // System.out.println(c);
                    
                    if(c==m){
                        cnt++;
                    }
                
                }
                if(cnt>=3){
                    ye=true;
                    break;
                }
            }
          //  System.out.println(m+" "+ye);
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
}