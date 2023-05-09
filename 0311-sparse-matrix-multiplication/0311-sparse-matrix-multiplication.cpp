class Solution {
public:
    vector<vector<int>> multiply(vector<vector<int>>& mat1, vector<vector<int>>& mat2) {
        int n=mat1.size();
        int k1=mat1[0].size();
        
        int m=mat2[0].size();
        vector<vector<int>>ans(n,vector<int>(m,0));
      
        for(int i=0;i<n;i++){
            for(int k=0;k<k1;k++){
                for(int j=0;j<m;j++ ){
                    ans[i][j]+=mat1[i][k]*mat2[k][j];
                }
                
                
                
            }
        }
        return ans;
        
        
        
    }
};