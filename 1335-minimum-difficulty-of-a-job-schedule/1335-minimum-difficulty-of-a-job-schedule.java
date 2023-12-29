class Solution {
    public int sol(int i,int j,int[][] maxi,int d,int[][][] dp){
        int n = maxi.length;

        if (d == 0 && j == n) {
            return 0;
        }
        if (d == 0) {
            return 1_000_000_000;
        }
        if (j == n) {
            return 1_000_000_000;
        }
        if (dp[i][j][d] != -1) {
            return dp[i][j][d];
        }

        int a = maxi[i][j] + sol(j + 1, j + 1, maxi, d - 1, dp);
        int b = sol(i, j + 1, maxi, d, dp);
        dp[i][j][d] = Math.min(a, b);
        return dp[i][j][d];
        
    }
    public int minDifficulty(int[] job, int d) {
        int n=job.length;
        if (n < d) {
            return -1;
        }
        int[][] maxi=new int[n][n];
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                int maxy=job[j];
                for(int k=j;k<n;k++){
                    maxy=Math.max(job[k],maxy);
                    maxi[j][k]=maxy;
                    
                }
            }
        }
        int[][][] dp=new int[n][n][d+1];
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                for(int k=0;k<=d;k++){
                    dp[i][j][k]=-1;
                }
            }
        }
        return sol(0,0,maxi,d,dp);
    }
}