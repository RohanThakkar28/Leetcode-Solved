class Solution {
public:
    int sol(int i,int j,vector<vector<int>>&maxi,int d,vector<vector<vector<int>>>&dp){
        int n=maxi.size();
       // cout<<i<<" "<<j<<" "<<d<<endl;
        
        if(d==0 && j==n){
            return 0;
        }
        if(d==0){
            return 1e9;
        }
        if(j==n){
            return 1e9;
        }
        if(dp[i][j][d]!=-1){
            return dp[i][j][d];
        }
        int a=maxi[i][j]+sol(j+1,j+1,maxi,d-1,dp);
        int b=sol(i,j+1,maxi,d,dp);
        return dp[i][j][d]=min(a,b);
        
    }
    
    int minDifficulty(vector<int>& job, int d) {
        int n=job.size();
        if(job.size()<d){
            return -1;
        }
        vector<vector<int>>maxi(n,vector<int>(n,0));
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                int maxy=job[j];
                for(int k=j;k<n;k++){
                    maxy=max(maxy,job[k]);
                    maxi[j][k]=maxy;
                }
            }
        }
        //cout<<maxi[1][4]<<endl;
       // cout<<n<<endl;
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(n,vector<int>(d+1,-1)));
        int ans=sol(0,0,maxi,d,dp);
        return ans;
        
        
    }
};