class Solution {
    public String smallestEquivalentString(String s1, String s2, String baseStr) {
        int[] ch=new int[26];
        for(int i=0;i<26;i++){
            ch[i]=i;
        }
        for(int j=0;j<s1.length();j++){
            
            
            for(int i=0;i<s1.length();i++){
                if(ch[s1.charAt(i)-'a']<ch[s2.charAt(i)-'a']){
                    ch[s2.charAt(i)-'a']=ch[s1.charAt(i)-'a'];
                }
                else{
                    ch[s1.charAt(i)-'a']=ch[s2.charAt(i)-'a'];
                }
            }
        }
        String ans="";
        for(int i=0;i<baseStr.length();i++){
            ans+=(char)((ch[baseStr.charAt(i)-'a'])+'a');
        }
        return ans;
    }
}