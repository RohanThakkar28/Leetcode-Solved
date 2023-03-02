class Solution {
    public int compress(char[] chars) {
        int n=chars.length;
        int ans=0;
        int c=1;
        int j=0;
        for(int i=1;i<n;i++){
            if(chars[i]==chars[i-1]){
                c++;
            }
            else{
                if(c==1){
                    chars[j++]=chars[i-1];
                    ans++;
                }
                else{
                    
                 
                    chars[j++]=chars[i-1];
                    String s=String.valueOf(c);
                    for(int k=0;k<s.length();k++){
                        chars[j++]=s.charAt(k);
                    }
                    ans+=(1+s.length());
                    c=1;
                }
            }
            
        }
        if(c==1){
                    chars[j++]=chars[n-1];
                    ans++;
                }
                else{
                    
                    //c1.add(chars[n-1]);
                    chars[j++]=chars[n-1];
                    String s=String.valueOf(c);
                    for(int k=0;k<s.length();k++){
                         chars[j++]=s.charAt(k);
                    }
                    ans+=(1+s.length());
                    c=1;
                }
    
        //System.out.println(ans);
        return ans;
        
    }
}