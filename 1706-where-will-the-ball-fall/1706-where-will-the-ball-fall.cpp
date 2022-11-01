class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<int>ans;
        for(int j=0;j<m;j++){
            bool ye=true;
            //int ans=-1;
            int i1=0;
            int j1=j;
            for(int i=0;i<n;i++){
                if(grid[i1][j1]==1){
                    if(j1==m-1){
                        ye=false;
                        break;
                    }
                    if(j1<m && grid[i1][j1+1]==-1){
                        ye=false;
                        break;
                    }
                    
                    j1++;
                    i1++;
                }
                else{
                    if(j1==0){
                        ye=false;
                        break;
                    }
                    if(grid[i1][j1-1]==1){
                        ye=false;
                        break;
                    }
                    i1++;
                    j1--;
                }
            }
            if(ye){
                ans.push_back(j1);
            }
            else{
                ans.push_back(-1);
            }
            
        }
        return ans;
        
    }
};