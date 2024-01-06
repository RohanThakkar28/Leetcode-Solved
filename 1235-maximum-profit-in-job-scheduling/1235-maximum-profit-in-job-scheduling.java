class Solution {
    int sol(int i,int[] startTime, int[] endTime, int[] profit,int[] dp){
        int n=startTime.length;
        if(i==n){
            return 0;
        }
        int l=i+1;
        int r=n-1;
        int t=n;
        if(dp[i]!=-1){
            return dp[i];
        }
        while(l<=r){
            int m=l+(r-l)/2;
            if(startTime[m]>=endTime[i]){
                t=m;
                r=m-1;
            }
            else{
                l=m+1;
            }
        }
        int take=profit[i]+sol(t,startTime,endTime,profit,dp);
        int nottake=sol(i+1,startTime,endTime,profit,dp);
        return dp[i]=Math.max(take,nottake);

        
    }
    class Triple implements Comparable<Triple> {
    int array1Value;
    int array2Value;
    int array3Value;

    public Triple(int array1Value, int array2Value, int array3Value) {
        this.array1Value = array1Value;
        this.array2Value = array2Value;
        this.array3Value = array3Value;
    }

    @Override
    public int compareTo(Triple other) {
        return Integer.compare(this.array1Value, other.array1Value);
    }
}

    public int jobScheduling(int[] startTime, int[] endTime, int[] profit) {
        int n=startTime.length;
        int[] dp=new int[n];
        for(int i=0;i<n;i++){
            dp[i]=-1;
        }
         Triple[] triples = new Triple[startTime.length];
        for (int i = 0; i < startTime.length; i++) {
            triples[i] = new Triple(startTime[i], endTime[i], profit[i]);
        }

        // Sort the array of Triple objects based on array1Value
        Arrays.sort(triples);

        // Extract the sorted values back to the original arrays
        for (int i = 0; i < triples.length; i++) {
            startTime[i] = triples[i].array1Value;
            endTime[i] = triples[i].array2Value;
            profit[i] = triples[i].array3Value;
        }

        int ans=sol(0,startTime,endTime,profit,dp);
        return ans;
        
    }
}