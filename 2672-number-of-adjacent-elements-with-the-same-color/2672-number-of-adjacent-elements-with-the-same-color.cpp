class Solution {
public:
    vector<int> colorTheArray(int n, vector<vector<int>>& queries) {
        vector<int>a(n,0);
        int curr=0;
        vector<int>ans;
        for(auto v:queries){
            int c=v[1];
            int id=v[0];
            if(a[id]==0){
                if(id-1>=0 && c==a[id-1]){
                    curr++;
                }
                if(id+1<n && a[id+1]==c){
                    curr++;
                }
                ans.push_back(curr);
                a[id]=c;
            }
            else{
                if(id-1>=0 && a[id]==a[id-1]){
                    curr--;
                }
                if(id+1<n && a[id+1]==a[id]){
                    curr--;
                }
                if(id-1>=0 && c==a[id-1]){
                    curr++;
                }
                if(id+1<n && a[id+1]==c){
                    curr++;
                }
                ans.push_back(curr);
                a[id]=c;
                
                
                
            }
        }
        return ans;
    }
};