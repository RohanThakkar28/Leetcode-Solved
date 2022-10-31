class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        int i1=n-1;
        int j1=0;
        bool ye=true;
        bool up=true;
        while((i1!=0 || j1!=m-1)){
            int i=i1;
            int j=j1;
            //cout<<i<<" "<<j<<endl;
            int num=matrix[i][j];
            while(i<n && j<m){
                if(matrix[i][j]!=num){
                    ye=false;
                    break;
                }
                i++;
                j++;
            }
            if(!ye){
                break;
            }
            if(up){
                i1--;
                if(i1<0){
                    i1++;
                    up=false;
                    j1++;
                }
            }
            else{
                j1++;
            }
            
            
        }
        return ye;
        
    }
};