class Solution {
    public boolean ch(String s1, String s2,int i){
        int j=0;
        int n2=s2.length();
        while(j<n2){
            if(s1.charAt(i)==s2.charAt(j)){
                i++;
                j++;
            }
            else{
                return false;
            }
        }
        return true;
        
    }
    public int strStr(String s1, String s2) {
        int n1=s1.length();
        int n2=s2.length();
        for(int i=0;i<=n1-n2;i++){
            if(s1.charAt(i)==s2.charAt(0)){
                if(ch(s1,s2,i)){
                    return i;
                }
                
                
            }
        }
        return -1;
        
        
        
    }
}