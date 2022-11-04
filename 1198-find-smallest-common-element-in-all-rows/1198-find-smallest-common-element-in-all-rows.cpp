class Solution {
public:
    int smallestCommonElement(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        vector<map<int,int>>v(n);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                v[i][mat[i][j]]++;
            }
        }
        int ans=1e9;
        for(int j=0;j<m;j++){
            int num=mat[0][j];
            int c=0;
            for(int i=0;i<n;i++){
                if(v[i][num]>0){
                    c++;
                }
            }
         //   cout<<num<<" "<<c<<" "<<n<<endl;
            if(c==n){
                ans=min(ans,num);
            }
            
        }
        if(ans==1e9){
            ans=-1;
        }
        return ans;
    }
};