class Solution {
    public int removeAlmostEqualCharacters(String word) {
        int n=word.length();
        int[][] dp=new int[n][2];
        for(int i=0;i<n;i++){
            for(int j=0;j<2;j++){
                dp[i][j]=10000;
            }
        }
        dp[0][0]=0;
        dp[0][1]=1;
        for(int i=1;i<n;i++){
            if(Math.abs(word.charAt(i)-word.charAt(i-1))<=1){
                dp[i][0]=dp[i-1][1];
                dp[i][1]=1+Math.min(dp[i-1][0],dp[i-1][1]);
            }
            else{
                dp[i][0]=Math.min(dp[i-1][0],dp[i-1][1]);
                dp[i][1]=1+Math.min(dp[i-1][0],dp[i-1][1]);
            }
        }
        return Math.min(dp[n-1][0],dp[n-1][1]);
        
    }
}