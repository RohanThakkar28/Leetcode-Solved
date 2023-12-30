class Solution {
    public boolean makeEqual(String[] words) {
        int[] c=new int[26];
        int n=words.length;
        for(int i=0;i<n;i++){
            for(int j=0;j<words[i].length();j++){
               
                
                c[(words[i].charAt(j)-'a')]++;
                
            }
        }
        boolean ye=true;
        for(int i=0;i<26;i++){
            if(c[i]%n!=0){
                ye=false;
            }
        }
        return ye;
    }
}