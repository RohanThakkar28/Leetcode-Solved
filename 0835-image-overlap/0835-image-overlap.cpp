class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        map<pair<int,int>,int>mp;
        int ans=0;
        int n=img1.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                for(int i1=0;i1<n;i1++){
                    for(int j1=0;j1<n;j1++){
                        if(img1[i][j]==1 && img2[i1][j1]==1){
                            mp[{i1-i,j1-j}]++;
                            ans=max(ans,mp[{i1-i,j1-j}]);
                        }
                    }
                }
            }
        }
        return ans;
        
    }
};