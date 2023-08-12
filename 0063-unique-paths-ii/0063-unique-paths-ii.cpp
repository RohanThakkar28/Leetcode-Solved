class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n=obstacleGrid.size();
        int m=obstacleGrid[0].size();
        vector<vector<int>>ans(n,vector<int>(m,0));
        ans[0][0]=1;
        for(int i=1;i<n;i++){
            if(obstacleGrid[i][0]==1){
                ans[i][0]=0;
                
            }
            else{
                ans[i][0]=ans[i-1][0];
            }
        }
        for(int j=1;j<m;j++){
            if(obstacleGrid[0][j]==1){
                ans[0][j]=0;
                
            }
            else{
                ans[0][j]=ans[0][j-1];
            }
            
        }
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                if(obstacleGrid[i][j]==1){
                    ans[i][j]=0;
                }
                else{
                      ans[i][j]=ans[i-1][j]+ans[i][j-1];
                }
            }
            
        }
        if(obstacleGrid[0][0]==1){
            return 0;
        }
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<m;j++){
        //         cout<<ans[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        return ans[n-1][m-1];
    }
};