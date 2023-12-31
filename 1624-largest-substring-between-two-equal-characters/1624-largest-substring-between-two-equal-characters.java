class Solution {
    public int maxLengthBetweenEqualCharacters(String s) {
        int[][] pos=new int[26][2];
        for(int i=0;i<26;i++){
            for(int j=0;j<2;j++){
                pos[i][j]=-1;
            }
        }
        for(int i=0;i<s.length();i++){
            int id=s.charAt(i)-'a';
            if(pos[id][0]==-1){
                pos[id][0]=i;
            }
            else{
                pos[id][1]=i;
            }
        }
        int ans=-1;
        for(int i=0;i<26;i++){
            if(pos[i][1]!=-1){
                ans=Math.max(ans,pos[i][1]-pos[i][0]-1);
            }
        }
        return ans;
        
    }
}