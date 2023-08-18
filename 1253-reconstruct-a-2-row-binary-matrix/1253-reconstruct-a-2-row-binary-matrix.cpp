class Solution {
public:
    vector<vector<int>> reconstructMatrix(int upper, int lower, vector<int>& colsum) {
        int n=colsum.size();
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=colsum[i];
        }
        vector<vector<int>>ans;
        if(sum!=(upper+lower)){
            return ans;
        }
        vector<int>v1(n,0);
        vector<int>v2(n,0);
        for(int i=0;i<n;i++){
            if(colsum[i]==2){
                v1[i]=1;
                v2[i]=1;
                upper--;
                lower--;
            }
        }
        if(upper<0 || lower<0){
            return ans;
        }
        int i=0;
        while(i<n){
            
            if(upper==0){
                break;
            }
            if(colsum[i]==1){
                v1[i]=1;
                upper--;
            }
            i++;
        }
        while(i<n){
            
            if(lower==0){
                break;
            }
            if(colsum[i]==1){
                v2[i]=1;
                lower--;
            }
            i++;
        }
        ans.push_back(v1);
        ans.push_back(v2);
        return ans;
        
    }
};