class Solution {
    public int findContentChildren(int[] g, int[] s) {
        Arrays.sort(g);
        Arrays.sort(s);
        int i=0;
        int j=0;
        int n=g.length;
        int m=s.length;
        int ans=0;
        while(i<n && j<m){
            if(s[j]>=g[i]){
                i++;
                j++;
                ans++;
            }
            else{
                j++;
            }
        }
        return ans;
        
    }
}