class Solution {
public:
    int dp[1000][1000];
    int sol(int i,vector<int>& days, vector<int>& costs,int day){
        int n=days.size();
      ///  cout<<i<<endl;
        if(i>=n){
            return 0;
        }
        if(dp[i][day]!=-1){
            return dp[i][day];
        }
        if(days[i]<=day){
            while(i<n && days[i]<=day){
                i++;
            }
        }
        if(dp[i][day]!=-1){
            return dp[i][day];
        }
        if(i>=n){
            return 0;
        }
        int a=costs[0]+sol(i+1,days,costs,days[i]);
        int b=costs[1]+sol(i+1,days,costs,days[i]+6);
        int c=costs[2]+sol(i+1,days,costs,days[i]+29);
        return dp[i][day]=min(a,min(b,c));
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        memset(dp,-1,sizeof(dp));
        return sol(0,days,costs,0);
    }
};